# Copyright (C) Yichun Zhang (agentzh)
# Copyright (C) Guanlan Dai

package Test::Resty;

use Test::Base -Base;
use File::Temp qw( tempfile );
use Cwd qw( cwd );
use IPC::Run ();

our @EXPORT = qw( run_tests blocks plan );

our $UseValgrind = $ENV{TEST_RESTY_USE_VALGRIND};

$ENV{LUA_PATH} = cwd . "/../lua-resty-core/lib/?.lua;;";

#warn $ENV{LUA_PATH};

sub write_user_files ($);

sub run_tests () {
    for my $block (Test::Base::blocks()) {
        run_test($block);
    }
}

sub bail_out (@) {
    Test::More::BAIL_OUT(@_);
}

sub parse_cmd ($) {
    my $cmd = shift;
    my @cmd;
    while (1) {
        if ($cmd =~ /\G\s*"(.*?)"/gmsc) {
            push @cmd, $1;

        } elsif ($cmd =~ /\G\s*'(.*?)'/gmsc) {
            push @cmd, $1;

        } elsif ($cmd =~ /\G\s*(\S+)/gmsc) {
            push @cmd, $1;

        } else {
            last;
        }
    }
    return @cmd;
}

sub run_test ($) {
    my $block = shift;
    my $name = $block->name;

    my $timeout = $block->timeout() || 10;
    my $opts = $block->opts // '';
    my $args = $block->args;

    my $cmd = "./bin/resty";

    if ($UseValgrind) {
        my $val_opts = " --num-callers=100 -q --gen-suppressions=all";

        my $sup_file = 'valgrind.suppress';
        if (-f $sup_file) {
            $val_opts .= " --suppressions=$sup_file";
        }

        my $extra_opts = "--valgrind '--valgrind-opts=$val_opts'";
        $opts .= " $extra_opts";

        warn "$name\n";
    }

    $cmd .= " $opts";

    my $luafile;
    if (defined $block->src) {
        my ($out, $luafile) = tempfile("testXXXXXX",
                                        SUFFIX => '.lua',
                                        TMPDIR => 1,
                                        UNLINK => 1);
        print $out ($block->src);
        close $out;
        $cmd .= " $luafile"
    }

    my $binfile;
    if (defined $block->mock_nginx) {
        my ($out, $binfile) = tempfile("testXXXXXX",
                                        SUFFIX => '',
                                        TMPDIR => 1,
                                        UNLINK => 1);
        print $out ($block->mock_nginx);
        close $out;
        chmod 0755, $binfile;
        $cmd .= " --nginx $binfile"
    }

    if (defined $args) {
        $cmd .= " $args";
    }

    #warn "CMD: $cmd\n";

    my @cmd = parse_cmd($cmd);

    write_user_files($block);

    my ($out, $err);

    eval {
        IPC::Run::run(\@cmd, \undef, \$out, \$err,
                      IPC::Run::timeout($timeout));
    };
    if ($@) {
        # timed out
        if ($@ =~ /timeout/) {
            if (!defined $block->expect_timeout) {
                fail("$name: resty process timed out");
            }
        } else {
            fail("$name: failed to run command [$cmd]: $@");
        }
    }

    my $ret = 0;
    if ($?) {
        $ret = ($? >> 8);
        if ($ret == 0) {
            $ret = $?;
        }
    }

    if (defined $luafile) {
        unlink $luafile;
    }

    if (defined $block->out) {
        is $out, $block->out, "$name - stdout eq okay";
    }

    my $regex;
    if (defined $block->out_like) {
        $regex = $block->out_like;
        if (!ref $regex) {
            $regex = qr/$regex/ms;
        }
        like $out, $regex, "$name - stdout like okay";

    } elsif (defined $block->out_not_like) {
        $regex = $block->out_not_like;
        if (!ref $regex) {
            $regex = qr/$regex/ms;
        }
        unlike $out, $regex, "$name - stdout unlike okay";
    }

    if (defined $block->err) {
        is $err, $block->err, "$name - stderr eq okay";
    }

    $regex = $block->err_like;
    if (defined $regex) {
        if (!ref $regex) {
            $regex = qr/$regex/ms;
        }
        like $err, $regex, "$name - stderr like okay";
    }

    my $exp_ret = $block->ret;
    if (!defined $exp_ret) {
        $exp_ret = 0;

    } elsif ($UseValgrind) {
        $ret &= 0x3;
    }
    is $ret, $exp_ret, "$name - exit code okay";
}

sub write_user_files ($) {
    my $block = shift;

    my $tmpdir = "./t/tmp";
    if (!-d $tmpdir) {
        mkdir $tmpdir or die "cannot mkdir $tmpdir: $!\n";
    }

    my $name = $block->name;

    my $files = $block->user_files;
    if ($files) {
        if (!ref $files) {
            my $raw = $files;

            open my $in, '<', \$raw;

            $files = [];
            my ($fname, $body, $date);
            while (<$in>) {
                if (/>>> (\S+)(?:\s+(.+))?/) {
                    if ($fname) {
                        push @$files, [$fname, $body, $date];
                    }

                    $fname = $1;
                    $date = $2;
                    undef $body;
                } else {
                    $body .= $_;
                }
            }

            if ($fname) {
                push @$files, [$fname, $body, $date];
            }

        } elsif (ref $files ne 'ARRAY') {
            bail_out "$name - wrong value type: ", ref $files,
                     ", only scalar or ARRAY are accepted";
        }

        for my $file (@$files) {
            my ($fname, $body, $date) = @$file;
            #warn "write file $fname with content [$body]\n";

            if (!defined $body) {
                $body = '';
            }

            my $path;
            if ($fname !~ m{^/}) {
                $path = "$tmpdir/$fname";

            } else {
                $path = $fname;
            }

            if ($path =~ /(.*)\//) {
                my $dir = $1;
                if (! -d $dir) {
                    make_path($dir)
                        or bail_out "$name - Cannot create directory ", $dir;
                }
            }

            if (-f $path) {
                unlink $path or die "$name - Cannot remove file $path: $!\n";
            }

            open my $out, ">$path" or
                bail_out "$name - Cannot open $path for writing: $!\n";
            binmode $out;
            #warn "write file $path with data len ", length $body;
            print $out $body;
            close $out;

            if ($date) {
                my $cmd = "TZ=GMT touch -t '$date' $path";
                system($cmd) == 0 or
                    bail_out "Failed to run shell command: $cmd\n";
            }
        }
    }
}

1;
# vi: et
