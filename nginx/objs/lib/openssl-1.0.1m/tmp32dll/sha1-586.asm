TITLE	sha1-586.asm
IF @Version LT 800
ECHO MASM version 8.00 or later is strongly recommended.
ENDIF
.686
.XMM
IF @Version LT 800
XMMWORD STRUCT 16
DQ	2 dup (?)
XMMWORD	ENDS
ENDIF

.MODEL	FLAT
OPTION	DOTNAME
IF @Version LT 800
.text$	SEGMENT PAGE 'CODE'
ELSE
.text$	SEGMENT ALIGN(64) 'CODE'
ENDIF
;EXTERN	_OPENSSL_ia32cap_P:NEAR
ALIGN	16
_sha1_block_data_order	PROC PUBLIC
$L_sha1_block_data_order_begin::
	push	ebp
	push	ebx
	push	esi
	push	edi
	call	$L000pic_point
$L000pic_point:
	pop	ebp
	lea	esi,DWORD PTR _OPENSSL_ia32cap_P
	lea	ebp,DWORD PTR ($LK_XX_XX-$L000pic_point)[ebp]
	mov	eax,DWORD PTR [esi]
	mov	edx,DWORD PTR 4[esi]
	test	edx,512
	jz	$L001x86
	test	eax,16777216
	jz	$L001x86
	jmp	$Lssse3_shortcut
ALIGN	16
$L001x86:
	mov	ebp,DWORD PTR 20[esp]
	mov	esi,DWORD PTR 24[esp]
	mov	eax,DWORD PTR 28[esp]
	sub	esp,76
	shl	eax,6
	add	eax,esi
	mov	DWORD PTR 104[esp],eax
	mov	edi,DWORD PTR 16[ebp]
	jmp	$L002loop
ALIGN	16
$L002loop:
	mov	eax,DWORD PTR [esi]
	mov	ebx,DWORD PTR 4[esi]
	mov	ecx,DWORD PTR 8[esi]
	mov	edx,DWORD PTR 12[esi]
	bswap	eax
	bswap	ebx
	bswap	ecx
	bswap	edx
	mov	DWORD PTR [esp],eax
	mov	DWORD PTR 4[esp],ebx
	mov	DWORD PTR 8[esp],ecx
	mov	DWORD PTR 12[esp],edx
	mov	eax,DWORD PTR 16[esi]
	mov	ebx,DWORD PTR 20[esi]
	mov	ecx,DWORD PTR 24[esi]
	mov	edx,DWORD PTR 28[esi]
	bswap	eax
	bswap	ebx
	bswap	ecx
	bswap	edx
	mov	DWORD PTR 16[esp],eax
	mov	DWORD PTR 20[esp],ebx
	mov	DWORD PTR 24[esp],ecx
	mov	DWORD PTR 28[esp],edx
	mov	eax,DWORD PTR 32[esi]
	mov	ebx,DWORD PTR 36[esi]
	mov	ecx,DWORD PTR 40[esi]
	mov	edx,DWORD PTR 44[esi]
	bswap	eax
	bswap	ebx
	bswap	ecx
	bswap	edx
	mov	DWORD PTR 32[esp],eax
	mov	DWORD PTR 36[esp],ebx
	mov	DWORD PTR 40[esp],ecx
	mov	DWORD PTR 44[esp],edx
	mov	eax,DWORD PTR 48[esi]
	mov	ebx,DWORD PTR 52[esi]
	mov	ecx,DWORD PTR 56[esi]
	mov	edx,DWORD PTR 60[esi]
	bswap	eax
	bswap	ebx
	bswap	ecx
	bswap	edx
	mov	DWORD PTR 48[esp],eax
	mov	DWORD PTR 52[esp],ebx
	mov	DWORD PTR 56[esp],ecx
	mov	DWORD PTR 60[esp],edx
	mov	DWORD PTR 100[esp],esi
	mov	eax,DWORD PTR [ebp]
	mov	ebx,DWORD PTR 4[ebp]
	mov	ecx,DWORD PTR 8[ebp]
	mov	edx,DWORD PTR 12[ebp]
	; 00_15 0
	mov	esi,ecx
	mov	ebp,eax
	rol	ebp,5
	xor	esi,edx
	add	ebp,edi
	mov	edi,DWORD PTR [esp]
	and	esi,ebx
	ror	ebx,2
	xor	esi,edx
	lea	ebp,DWORD PTR 1518500249[edi*1+ebp]
	add	ebp,esi
	; 00_15 1
	mov	edi,ebx
	mov	esi,ebp
	rol	ebp,5
	xor	edi,ecx
	add	ebp,edx
	mov	edx,DWORD PTR 4[esp]
	and	edi,eax
	ror	eax,2
	xor	edi,ecx
	lea	ebp,DWORD PTR 1518500249[edx*1+ebp]
	add	ebp,edi
	; 00_15 2
	mov	edx,eax
	mov	edi,ebp
	rol	ebp,5
	xor	edx,ebx
	add	ebp,ecx
	mov	ecx,DWORD PTR 8[esp]
	and	edx,esi
	ror	esi,2
	xor	edx,ebx
	lea	ebp,DWORD PTR 1518500249[ecx*1+ebp]
	add	ebp,edx
	; 00_15 3
	mov	ecx,esi
	mov	edx,ebp
	rol	ebp,5
	xor	ecx,eax
	add	ebp,ebx
	mov	ebx,DWORD PTR 12[esp]
	and	ecx,edi
	ror	edi,2
	xor	ecx,eax
	lea	ebp,DWORD PTR 1518500249[ebx*1+ebp]
	add	ebp,ecx
	; 00_15 4
	mov	ebx,edi
	mov	ecx,ebp
	rol	ebp,5
	xor	ebx,esi
	add	ebp,eax
	mov	eax,DWORD PTR 16[esp]
	and	ebx,edx
	ror	edx,2
	xor	ebx,esi
	lea	ebp,DWORD PTR 1518500249[eax*1+ebp]
	add	ebp,ebx
	; 00_15 5
	mov	eax,edx
	mov	ebx,ebp
	rol	ebp,5
	xor	eax,edi
	add	ebp,esi
	mov	esi,DWORD PTR 20[esp]
	and	eax,ecx
	ror	ecx,2
	xor	eax,edi
	lea	ebp,DWORD PTR 1518500249[esi*1+ebp]
	add	ebp,eax
	; 00_15 6
	mov	esi,ecx
	mov	eax,ebp
	rol	ebp,5
	xor	esi,edx
	add	ebp,edi
	mov	edi,DWORD PTR 24[esp]
	and	esi,ebx
	ror	ebx,2
	xor	esi,edx
	lea	ebp,DWORD PTR 1518500249[edi*1+ebp]
	add	ebp,esi
	; 00_15 7
	mov	edi,ebx
	mov	esi,ebp
	rol	ebp,5
	xor	edi,ecx
	add	ebp,edx
	mov	edx,DWORD PTR 28[esp]
	and	edi,eax
	ror	eax,2
	xor	edi,ecx
	lea	ebp,DWORD PTR 1518500249[edx*1+ebp]
	add	ebp,edi
	; 00_15 8
	mov	edx,eax
	mov	edi,ebp
	rol	ebp,5
	xor	edx,ebx
	add	ebp,ecx
	mov	ecx,DWORD PTR 32[esp]
	and	edx,esi
	ror	esi,2
	xor	edx,ebx
	lea	ebp,DWORD PTR 1518500249[ecx*1+ebp]
	add	ebp,edx
	; 00_15 9
	mov	ecx,esi
	mov	edx,ebp
	rol	ebp,5
	xor	ecx,eax
	add	ebp,ebx
	mov	ebx,DWORD PTR 36[esp]
	and	ecx,edi
	ror	edi,2
	xor	ecx,eax
	lea	ebp,DWORD PTR 1518500249[ebx*1+ebp]
	add	ebp,ecx
	; 00_15 10
	mov	ebx,edi
	mov	ecx,ebp
	rol	ebp,5
	xor	ebx,esi
	add	ebp,eax
	mov	eax,DWORD PTR 40[esp]
	and	ebx,edx
	ror	edx,2
	xor	ebx,esi
	lea	ebp,DWORD PTR 1518500249[eax*1+ebp]
	add	ebp,ebx
	; 00_15 11
	mov	eax,edx
	mov	ebx,ebp
	rol	ebp,5
	xor	eax,edi
	add	ebp,esi
	mov	esi,DWORD PTR 44[esp]
	and	eax,ecx
	ror	ecx,2
	xor	eax,edi
	lea	ebp,DWORD PTR 1518500249[esi*1+ebp]
	add	ebp,eax
	; 00_15 12
	mov	esi,ecx
	mov	eax,ebp
	rol	ebp,5
	xor	esi,edx
	add	ebp,edi
	mov	edi,DWORD PTR 48[esp]
	and	esi,ebx
	ror	ebx,2
	xor	esi,edx
	lea	ebp,DWORD PTR 1518500249[edi*1+ebp]
	add	ebp,esi
	; 00_15 13
	mov	edi,ebx
	mov	esi,ebp
	rol	ebp,5
	xor	edi,ecx
	add	ebp,edx
	mov	edx,DWORD PTR 52[esp]
	and	edi,eax
	ror	eax,2
	xor	edi,ecx
	lea	ebp,DWORD PTR 1518500249[edx*1+ebp]
	add	ebp,edi
	; 00_15 14
	mov	edx,eax
	mov	edi,ebp
	rol	ebp,5
	xor	edx,ebx
	add	ebp,ecx
	mov	ecx,DWORD PTR 56[esp]
	and	edx,esi
	ror	esi,2
	xor	edx,ebx
	lea	ebp,DWORD PTR 1518500249[ecx*1+ebp]
	add	ebp,edx
	; 00_15 15
	mov	ecx,esi
	mov	edx,ebp
	rol	ebp,5
	xor	ecx,eax
	add	ebp,ebx
	mov	ebx,DWORD PTR 60[esp]
	and	ecx,edi
	ror	edi,2
	xor	ecx,eax
	lea	ebp,DWORD PTR 1518500249[ebx*1+ebp]
	mov	ebx,DWORD PTR [esp]
	add	ecx,ebp
	; 16_19 16
	mov	ebp,edi
	xor	ebx,DWORD PTR 8[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 32[esp]
	and	ebp,edx
	xor	ebx,DWORD PTR 52[esp]
	rol	ebx,1
	xor	ebp,esi
	add	eax,ebp
	mov	ebp,ecx
	ror	edx,2
	mov	DWORD PTR [esp],ebx
	rol	ebp,5
	lea	ebx,DWORD PTR 1518500249[eax*1+ebx]
	mov	eax,DWORD PTR 4[esp]
	add	ebx,ebp
	; 16_19 17
	mov	ebp,edx
	xor	eax,DWORD PTR 12[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 36[esp]
	and	ebp,ecx
	xor	eax,DWORD PTR 56[esp]
	rol	eax,1
	xor	ebp,edi
	add	esi,ebp
	mov	ebp,ebx
	ror	ecx,2
	mov	DWORD PTR 4[esp],eax
	rol	ebp,5
	lea	eax,DWORD PTR 1518500249[esi*1+eax]
	mov	esi,DWORD PTR 8[esp]
	add	eax,ebp
	; 16_19 18
	mov	ebp,ecx
	xor	esi,DWORD PTR 16[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 40[esp]
	and	ebp,ebx
	xor	esi,DWORD PTR 60[esp]
	rol	esi,1
	xor	ebp,edx
	add	edi,ebp
	mov	ebp,eax
	ror	ebx,2
	mov	DWORD PTR 8[esp],esi
	rol	ebp,5
	lea	esi,DWORD PTR 1518500249[edi*1+esi]
	mov	edi,DWORD PTR 12[esp]
	add	esi,ebp
	; 16_19 19
	mov	ebp,ebx
	xor	edi,DWORD PTR 20[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 44[esp]
	and	ebp,eax
	xor	edi,DWORD PTR [esp]
	rol	edi,1
	xor	ebp,ecx
	add	edx,ebp
	mov	ebp,esi
	ror	eax,2
	mov	DWORD PTR 12[esp],edi
	rol	ebp,5
	lea	edi,DWORD PTR 1518500249[edx*1+edi]
	mov	edx,DWORD PTR 16[esp]
	add	edi,ebp
	; 20_39 20
	mov	ebp,esi
	xor	edx,DWORD PTR 24[esp]
	xor	ebp,eax
	xor	edx,DWORD PTR 48[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 4[esp]
	rol	edx,1
	add	ecx,ebp
	ror	esi,2
	mov	ebp,edi
	rol	ebp,5
	mov	DWORD PTR 16[esp],edx
	lea	edx,DWORD PTR 1859775393[ecx*1+edx]
	mov	ecx,DWORD PTR 20[esp]
	add	edx,ebp
	; 20_39 21
	mov	ebp,edi
	xor	ecx,DWORD PTR 28[esp]
	xor	ebp,esi
	xor	ecx,DWORD PTR 52[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 8[esp]
	rol	ecx,1
	add	ebx,ebp
	ror	edi,2
	mov	ebp,edx
	rol	ebp,5
	mov	DWORD PTR 20[esp],ecx
	lea	ecx,DWORD PTR 1859775393[ebx*1+ecx]
	mov	ebx,DWORD PTR 24[esp]
	add	ecx,ebp
	; 20_39 22
	mov	ebp,edx
	xor	ebx,DWORD PTR 32[esp]
	xor	ebp,edi
	xor	ebx,DWORD PTR 56[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 12[esp]
	rol	ebx,1
	add	eax,ebp
	ror	edx,2
	mov	ebp,ecx
	rol	ebp,5
	mov	DWORD PTR 24[esp],ebx
	lea	ebx,DWORD PTR 1859775393[eax*1+ebx]
	mov	eax,DWORD PTR 28[esp]
	add	ebx,ebp
	; 20_39 23
	mov	ebp,ecx
	xor	eax,DWORD PTR 36[esp]
	xor	ebp,edx
	xor	eax,DWORD PTR 60[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 16[esp]
	rol	eax,1
	add	esi,ebp
	ror	ecx,2
	mov	ebp,ebx
	rol	ebp,5
	mov	DWORD PTR 28[esp],eax
	lea	eax,DWORD PTR 1859775393[esi*1+eax]
	mov	esi,DWORD PTR 32[esp]
	add	eax,ebp
	; 20_39 24
	mov	ebp,ebx
	xor	esi,DWORD PTR 40[esp]
	xor	ebp,ecx
	xor	esi,DWORD PTR [esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 20[esp]
	rol	esi,1
	add	edi,ebp
	ror	ebx,2
	mov	ebp,eax
	rol	ebp,5
	mov	DWORD PTR 32[esp],esi
	lea	esi,DWORD PTR 1859775393[edi*1+esi]
	mov	edi,DWORD PTR 36[esp]
	add	esi,ebp
	; 20_39 25
	mov	ebp,eax
	xor	edi,DWORD PTR 44[esp]
	xor	ebp,ebx
	xor	edi,DWORD PTR 4[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 24[esp]
	rol	edi,1
	add	edx,ebp
	ror	eax,2
	mov	ebp,esi
	rol	ebp,5
	mov	DWORD PTR 36[esp],edi
	lea	edi,DWORD PTR 1859775393[edx*1+edi]
	mov	edx,DWORD PTR 40[esp]
	add	edi,ebp
	; 20_39 26
	mov	ebp,esi
	xor	edx,DWORD PTR 48[esp]
	xor	ebp,eax
	xor	edx,DWORD PTR 8[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 28[esp]
	rol	edx,1
	add	ecx,ebp
	ror	esi,2
	mov	ebp,edi
	rol	ebp,5
	mov	DWORD PTR 40[esp],edx
	lea	edx,DWORD PTR 1859775393[ecx*1+edx]
	mov	ecx,DWORD PTR 44[esp]
	add	edx,ebp
	; 20_39 27
	mov	ebp,edi
	xor	ecx,DWORD PTR 52[esp]
	xor	ebp,esi
	xor	ecx,DWORD PTR 12[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 32[esp]
	rol	ecx,1
	add	ebx,ebp
	ror	edi,2
	mov	ebp,edx
	rol	ebp,5
	mov	DWORD PTR 44[esp],ecx
	lea	ecx,DWORD PTR 1859775393[ebx*1+ecx]
	mov	ebx,DWORD PTR 48[esp]
	add	ecx,ebp
	; 20_39 28
	mov	ebp,edx
	xor	ebx,DWORD PTR 56[esp]
	xor	ebp,edi
	xor	ebx,DWORD PTR 16[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 36[esp]
	rol	ebx,1
	add	eax,ebp
	ror	edx,2
	mov	ebp,ecx
	rol	ebp,5
	mov	DWORD PTR 48[esp],ebx
	lea	ebx,DWORD PTR 1859775393[eax*1+ebx]
	mov	eax,DWORD PTR 52[esp]
	add	ebx,ebp
	; 20_39 29
	mov	ebp,ecx
	xor	eax,DWORD PTR 60[esp]
	xor	ebp,edx
	xor	eax,DWORD PTR 20[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 40[esp]
	rol	eax,1
	add	esi,ebp
	ror	ecx,2
	mov	ebp,ebx
	rol	ebp,5
	mov	DWORD PTR 52[esp],eax
	lea	eax,DWORD PTR 1859775393[esi*1+eax]
	mov	esi,DWORD PTR 56[esp]
	add	eax,ebp
	; 20_39 30
	mov	ebp,ebx
	xor	esi,DWORD PTR [esp]
	xor	ebp,ecx
	xor	esi,DWORD PTR 24[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 44[esp]
	rol	esi,1
	add	edi,ebp
	ror	ebx,2
	mov	ebp,eax
	rol	ebp,5
	mov	DWORD PTR 56[esp],esi
	lea	esi,DWORD PTR 1859775393[edi*1+esi]
	mov	edi,DWORD PTR 60[esp]
	add	esi,ebp
	; 20_39 31
	mov	ebp,eax
	xor	edi,DWORD PTR 4[esp]
	xor	ebp,ebx
	xor	edi,DWORD PTR 28[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 48[esp]
	rol	edi,1
	add	edx,ebp
	ror	eax,2
	mov	ebp,esi
	rol	ebp,5
	mov	DWORD PTR 60[esp],edi
	lea	edi,DWORD PTR 1859775393[edx*1+edi]
	mov	edx,DWORD PTR [esp]
	add	edi,ebp
	; 20_39 32
	mov	ebp,esi
	xor	edx,DWORD PTR 8[esp]
	xor	ebp,eax
	xor	edx,DWORD PTR 32[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 52[esp]
	rol	edx,1
	add	ecx,ebp
	ror	esi,2
	mov	ebp,edi
	rol	ebp,5
	mov	DWORD PTR [esp],edx
	lea	edx,DWORD PTR 1859775393[ecx*1+edx]
	mov	ecx,DWORD PTR 4[esp]
	add	edx,ebp
	; 20_39 33
	mov	ebp,edi
	xor	ecx,DWORD PTR 12[esp]
	xor	ebp,esi
	xor	ecx,DWORD PTR 36[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 56[esp]
	rol	ecx,1
	add	ebx,ebp
	ror	edi,2
	mov	ebp,edx
	rol	ebp,5
	mov	DWORD PTR 4[esp],ecx
	lea	ecx,DWORD PTR 1859775393[ebx*1+ecx]
	mov	ebx,DWORD PTR 8[esp]
	add	ecx,ebp
	; 20_39 34
	mov	ebp,edx
	xor	ebx,DWORD PTR 16[esp]
	xor	ebp,edi
	xor	ebx,DWORD PTR 40[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 60[esp]
	rol	ebx,1
	add	eax,ebp
	ror	edx,2
	mov	ebp,ecx
	rol	ebp,5
	mov	DWORD PTR 8[esp],ebx
	lea	ebx,DWORD PTR 1859775393[eax*1+ebx]
	mov	eax,DWORD PTR 12[esp]
	add	ebx,ebp
	; 20_39 35
	mov	ebp,ecx
	xor	eax,DWORD PTR 20[esp]
	xor	ebp,edx
	xor	eax,DWORD PTR 44[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR [esp]
	rol	eax,1
	add	esi,ebp
	ror	ecx,2
	mov	ebp,ebx
	rol	ebp,5
	mov	DWORD PTR 12[esp],eax
	lea	eax,DWORD PTR 1859775393[esi*1+eax]
	mov	esi,DWORD PTR 16[esp]
	add	eax,ebp
	; 20_39 36
	mov	ebp,ebx
	xor	esi,DWORD PTR 24[esp]
	xor	ebp,ecx
	xor	esi,DWORD PTR 48[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 4[esp]
	rol	esi,1
	add	edi,ebp
	ror	ebx,2
	mov	ebp,eax
	rol	ebp,5
	mov	DWORD PTR 16[esp],esi
	lea	esi,DWORD PTR 1859775393[edi*1+esi]
	mov	edi,DWORD PTR 20[esp]
	add	esi,ebp
	; 20_39 37
	mov	ebp,eax
	xor	edi,DWORD PTR 28[esp]
	xor	ebp,ebx
	xor	edi,DWORD PTR 52[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 8[esp]
	rol	edi,1
	add	edx,ebp
	ror	eax,2
	mov	ebp,esi
	rol	ebp,5
	mov	DWORD PTR 20[esp],edi
	lea	edi,DWORD PTR 1859775393[edx*1+edi]
	mov	edx,DWORD PTR 24[esp]
	add	edi,ebp
	; 20_39 38
	mov	ebp,esi
	xor	edx,DWORD PTR 32[esp]
	xor	ebp,eax
	xor	edx,DWORD PTR 56[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 12[esp]
	rol	edx,1
	add	ecx,ebp
	ror	esi,2
	mov	ebp,edi
	rol	ebp,5
	mov	DWORD PTR 24[esp],edx
	lea	edx,DWORD PTR 1859775393[ecx*1+edx]
	mov	ecx,DWORD PTR 28[esp]
	add	edx,ebp
	; 20_39 39
	mov	ebp,edi
	xor	ecx,DWORD PTR 36[esp]
	xor	ebp,esi
	xor	ecx,DWORD PTR 60[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 16[esp]
	rol	ecx,1
	add	ebx,ebp
	ror	edi,2
	mov	ebp,edx
	rol	ebp,5
	mov	DWORD PTR 28[esp],ecx
	lea	ecx,DWORD PTR 1859775393[ebx*1+ecx]
	mov	ebx,DWORD PTR 32[esp]
	add	ecx,ebp
	; 40_59 40
	mov	ebp,edi
	xor	ebx,DWORD PTR 40[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR [esp]
	and	ebp,edx
	xor	ebx,DWORD PTR 20[esp]
	rol	ebx,1
	add	ebp,eax
	ror	edx,2
	mov	eax,ecx
	rol	eax,5
	mov	DWORD PTR 32[esp],ebx
	lea	ebx,DWORD PTR 2400959708[ebp*1+ebx]
	mov	ebp,edi
	add	ebx,eax
	and	ebp,esi
	mov	eax,DWORD PTR 36[esp]
	add	ebx,ebp
	; 40_59 41
	mov	ebp,edx
	xor	eax,DWORD PTR 44[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 4[esp]
	and	ebp,ecx
	xor	eax,DWORD PTR 24[esp]
	rol	eax,1
	add	ebp,esi
	ror	ecx,2
	mov	esi,ebx
	rol	esi,5
	mov	DWORD PTR 36[esp],eax
	lea	eax,DWORD PTR 2400959708[ebp*1+eax]
	mov	ebp,edx
	add	eax,esi
	and	ebp,edi
	mov	esi,DWORD PTR 40[esp]
	add	eax,ebp
	; 40_59 42
	mov	ebp,ecx
	xor	esi,DWORD PTR 48[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 8[esp]
	and	ebp,ebx
	xor	esi,DWORD PTR 28[esp]
	rol	esi,1
	add	ebp,edi
	ror	ebx,2
	mov	edi,eax
	rol	edi,5
	mov	DWORD PTR 40[esp],esi
	lea	esi,DWORD PTR 2400959708[ebp*1+esi]
	mov	ebp,ecx
	add	esi,edi
	and	ebp,edx
	mov	edi,DWORD PTR 44[esp]
	add	esi,ebp
	; 40_59 43
	mov	ebp,ebx
	xor	edi,DWORD PTR 52[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 12[esp]
	and	ebp,eax
	xor	edi,DWORD PTR 32[esp]
	rol	edi,1
	add	ebp,edx
	ror	eax,2
	mov	edx,esi
	rol	edx,5
	mov	DWORD PTR 44[esp],edi
	lea	edi,DWORD PTR 2400959708[ebp*1+edi]
	mov	ebp,ebx
	add	edi,edx
	and	ebp,ecx
	mov	edx,DWORD PTR 48[esp]
	add	edi,ebp
	; 40_59 44
	mov	ebp,eax
	xor	edx,DWORD PTR 56[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 16[esp]
	and	ebp,esi
	xor	edx,DWORD PTR 36[esp]
	rol	edx,1
	add	ebp,ecx
	ror	esi,2
	mov	ecx,edi
	rol	ecx,5
	mov	DWORD PTR 48[esp],edx
	lea	edx,DWORD PTR 2400959708[ebp*1+edx]
	mov	ebp,eax
	add	edx,ecx
	and	ebp,ebx
	mov	ecx,DWORD PTR 52[esp]
	add	edx,ebp
	; 40_59 45
	mov	ebp,esi
	xor	ecx,DWORD PTR 60[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 20[esp]
	and	ebp,edi
	xor	ecx,DWORD PTR 40[esp]
	rol	ecx,1
	add	ebp,ebx
	ror	edi,2
	mov	ebx,edx
	rol	ebx,5
	mov	DWORD PTR 52[esp],ecx
	lea	ecx,DWORD PTR 2400959708[ebp*1+ecx]
	mov	ebp,esi
	add	ecx,ebx
	and	ebp,eax
	mov	ebx,DWORD PTR 56[esp]
	add	ecx,ebp
	; 40_59 46
	mov	ebp,edi
	xor	ebx,DWORD PTR [esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 24[esp]
	and	ebp,edx
	xor	ebx,DWORD PTR 44[esp]
	rol	ebx,1
	add	ebp,eax
	ror	edx,2
	mov	eax,ecx
	rol	eax,5
	mov	DWORD PTR 56[esp],ebx
	lea	ebx,DWORD PTR 2400959708[ebp*1+ebx]
	mov	ebp,edi
	add	ebx,eax
	and	ebp,esi
	mov	eax,DWORD PTR 60[esp]
	add	ebx,ebp
	; 40_59 47
	mov	ebp,edx
	xor	eax,DWORD PTR 4[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 28[esp]
	and	ebp,ecx
	xor	eax,DWORD PTR 48[esp]
	rol	eax,1
	add	ebp,esi
	ror	ecx,2
	mov	esi,ebx
	rol	esi,5
	mov	DWORD PTR 60[esp],eax
	lea	eax,DWORD PTR 2400959708[ebp*1+eax]
	mov	ebp,edx
	add	eax,esi
	and	ebp,edi
	mov	esi,DWORD PTR [esp]
	add	eax,ebp
	; 40_59 48
	mov	ebp,ecx
	xor	esi,DWORD PTR 8[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 32[esp]
	and	ebp,ebx
	xor	esi,DWORD PTR 52[esp]
	rol	esi,1
	add	ebp,edi
	ror	ebx,2
	mov	edi,eax
	rol	edi,5
	mov	DWORD PTR [esp],esi
	lea	esi,DWORD PTR 2400959708[ebp*1+esi]
	mov	ebp,ecx
	add	esi,edi
	and	ebp,edx
	mov	edi,DWORD PTR 4[esp]
	add	esi,ebp
	; 40_59 49
	mov	ebp,ebx
	xor	edi,DWORD PTR 12[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 36[esp]
	and	ebp,eax
	xor	edi,DWORD PTR 56[esp]
	rol	edi,1
	add	ebp,edx
	ror	eax,2
	mov	edx,esi
	rol	edx,5
	mov	DWORD PTR 4[esp],edi
	lea	edi,DWORD PTR 2400959708[ebp*1+edi]
	mov	ebp,ebx
	add	edi,edx
	and	ebp,ecx
	mov	edx,DWORD PTR 8[esp]
	add	edi,ebp
	; 40_59 50
	mov	ebp,eax
	xor	edx,DWORD PTR 16[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 40[esp]
	and	ebp,esi
	xor	edx,DWORD PTR 60[esp]
	rol	edx,1
	add	ebp,ecx
	ror	esi,2
	mov	ecx,edi
	rol	ecx,5
	mov	DWORD PTR 8[esp],edx
	lea	edx,DWORD PTR 2400959708[ebp*1+edx]
	mov	ebp,eax
	add	edx,ecx
	and	ebp,ebx
	mov	ecx,DWORD PTR 12[esp]
	add	edx,ebp
	; 40_59 51
	mov	ebp,esi
	xor	ecx,DWORD PTR 20[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 44[esp]
	and	ebp,edi
	xor	ecx,DWORD PTR [esp]
	rol	ecx,1
	add	ebp,ebx
	ror	edi,2
	mov	ebx,edx
	rol	ebx,5
	mov	DWORD PTR 12[esp],ecx
	lea	ecx,DWORD PTR 2400959708[ebp*1+ecx]
	mov	ebp,esi
	add	ecx,ebx
	and	ebp,eax
	mov	ebx,DWORD PTR 16[esp]
	add	ecx,ebp
	; 40_59 52
	mov	ebp,edi
	xor	ebx,DWORD PTR 24[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 48[esp]
	and	ebp,edx
	xor	ebx,DWORD PTR 4[esp]
	rol	ebx,1
	add	ebp,eax
	ror	edx,2
	mov	eax,ecx
	rol	eax,5
	mov	DWORD PTR 16[esp],ebx
	lea	ebx,DWORD PTR 2400959708[ebp*1+ebx]
	mov	ebp,edi
	add	ebx,eax
	and	ebp,esi
	mov	eax,DWORD PTR 20[esp]
	add	ebx,ebp
	; 40_59 53
	mov	ebp,edx
	xor	eax,DWORD PTR 28[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 52[esp]
	and	ebp,ecx
	xor	eax,DWORD PTR 8[esp]
	rol	eax,1
	add	ebp,esi
	ror	ecx,2
	mov	esi,ebx
	rol	esi,5
	mov	DWORD PTR 20[esp],eax
	lea	eax,DWORD PTR 2400959708[ebp*1+eax]
	mov	ebp,edx
	add	eax,esi
	and	ebp,edi
	mov	esi,DWORD PTR 24[esp]
	add	eax,ebp
	; 40_59 54
	mov	ebp,ecx
	xor	esi,DWORD PTR 32[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 56[esp]
	and	ebp,ebx
	xor	esi,DWORD PTR 12[esp]
	rol	esi,1
	add	ebp,edi
	ror	ebx,2
	mov	edi,eax
	rol	edi,5
	mov	DWORD PTR 24[esp],esi
	lea	esi,DWORD PTR 2400959708[ebp*1+esi]
	mov	ebp,ecx
	add	esi,edi
	and	ebp,edx
	mov	edi,DWORD PTR 28[esp]
	add	esi,ebp
	; 40_59 55
	mov	ebp,ebx
	xor	edi,DWORD PTR 36[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 60[esp]
	and	ebp,eax
	xor	edi,DWORD PTR 16[esp]
	rol	edi,1
	add	ebp,edx
	ror	eax,2
	mov	edx,esi
	rol	edx,5
	mov	DWORD PTR 28[esp],edi
	lea	edi,DWORD PTR 2400959708[ebp*1+edi]
	mov	ebp,ebx
	add	edi,edx
	and	ebp,ecx
	mov	edx,DWORD PTR 32[esp]
	add	edi,ebp
	; 40_59 56
	mov	ebp,eax
	xor	edx,DWORD PTR 40[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR [esp]
	and	ebp,esi
	xor	edx,DWORD PTR 20[esp]
	rol	edx,1
	add	ebp,ecx
	ror	esi,2
	mov	ecx,edi
	rol	ecx,5
	mov	DWORD PTR 32[esp],edx
	lea	edx,DWORD PTR 2400959708[ebp*1+edx]
	mov	ebp,eax
	add	edx,ecx
	and	ebp,ebx
	mov	ecx,DWORD PTR 36[esp]
	add	edx,ebp
	; 40_59 57
	mov	ebp,esi
	xor	ecx,DWORD PTR 44[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 4[esp]
	and	ebp,edi
	xor	ecx,DWORD PTR 24[esp]
	rol	ecx,1
	add	ebp,ebx
	ror	edi,2
	mov	ebx,edx
	rol	ebx,5
	mov	DWORD PTR 36[esp],ecx
	lea	ecx,DWORD PTR 2400959708[ebp*1+ecx]
	mov	ebp,esi
	add	ecx,ebx
	and	ebp,eax
	mov	ebx,DWORD PTR 40[esp]
	add	ecx,ebp
	; 40_59 58
	mov	ebp,edi
	xor	ebx,DWORD PTR 48[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 8[esp]
	and	ebp,edx
	xor	ebx,DWORD PTR 28[esp]
	rol	ebx,1
	add	ebp,eax
	ror	edx,2
	mov	eax,ecx
	rol	eax,5
	mov	DWORD PTR 40[esp],ebx
	lea	ebx,DWORD PTR 2400959708[ebp*1+ebx]
	mov	ebp,edi
	add	ebx,eax
	and	ebp,esi
	mov	eax,DWORD PTR 44[esp]
	add	ebx,ebp
	; 40_59 59
	mov	ebp,edx
	xor	eax,DWORD PTR 52[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 12[esp]
	and	ebp,ecx
	xor	eax,DWORD PTR 32[esp]
	rol	eax,1
	add	ebp,esi
	ror	ecx,2
	mov	esi,ebx
	rol	esi,5
	mov	DWORD PTR 44[esp],eax
	lea	eax,DWORD PTR 2400959708[ebp*1+eax]
	mov	ebp,edx
	add	eax,esi
	and	ebp,edi
	mov	esi,DWORD PTR 48[esp]
	add	eax,ebp
	; 20_39 60
	mov	ebp,ebx
	xor	esi,DWORD PTR 56[esp]
	xor	ebp,ecx
	xor	esi,DWORD PTR 16[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 36[esp]
	rol	esi,1
	add	edi,ebp
	ror	ebx,2
	mov	ebp,eax
	rol	ebp,5
	mov	DWORD PTR 48[esp],esi
	lea	esi,DWORD PTR 3395469782[edi*1+esi]
	mov	edi,DWORD PTR 52[esp]
	add	esi,ebp
	; 20_39 61
	mov	ebp,eax
	xor	edi,DWORD PTR 60[esp]
	xor	ebp,ebx
	xor	edi,DWORD PTR 20[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 40[esp]
	rol	edi,1
	add	edx,ebp
	ror	eax,2
	mov	ebp,esi
	rol	ebp,5
	mov	DWORD PTR 52[esp],edi
	lea	edi,DWORD PTR 3395469782[edx*1+edi]
	mov	edx,DWORD PTR 56[esp]
	add	edi,ebp
	; 20_39 62
	mov	ebp,esi
	xor	edx,DWORD PTR [esp]
	xor	ebp,eax
	xor	edx,DWORD PTR 24[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 44[esp]
	rol	edx,1
	add	ecx,ebp
	ror	esi,2
	mov	ebp,edi
	rol	ebp,5
	mov	DWORD PTR 56[esp],edx
	lea	edx,DWORD PTR 3395469782[ecx*1+edx]
	mov	ecx,DWORD PTR 60[esp]
	add	edx,ebp
	; 20_39 63
	mov	ebp,edi
	xor	ecx,DWORD PTR 4[esp]
	xor	ebp,esi
	xor	ecx,DWORD PTR 28[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 48[esp]
	rol	ecx,1
	add	ebx,ebp
	ror	edi,2
	mov	ebp,edx
	rol	ebp,5
	mov	DWORD PTR 60[esp],ecx
	lea	ecx,DWORD PTR 3395469782[ebx*1+ecx]
	mov	ebx,DWORD PTR [esp]
	add	ecx,ebp
	; 20_39 64
	mov	ebp,edx
	xor	ebx,DWORD PTR 8[esp]
	xor	ebp,edi
	xor	ebx,DWORD PTR 32[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 52[esp]
	rol	ebx,1
	add	eax,ebp
	ror	edx,2
	mov	ebp,ecx
	rol	ebp,5
	mov	DWORD PTR [esp],ebx
	lea	ebx,DWORD PTR 3395469782[eax*1+ebx]
	mov	eax,DWORD PTR 4[esp]
	add	ebx,ebp
	; 20_39 65
	mov	ebp,ecx
	xor	eax,DWORD PTR 12[esp]
	xor	ebp,edx
	xor	eax,DWORD PTR 36[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 56[esp]
	rol	eax,1
	add	esi,ebp
	ror	ecx,2
	mov	ebp,ebx
	rol	ebp,5
	mov	DWORD PTR 4[esp],eax
	lea	eax,DWORD PTR 3395469782[esi*1+eax]
	mov	esi,DWORD PTR 8[esp]
	add	eax,ebp
	; 20_39 66
	mov	ebp,ebx
	xor	esi,DWORD PTR 16[esp]
	xor	ebp,ecx
	xor	esi,DWORD PTR 40[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 60[esp]
	rol	esi,1
	add	edi,ebp
	ror	ebx,2
	mov	ebp,eax
	rol	ebp,5
	mov	DWORD PTR 8[esp],esi
	lea	esi,DWORD PTR 3395469782[edi*1+esi]
	mov	edi,DWORD PTR 12[esp]
	add	esi,ebp
	; 20_39 67
	mov	ebp,eax
	xor	edi,DWORD PTR 20[esp]
	xor	ebp,ebx
	xor	edi,DWORD PTR 44[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR [esp]
	rol	edi,1
	add	edx,ebp
	ror	eax,2
	mov	ebp,esi
	rol	ebp,5
	mov	DWORD PTR 12[esp],edi
	lea	edi,DWORD PTR 3395469782[edx*1+edi]
	mov	edx,DWORD PTR 16[esp]
	add	edi,ebp
	; 20_39 68
	mov	ebp,esi
	xor	edx,DWORD PTR 24[esp]
	xor	ebp,eax
	xor	edx,DWORD PTR 48[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 4[esp]
	rol	edx,1
	add	ecx,ebp
	ror	esi,2
	mov	ebp,edi
	rol	ebp,5
	mov	DWORD PTR 16[esp],edx
	lea	edx,DWORD PTR 3395469782[ecx*1+edx]
	mov	ecx,DWORD PTR 20[esp]
	add	edx,ebp
	; 20_39 69
	mov	ebp,edi
	xor	ecx,DWORD PTR 28[esp]
	xor	ebp,esi
	xor	ecx,DWORD PTR 52[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 8[esp]
	rol	ecx,1
	add	ebx,ebp
	ror	edi,2
	mov	ebp,edx
	rol	ebp,5
	mov	DWORD PTR 20[esp],ecx
	lea	ecx,DWORD PTR 3395469782[ebx*1+ecx]
	mov	ebx,DWORD PTR 24[esp]
	add	ecx,ebp
	; 20_39 70
	mov	ebp,edx
	xor	ebx,DWORD PTR 32[esp]
	xor	ebp,edi
	xor	ebx,DWORD PTR 56[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 12[esp]
	rol	ebx,1
	add	eax,ebp
	ror	edx,2
	mov	ebp,ecx
	rol	ebp,5
	mov	DWORD PTR 24[esp],ebx
	lea	ebx,DWORD PTR 3395469782[eax*1+ebx]
	mov	eax,DWORD PTR 28[esp]
	add	ebx,ebp
	; 20_39 71
	mov	ebp,ecx
	xor	eax,DWORD PTR 36[esp]
	xor	ebp,edx
	xor	eax,DWORD PTR 60[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 16[esp]
	rol	eax,1
	add	esi,ebp
	ror	ecx,2
	mov	ebp,ebx
	rol	ebp,5
	mov	DWORD PTR 28[esp],eax
	lea	eax,DWORD PTR 3395469782[esi*1+eax]
	mov	esi,DWORD PTR 32[esp]
	add	eax,ebp
	; 20_39 72
	mov	ebp,ebx
	xor	esi,DWORD PTR 40[esp]
	xor	ebp,ecx
	xor	esi,DWORD PTR [esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 20[esp]
	rol	esi,1
	add	edi,ebp
	ror	ebx,2
	mov	ebp,eax
	rol	ebp,5
	mov	DWORD PTR 32[esp],esi
	lea	esi,DWORD PTR 3395469782[edi*1+esi]
	mov	edi,DWORD PTR 36[esp]
	add	esi,ebp
	; 20_39 73
	mov	ebp,eax
	xor	edi,DWORD PTR 44[esp]
	xor	ebp,ebx
	xor	edi,DWORD PTR 4[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 24[esp]
	rol	edi,1
	add	edx,ebp
	ror	eax,2
	mov	ebp,esi
	rol	ebp,5
	mov	DWORD PTR 36[esp],edi
	lea	edi,DWORD PTR 3395469782[edx*1+edi]
	mov	edx,DWORD PTR 40[esp]
	add	edi,ebp
	; 20_39 74
	mov	ebp,esi
	xor	edx,DWORD PTR 48[esp]
	xor	ebp,eax
	xor	edx,DWORD PTR 8[esp]
	xor	ebp,ebx
	xor	edx,DWORD PTR 28[esp]
	rol	edx,1
	add	ecx,ebp
	ror	esi,2
	mov	ebp,edi
	rol	ebp,5
	mov	DWORD PTR 40[esp],edx
	lea	edx,DWORD PTR 3395469782[ecx*1+edx]
	mov	ecx,DWORD PTR 44[esp]
	add	edx,ebp
	; 20_39 75
	mov	ebp,edi
	xor	ecx,DWORD PTR 52[esp]
	xor	ebp,esi
	xor	ecx,DWORD PTR 12[esp]
	xor	ebp,eax
	xor	ecx,DWORD PTR 32[esp]
	rol	ecx,1
	add	ebx,ebp
	ror	edi,2
	mov	ebp,edx
	rol	ebp,5
	mov	DWORD PTR 44[esp],ecx
	lea	ecx,DWORD PTR 3395469782[ebx*1+ecx]
	mov	ebx,DWORD PTR 48[esp]
	add	ecx,ebp
	; 20_39 76
	mov	ebp,edx
	xor	ebx,DWORD PTR 56[esp]
	xor	ebp,edi
	xor	ebx,DWORD PTR 16[esp]
	xor	ebp,esi
	xor	ebx,DWORD PTR 36[esp]
	rol	ebx,1
	add	eax,ebp
	ror	edx,2
	mov	ebp,ecx
	rol	ebp,5
	mov	DWORD PTR 48[esp],ebx
	lea	ebx,DWORD PTR 3395469782[eax*1+ebx]
	mov	eax,DWORD PTR 52[esp]
	add	ebx,ebp
	; 20_39 77
	mov	ebp,ecx
	xor	eax,DWORD PTR 60[esp]
	xor	ebp,edx
	xor	eax,DWORD PTR 20[esp]
	xor	ebp,edi
	xor	eax,DWORD PTR 40[esp]
	rol	eax,1
	add	esi,ebp
	ror	ecx,2
	mov	ebp,ebx
	rol	ebp,5
	lea	eax,DWORD PTR 3395469782[esi*1+eax]
	mov	esi,DWORD PTR 56[esp]
	add	eax,ebp
	; 20_39 78
	mov	ebp,ebx
	xor	esi,DWORD PTR [esp]
	xor	ebp,ecx
	xor	esi,DWORD PTR 24[esp]
	xor	ebp,edx
	xor	esi,DWORD PTR 44[esp]
	rol	esi,1
	add	edi,ebp
	ror	ebx,2
	mov	ebp,eax
	rol	ebp,5
	lea	esi,DWORD PTR 3395469782[edi*1+esi]
	mov	edi,DWORD PTR 60[esp]
	add	esi,ebp
	; 20_39 79
	mov	ebp,eax
	xor	edi,DWORD PTR 4[esp]
	xor	ebp,ebx
	xor	edi,DWORD PTR 28[esp]
	xor	ebp,ecx
	xor	edi,DWORD PTR 48[esp]
	rol	edi,1
	add	edx,ebp
	ror	eax,2
	mov	ebp,esi
	rol	ebp,5
	lea	edi,DWORD PTR 3395469782[edx*1+edi]
	add	edi,ebp
	mov	ebp,DWORD PTR 96[esp]
	mov	edx,DWORD PTR 100[esp]
	add	edi,DWORD PTR [ebp]
	add	esi,DWORD PTR 4[ebp]
	add	eax,DWORD PTR 8[ebp]
	add	ebx,DWORD PTR 12[ebp]
	add	ecx,DWORD PTR 16[ebp]
	mov	DWORD PTR [ebp],edi
	add	edx,64
	mov	DWORD PTR 4[ebp],esi
	cmp	edx,DWORD PTR 104[esp]
	mov	DWORD PTR 8[ebp],eax
	mov	edi,ecx
	mov	DWORD PTR 12[ebp],ebx
	mov	esi,edx
	mov	DWORD PTR 16[ebp],ecx
	jb	$L002loop
	add	esp,76
	pop	edi
	pop	esi
	pop	ebx
	pop	ebp
	ret
_sha1_block_data_order ENDP
ALIGN	16
__sha1_block_data_order_ssse3	PROC PRIVATE
	push	ebp
	push	ebx
	push	esi
	push	edi
	call	$L003pic_point
$L003pic_point:
	pop	ebp
	lea	ebp,DWORD PTR ($LK_XX_XX-$L003pic_point)[ebp]
$Lssse3_shortcut::
	movdqa	xmm7,XMMWORD PTR [ebp]
	movdqa	xmm0,XMMWORD PTR 16[ebp]
	movdqa	xmm1,XMMWORD PTR 32[ebp]
	movdqa	xmm2,XMMWORD PTR 48[ebp]
	movdqa	xmm6,XMMWORD PTR 64[ebp]
	mov	edi,DWORD PTR 20[esp]
	mov	ebp,DWORD PTR 24[esp]
	mov	edx,DWORD PTR 28[esp]
	mov	esi,esp
	sub	esp,208
	and	esp,-64
	movdqa	XMMWORD PTR 112[esp],xmm0
	movdqa	XMMWORD PTR 128[esp],xmm1
	movdqa	XMMWORD PTR 144[esp],xmm2
	shl	edx,6
	movdqa	XMMWORD PTR 160[esp],xmm7
	add	edx,ebp
	movdqa	XMMWORD PTR 176[esp],xmm6
	add	ebp,64
	mov	DWORD PTR 192[esp],edi
	mov	DWORD PTR 196[esp],ebp
	mov	DWORD PTR 200[esp],edx
	mov	DWORD PTR 204[esp],esi
	mov	eax,DWORD PTR [edi]
	mov	ebx,DWORD PTR 4[edi]
	mov	ecx,DWORD PTR 8[edi]
	mov	edx,DWORD PTR 12[edi]
	mov	edi,DWORD PTR 16[edi]
	mov	esi,ebx
	movdqu	xmm0,XMMWORD PTR [ebp-64]
	movdqu	xmm1,XMMWORD PTR [ebp-48]
	movdqu	xmm2,XMMWORD PTR [ebp-32]
	movdqu	xmm3,XMMWORD PTR [ebp-16]
DB	102,15,56,0,198
DB	102,15,56,0,206
DB	102,15,56,0,214
	movdqa	XMMWORD PTR 96[esp],xmm7
DB	102,15,56,0,222
	paddd	xmm0,xmm7
	paddd	xmm1,xmm7
	paddd	xmm2,xmm7
	movdqa	XMMWORD PTR [esp],xmm0
	psubd	xmm0,xmm7
	movdqa	XMMWORD PTR 16[esp],xmm1
	psubd	xmm1,xmm7
	movdqa	XMMWORD PTR 32[esp],xmm2
	psubd	xmm2,xmm7
	movdqa	xmm4,xmm1
	jmp	$L004loop
ALIGN	16
$L004loop:
	add	edi,DWORD PTR [esp]
	xor	ecx,edx
DB	102,15,58,15,224,8
	movdqa	xmm6,xmm3
	mov	ebp,eax
	rol	eax,5
	paddd	xmm7,xmm3
	movdqa	XMMWORD PTR 64[esp],xmm0
	and	esi,ecx
	xor	ecx,edx
	psrldq	xmm6,4
	xor	esi,edx
	add	edi,eax
	pxor	xmm4,xmm0
	ror	ebx,2
	add	edi,esi
	pxor	xmm6,xmm2
	add	edx,DWORD PTR 4[esp]
	xor	ebx,ecx
	mov	esi,edi
	rol	edi,5
	pxor	xmm4,xmm6
	and	ebp,ebx
	xor	ebx,ecx
	movdqa	XMMWORD PTR 48[esp],xmm7
	xor	ebp,ecx
	add	edx,edi
	movdqa	xmm0,xmm4
	movdqa	xmm6,xmm4
	ror	eax,7
	add	edx,ebp
	add	ecx,DWORD PTR 8[esp]
	xor	eax,ebx
	pslldq	xmm0,12
	paddd	xmm4,xmm4
	mov	ebp,edx
	rol	edx,5
	and	esi,eax
	xor	eax,ebx
	psrld	xmm6,31
	xor	esi,ebx
	add	ecx,edx
	movdqa	xmm7,xmm0
	ror	edi,7
	add	ecx,esi
	psrld	xmm0,30
	por	xmm4,xmm6
	add	ebx,DWORD PTR 12[esp]
	xor	edi,eax
	mov	esi,ecx
	rol	ecx,5
	pslld	xmm7,2
	pxor	xmm4,xmm0
	and	ebp,edi
	xor	edi,eax
	movdqa	xmm0,XMMWORD PTR 96[esp]
	xor	ebp,eax
	add	ebx,ecx
	pxor	xmm4,xmm7
	movdqa	xmm5,xmm2
	ror	edx,7
	add	ebx,ebp
	add	eax,DWORD PTR 16[esp]
	xor	edx,edi
DB	102,15,58,15,233,8
	movdqa	xmm7,xmm4
	mov	ebp,ebx
	rol	ebx,5
	paddd	xmm0,xmm4
	movdqa	XMMWORD PTR 80[esp],xmm1
	and	esi,edx
	xor	edx,edi
	psrldq	xmm7,4
	xor	esi,edi
	add	eax,ebx
	pxor	xmm5,xmm1
	ror	ecx,7
	add	eax,esi
	pxor	xmm7,xmm3
	add	edi,DWORD PTR 20[esp]
	xor	ecx,edx
	mov	esi,eax
	rol	eax,5
	pxor	xmm5,xmm7
	and	ebp,ecx
	xor	ecx,edx
	movdqa	XMMWORD PTR [esp],xmm0
	xor	ebp,edx
	add	edi,eax
	movdqa	xmm1,xmm5
	movdqa	xmm7,xmm5
	ror	ebx,7
	add	edi,ebp
	add	edx,DWORD PTR 24[esp]
	xor	ebx,ecx
	pslldq	xmm1,12
	paddd	xmm5,xmm5
	mov	ebp,edi
	rol	edi,5
	and	esi,ebx
	xor	ebx,ecx
	psrld	xmm7,31
	xor	esi,ecx
	add	edx,edi
	movdqa	xmm0,xmm1
	ror	eax,7
	add	edx,esi
	psrld	xmm1,30
	por	xmm5,xmm7
	add	ecx,DWORD PTR 28[esp]
	xor	eax,ebx
	mov	esi,edx
	rol	edx,5
	pslld	xmm0,2
	pxor	xmm5,xmm1
	and	ebp,eax
	xor	eax,ebx
	movdqa	xmm1,XMMWORD PTR 112[esp]
	xor	ebp,ebx
	add	ecx,edx
	pxor	xmm5,xmm0
	movdqa	xmm6,xmm3
	ror	edi,7
	add	ecx,ebp
	add	ebx,DWORD PTR 32[esp]
	xor	edi,eax
DB	102,15,58,15,242,8
	movdqa	xmm0,xmm5
	mov	ebp,ecx
	rol	ecx,5
	paddd	xmm1,xmm5
	movdqa	XMMWORD PTR 96[esp],xmm2
	and	esi,edi
	xor	edi,eax
	psrldq	xmm0,4
	xor	esi,eax
	add	ebx,ecx
	pxor	xmm6,xmm2
	ror	edx,7
	add	ebx,esi
	pxor	xmm0,xmm4
	add	eax,DWORD PTR 36[esp]
	xor	edx,edi
	mov	esi,ebx
	rol	ebx,5
	pxor	xmm6,xmm0
	and	ebp,edx
	xor	edx,edi
	movdqa	XMMWORD PTR 16[esp],xmm1
	xor	ebp,edi
	add	eax,ebx
	movdqa	xmm2,xmm6
	movdqa	xmm0,xmm6
	ror	ecx,7
	add	eax,ebp
	add	edi,DWORD PTR 40[esp]
	xor	ecx,edx
	pslldq	xmm2,12
	paddd	xmm6,xmm6
	mov	ebp,eax
	rol	eax,5
	and	esi,ecx
	xor	ecx,edx
	psrld	xmm0,31
	xor	esi,edx
	add	edi,eax
	movdqa	xmm1,xmm2
	ror	ebx,7
	add	edi,esi
	psrld	xmm2,30
	por	xmm6,xmm0
	add	edx,DWORD PTR 44[esp]
	xor	ebx,ecx
	movdqa	xmm0,XMMWORD PTR 64[esp]
	mov	esi,edi
	rol	edi,5
	pslld	xmm1,2
	pxor	xmm6,xmm2
	and	ebp,ebx
	xor	ebx,ecx
	movdqa	xmm2,XMMWORD PTR 112[esp]
	xor	ebp,ecx
	add	edx,edi
	pxor	xmm6,xmm1
	movdqa	xmm7,xmm4
	ror	eax,7
	add	edx,ebp
	add	ecx,DWORD PTR 48[esp]
	xor	eax,ebx
DB	102,15,58,15,251,8
	movdqa	xmm1,xmm6
	mov	ebp,edx
	rol	edx,5
	paddd	xmm2,xmm6
	movdqa	XMMWORD PTR 64[esp],xmm3
	and	esi,eax
	xor	eax,ebx
	psrldq	xmm1,4
	xor	esi,ebx
	add	ecx,edx
	pxor	xmm7,xmm3
	ror	edi,7
	add	ecx,esi
	pxor	xmm1,xmm5
	add	ebx,DWORD PTR 52[esp]
	xor	edi,eax
	mov	esi,ecx
	rol	ecx,5
	pxor	xmm7,xmm1
	and	ebp,edi
	xor	edi,eax
	movdqa	XMMWORD PTR 32[esp],xmm2
	xor	ebp,eax
	add	ebx,ecx
	movdqa	xmm3,xmm7
	movdqa	xmm1,xmm7
	ror	edx,7
	add	ebx,ebp
	add	eax,DWORD PTR 56[esp]
	xor	edx,edi
	pslldq	xmm3,12
	paddd	xmm7,xmm7
	mov	ebp,ebx
	rol	ebx,5
	and	esi,edx
	xor	edx,edi
	psrld	xmm1,31
	xor	esi,edi
	add	eax,ebx
	movdqa	xmm2,xmm3
	ror	ecx,7
	add	eax,esi
	psrld	xmm3,30
	por	xmm7,xmm1
	add	edi,DWORD PTR 60[esp]
	xor	ecx,edx
	movdqa	xmm1,XMMWORD PTR 80[esp]
	mov	esi,eax
	rol	eax,5
	pslld	xmm2,2
	pxor	xmm7,xmm3
	and	ebp,ecx
	xor	ecx,edx
	movdqa	xmm3,XMMWORD PTR 112[esp]
	xor	ebp,edx
	add	edi,eax
	pxor	xmm7,xmm2
	ror	ebx,7
	add	edi,ebp
	movdqa	xmm2,xmm7
	add	edx,DWORD PTR [esp]
	pxor	xmm0,xmm4
DB	102,15,58,15,214,8
	xor	ebx,ecx
	mov	ebp,edi
	rol	edi,5
	pxor	xmm0,xmm1
	movdqa	XMMWORD PTR 80[esp],xmm4
	and	esi,ebx
	xor	ebx,ecx
	movdqa	xmm4,xmm3
	paddd	xmm3,xmm7
	xor	esi,ecx
	add	edx,edi
	pxor	xmm0,xmm2
	ror	eax,7
	add	edx,esi
	add	ecx,DWORD PTR 4[esp]
	xor	eax,ebx
	movdqa	xmm2,xmm0
	movdqa	XMMWORD PTR 48[esp],xmm3
	mov	esi,edx
	rol	edx,5
	and	ebp,eax
	xor	eax,ebx
	pslld	xmm0,2
	xor	ebp,ebx
	add	ecx,edx
	psrld	xmm2,30
	ror	edi,7
	add	ecx,ebp
	add	ebx,DWORD PTR 8[esp]
	xor	edi,eax
	mov	ebp,ecx
	rol	ecx,5
	por	xmm0,xmm2
	and	esi,edi
	xor	edi,eax
	movdqa	xmm2,XMMWORD PTR 96[esp]
	xor	esi,eax
	add	ebx,ecx
	ror	edx,7
	add	ebx,esi
	add	eax,DWORD PTR 12[esp]
	movdqa	xmm3,xmm0
	xor	edx,edi
	mov	esi,ebx
	rol	ebx,5
	and	ebp,edx
	xor	edx,edi
	xor	ebp,edi
	add	eax,ebx
	ror	ecx,7
	add	eax,ebp
	add	edi,DWORD PTR 16[esp]
	pxor	xmm1,xmm5
DB	102,15,58,15,223,8
	xor	esi,edx
	mov	ebp,eax
	rol	eax,5
	pxor	xmm1,xmm2
	movdqa	XMMWORD PTR 96[esp],xmm5
	xor	esi,ecx
	add	edi,eax
	movdqa	xmm5,xmm4
	paddd	xmm4,xmm0
	ror	ebx,7
	add	edi,esi
	pxor	xmm1,xmm3
	add	edx,DWORD PTR 20[esp]
	xor	ebp,ecx
	mov	esi,edi
	rol	edi,5
	movdqa	xmm3,xmm1
	movdqa	XMMWORD PTR [esp],xmm4
	xor	ebp,ebx
	add	edx,edi
	ror	eax,7
	add	edx,ebp
	pslld	xmm1,2
	add	ecx,DWORD PTR 24[esp]
	xor	esi,ebx
	psrld	xmm3,30
	mov	ebp,edx
	rol	edx,5
	xor	esi,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,esi
	por	xmm1,xmm3
	add	ebx,DWORD PTR 28[esp]
	xor	ebp,eax
	movdqa	xmm3,XMMWORD PTR 64[esp]
	mov	esi,ecx
	rol	ecx,5
	xor	ebp,edi
	add	ebx,ecx
	ror	edx,7
	movdqa	xmm4,xmm1
	add	ebx,ebp
	add	eax,DWORD PTR 32[esp]
	pxor	xmm2,xmm6
DB	102,15,58,15,224,8
	xor	esi,edi
	mov	ebp,ebx
	rol	ebx,5
	pxor	xmm2,xmm3
	movdqa	XMMWORD PTR 64[esp],xmm6
	xor	esi,edx
	add	eax,ebx
	movdqa	xmm6,XMMWORD PTR 128[esp]
	paddd	xmm5,xmm1
	ror	ecx,7
	add	eax,esi
	pxor	xmm2,xmm4
	add	edi,DWORD PTR 36[esp]
	xor	ebp,edx
	mov	esi,eax
	rol	eax,5
	movdqa	xmm4,xmm2
	movdqa	XMMWORD PTR 16[esp],xmm5
	xor	ebp,ecx
	add	edi,eax
	ror	ebx,7
	add	edi,ebp
	pslld	xmm2,2
	add	edx,DWORD PTR 40[esp]
	xor	esi,ecx
	psrld	xmm4,30
	mov	ebp,edi
	rol	edi,5
	xor	esi,ebx
	add	edx,edi
	ror	eax,7
	add	edx,esi
	por	xmm2,xmm4
	add	ecx,DWORD PTR 44[esp]
	xor	ebp,ebx
	movdqa	xmm4,XMMWORD PTR 80[esp]
	mov	esi,edx
	rol	edx,5
	xor	ebp,eax
	add	ecx,edx
	ror	edi,7
	movdqa	xmm5,xmm2
	add	ecx,ebp
	add	ebx,DWORD PTR 48[esp]
	pxor	xmm3,xmm7
DB	102,15,58,15,233,8
	xor	esi,eax
	mov	ebp,ecx
	rol	ecx,5
	pxor	xmm3,xmm4
	movdqa	XMMWORD PTR 80[esp],xmm7
	xor	esi,edi
	add	ebx,ecx
	movdqa	xmm7,xmm6
	paddd	xmm6,xmm2
	ror	edx,7
	add	ebx,esi
	pxor	xmm3,xmm5
	add	eax,DWORD PTR 52[esp]
	xor	ebp,edi
	mov	esi,ebx
	rol	ebx,5
	movdqa	xmm5,xmm3
	movdqa	XMMWORD PTR 32[esp],xmm6
	xor	ebp,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,ebp
	pslld	xmm3,2
	add	edi,DWORD PTR 56[esp]
	xor	esi,edx
	psrld	xmm5,30
	mov	ebp,eax
	rol	eax,5
	xor	esi,ecx
	add	edi,eax
	ror	ebx,7
	add	edi,esi
	por	xmm3,xmm5
	add	edx,DWORD PTR 60[esp]
	xor	ebp,ecx
	movdqa	xmm5,XMMWORD PTR 96[esp]
	mov	esi,edi
	rol	edi,5
	xor	ebp,ebx
	add	edx,edi
	ror	eax,7
	movdqa	xmm6,xmm3
	add	edx,ebp
	add	ecx,DWORD PTR [esp]
	pxor	xmm4,xmm0
DB	102,15,58,15,242,8
	xor	esi,ebx
	mov	ebp,edx
	rol	edx,5
	pxor	xmm4,xmm5
	movdqa	XMMWORD PTR 96[esp],xmm0
	xor	esi,eax
	add	ecx,edx
	movdqa	xmm0,xmm7
	paddd	xmm7,xmm3
	ror	edi,7
	add	ecx,esi
	pxor	xmm4,xmm6
	add	ebx,DWORD PTR 4[esp]
	xor	ebp,eax
	mov	esi,ecx
	rol	ecx,5
	movdqa	xmm6,xmm4
	movdqa	XMMWORD PTR 48[esp],xmm7
	xor	ebp,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,ebp
	pslld	xmm4,2
	add	eax,DWORD PTR 8[esp]
	xor	esi,edi
	psrld	xmm6,30
	mov	ebp,ebx
	rol	ebx,5
	xor	esi,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,esi
	por	xmm4,xmm6
	add	edi,DWORD PTR 12[esp]
	xor	ebp,edx
	movdqa	xmm6,XMMWORD PTR 64[esp]
	mov	esi,eax
	rol	eax,5
	xor	ebp,ecx
	add	edi,eax
	ror	ebx,7
	movdqa	xmm7,xmm4
	add	edi,ebp
	add	edx,DWORD PTR 16[esp]
	pxor	xmm5,xmm1
DB	102,15,58,15,251,8
	xor	esi,ecx
	mov	ebp,edi
	rol	edi,5
	pxor	xmm5,xmm6
	movdqa	XMMWORD PTR 64[esp],xmm1
	xor	esi,ebx
	add	edx,edi
	movdqa	xmm1,xmm0
	paddd	xmm0,xmm4
	ror	eax,7
	add	edx,esi
	pxor	xmm5,xmm7
	add	ecx,DWORD PTR 20[esp]
	xor	ebp,ebx
	mov	esi,edx
	rol	edx,5
	movdqa	xmm7,xmm5
	movdqa	XMMWORD PTR [esp],xmm0
	xor	ebp,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,ebp
	pslld	xmm5,2
	add	ebx,DWORD PTR 24[esp]
	xor	esi,eax
	psrld	xmm7,30
	mov	ebp,ecx
	rol	ecx,5
	xor	esi,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,esi
	por	xmm5,xmm7
	add	eax,DWORD PTR 28[esp]
	xor	ebp,edi
	movdqa	xmm7,XMMWORD PTR 80[esp]
	mov	esi,ebx
	rol	ebx,5
	xor	ebp,edx
	add	eax,ebx
	ror	ecx,7
	movdqa	xmm0,xmm5
	add	eax,ebp
	mov	ebp,ecx
	pxor	xmm6,xmm2
DB	102,15,58,15,196,8
	xor	ecx,edx
	add	edi,DWORD PTR 32[esp]
	and	ebp,edx
	pxor	xmm6,xmm7
	movdqa	XMMWORD PTR 80[esp],xmm2
	and	esi,ecx
	ror	ebx,7
	movdqa	xmm2,xmm1
	paddd	xmm1,xmm5
	add	edi,ebp
	mov	ebp,eax
	pxor	xmm6,xmm0
	rol	eax,5
	add	edi,esi
	xor	ecx,edx
	add	edi,eax
	movdqa	xmm0,xmm6
	movdqa	XMMWORD PTR 16[esp],xmm1
	mov	esi,ebx
	xor	ebx,ecx
	add	edx,DWORD PTR 36[esp]
	and	esi,ecx
	pslld	xmm6,2
	and	ebp,ebx
	ror	eax,7
	psrld	xmm0,30
	add	edx,esi
	mov	esi,edi
	rol	edi,5
	add	edx,ebp
	xor	ebx,ecx
	add	edx,edi
	por	xmm6,xmm0
	mov	ebp,eax
	xor	eax,ebx
	movdqa	xmm0,XMMWORD PTR 96[esp]
	add	ecx,DWORD PTR 40[esp]
	and	ebp,ebx
	and	esi,eax
	ror	edi,7
	add	ecx,ebp
	movdqa	xmm1,xmm6
	mov	ebp,edx
	rol	edx,5
	add	ecx,esi
	xor	eax,ebx
	add	ecx,edx
	mov	esi,edi
	xor	edi,eax
	add	ebx,DWORD PTR 44[esp]
	and	esi,eax
	and	ebp,edi
	ror	edx,7
	add	ebx,esi
	mov	esi,ecx
	rol	ecx,5
	add	ebx,ebp
	xor	edi,eax
	add	ebx,ecx
	mov	ebp,edx
	pxor	xmm7,xmm3
DB	102,15,58,15,205,8
	xor	edx,edi
	add	eax,DWORD PTR 48[esp]
	and	ebp,edi
	pxor	xmm7,xmm0
	movdqa	XMMWORD PTR 96[esp],xmm3
	and	esi,edx
	ror	ecx,7
	movdqa	xmm3,XMMWORD PTR 144[esp]
	paddd	xmm2,xmm6
	add	eax,ebp
	mov	ebp,ebx
	pxor	xmm7,xmm1
	rol	ebx,5
	add	eax,esi
	xor	edx,edi
	add	eax,ebx
	movdqa	xmm1,xmm7
	movdqa	XMMWORD PTR 32[esp],xmm2
	mov	esi,ecx
	xor	ecx,edx
	add	edi,DWORD PTR 52[esp]
	and	esi,edx
	pslld	xmm7,2
	and	ebp,ecx
	ror	ebx,7
	psrld	xmm1,30
	add	edi,esi
	mov	esi,eax
	rol	eax,5
	add	edi,ebp
	xor	ecx,edx
	add	edi,eax
	por	xmm7,xmm1
	mov	ebp,ebx
	xor	ebx,ecx
	movdqa	xmm1,XMMWORD PTR 64[esp]
	add	edx,DWORD PTR 56[esp]
	and	ebp,ecx
	and	esi,ebx
	ror	eax,7
	add	edx,ebp
	movdqa	xmm2,xmm7
	mov	ebp,edi
	rol	edi,5
	add	edx,esi
	xor	ebx,ecx
	add	edx,edi
	mov	esi,eax
	xor	eax,ebx
	add	ecx,DWORD PTR 60[esp]
	and	esi,ebx
	and	ebp,eax
	ror	edi,7
	add	ecx,esi
	mov	esi,edx
	rol	edx,5
	add	ecx,ebp
	xor	eax,ebx
	add	ecx,edx
	mov	ebp,edi
	pxor	xmm0,xmm4
DB	102,15,58,15,214,8
	xor	edi,eax
	add	ebx,DWORD PTR [esp]
	and	ebp,eax
	pxor	xmm0,xmm1
	movdqa	XMMWORD PTR 64[esp],xmm4
	and	esi,edi
	ror	edx,7
	movdqa	xmm4,xmm3
	paddd	xmm3,xmm7
	add	ebx,ebp
	mov	ebp,ecx
	pxor	xmm0,xmm2
	rol	ecx,5
	add	ebx,esi
	xor	edi,eax
	add	ebx,ecx
	movdqa	xmm2,xmm0
	movdqa	XMMWORD PTR 48[esp],xmm3
	mov	esi,edx
	xor	edx,edi
	add	eax,DWORD PTR 4[esp]
	and	esi,edi
	pslld	xmm0,2
	and	ebp,edx
	ror	ecx,7
	psrld	xmm2,30
	add	eax,esi
	mov	esi,ebx
	rol	ebx,5
	add	eax,ebp
	xor	edx,edi
	add	eax,ebx
	por	xmm0,xmm2
	mov	ebp,ecx
	xor	ecx,edx
	movdqa	xmm2,XMMWORD PTR 80[esp]
	add	edi,DWORD PTR 8[esp]
	and	ebp,edx
	and	esi,ecx
	ror	ebx,7
	add	edi,ebp
	movdqa	xmm3,xmm0
	mov	ebp,eax
	rol	eax,5
	add	edi,esi
	xor	ecx,edx
	add	edi,eax
	mov	esi,ebx
	xor	ebx,ecx
	add	edx,DWORD PTR 12[esp]
	and	esi,ecx
	and	ebp,ebx
	ror	eax,7
	add	edx,esi
	mov	esi,edi
	rol	edi,5
	add	edx,ebp
	xor	ebx,ecx
	add	edx,edi
	mov	ebp,eax
	pxor	xmm1,xmm5
DB	102,15,58,15,223,8
	xor	eax,ebx
	add	ecx,DWORD PTR 16[esp]
	and	ebp,ebx
	pxor	xmm1,xmm2
	movdqa	XMMWORD PTR 80[esp],xmm5
	and	esi,eax
	ror	edi,7
	movdqa	xmm5,xmm4
	paddd	xmm4,xmm0
	add	ecx,ebp
	mov	ebp,edx
	pxor	xmm1,xmm3
	rol	edx,5
	add	ecx,esi
	xor	eax,ebx
	add	ecx,edx
	movdqa	xmm3,xmm1
	movdqa	XMMWORD PTR [esp],xmm4
	mov	esi,edi
	xor	edi,eax
	add	ebx,DWORD PTR 20[esp]
	and	esi,eax
	pslld	xmm1,2
	and	ebp,edi
	ror	edx,7
	psrld	xmm3,30
	add	ebx,esi
	mov	esi,ecx
	rol	ecx,5
	add	ebx,ebp
	xor	edi,eax
	add	ebx,ecx
	por	xmm1,xmm3
	mov	ebp,edx
	xor	edx,edi
	movdqa	xmm3,XMMWORD PTR 96[esp]
	add	eax,DWORD PTR 24[esp]
	and	ebp,edi
	and	esi,edx
	ror	ecx,7
	add	eax,ebp
	movdqa	xmm4,xmm1
	mov	ebp,ebx
	rol	ebx,5
	add	eax,esi
	xor	edx,edi
	add	eax,ebx
	mov	esi,ecx
	xor	ecx,edx
	add	edi,DWORD PTR 28[esp]
	and	esi,edx
	and	ebp,ecx
	ror	ebx,7
	add	edi,esi
	mov	esi,eax
	rol	eax,5
	add	edi,ebp
	xor	ecx,edx
	add	edi,eax
	mov	ebp,ebx
	pxor	xmm2,xmm6
DB	102,15,58,15,224,8
	xor	ebx,ecx
	add	edx,DWORD PTR 32[esp]
	and	ebp,ecx
	pxor	xmm2,xmm3
	movdqa	XMMWORD PTR 96[esp],xmm6
	and	esi,ebx
	ror	eax,7
	movdqa	xmm6,xmm5
	paddd	xmm5,xmm1
	add	edx,ebp
	mov	ebp,edi
	pxor	xmm2,xmm4
	rol	edi,5
	add	edx,esi
	xor	ebx,ecx
	add	edx,edi
	movdqa	xmm4,xmm2
	movdqa	XMMWORD PTR 16[esp],xmm5
	mov	esi,eax
	xor	eax,ebx
	add	ecx,DWORD PTR 36[esp]
	and	esi,ebx
	pslld	xmm2,2
	and	ebp,eax
	ror	edi,7
	psrld	xmm4,30
	add	ecx,esi
	mov	esi,edx
	rol	edx,5
	add	ecx,ebp
	xor	eax,ebx
	add	ecx,edx
	por	xmm2,xmm4
	mov	ebp,edi
	xor	edi,eax
	movdqa	xmm4,XMMWORD PTR 64[esp]
	add	ebx,DWORD PTR 40[esp]
	and	ebp,eax
	and	esi,edi
	ror	edx,7
	add	ebx,ebp
	movdqa	xmm5,xmm2
	mov	ebp,ecx
	rol	ecx,5
	add	ebx,esi
	xor	edi,eax
	add	ebx,ecx
	mov	esi,edx
	xor	edx,edi
	add	eax,DWORD PTR 44[esp]
	and	esi,edi
	and	ebp,edx
	ror	ecx,7
	add	eax,esi
	mov	esi,ebx
	rol	ebx,5
	add	eax,ebp
	xor	edx,edi
	add	eax,ebx
	add	edi,DWORD PTR 48[esp]
	pxor	xmm3,xmm7
DB	102,15,58,15,233,8
	xor	esi,edx
	mov	ebp,eax
	rol	eax,5
	pxor	xmm3,xmm4
	movdqa	XMMWORD PTR 64[esp],xmm7
	xor	esi,ecx
	add	edi,eax
	movdqa	xmm7,xmm6
	paddd	xmm6,xmm2
	ror	ebx,7
	add	edi,esi
	pxor	xmm3,xmm5
	add	edx,DWORD PTR 52[esp]
	xor	ebp,ecx
	mov	esi,edi
	rol	edi,5
	movdqa	xmm5,xmm3
	movdqa	XMMWORD PTR 32[esp],xmm6
	xor	ebp,ebx
	add	edx,edi
	ror	eax,7
	add	edx,ebp
	pslld	xmm3,2
	add	ecx,DWORD PTR 56[esp]
	xor	esi,ebx
	psrld	xmm5,30
	mov	ebp,edx
	rol	edx,5
	xor	esi,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,esi
	por	xmm3,xmm5
	add	ebx,DWORD PTR 60[esp]
	xor	ebp,eax
	mov	esi,ecx
	rol	ecx,5
	xor	ebp,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,ebp
	add	eax,DWORD PTR [esp]
	paddd	xmm7,xmm3
	xor	esi,edi
	mov	ebp,ebx
	rol	ebx,5
	xor	esi,edx
	movdqa	XMMWORD PTR 48[esp],xmm7
	add	eax,ebx
	ror	ecx,7
	add	eax,esi
	add	edi,DWORD PTR 4[esp]
	xor	ebp,edx
	mov	esi,eax
	rol	eax,5
	xor	ebp,ecx
	add	edi,eax
	ror	ebx,7
	add	edi,ebp
	add	edx,DWORD PTR 8[esp]
	xor	esi,ecx
	mov	ebp,edi
	rol	edi,5
	xor	esi,ebx
	add	edx,edi
	ror	eax,7
	add	edx,esi
	add	ecx,DWORD PTR 12[esp]
	xor	ebp,ebx
	mov	esi,edx
	rol	edx,5
	xor	ebp,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,ebp
	mov	ebp,DWORD PTR 196[esp]
	cmp	ebp,DWORD PTR 200[esp]
	je	$L005done
	movdqa	xmm7,XMMWORD PTR 160[esp]
	movdqa	xmm6,XMMWORD PTR 176[esp]
	movdqu	xmm0,XMMWORD PTR [ebp]
	movdqu	xmm1,XMMWORD PTR 16[ebp]
	movdqu	xmm2,XMMWORD PTR 32[ebp]
	movdqu	xmm3,XMMWORD PTR 48[ebp]
	add	ebp,64
DB	102,15,56,0,198
	mov	DWORD PTR 196[esp],ebp
	movdqa	XMMWORD PTR 96[esp],xmm7
	add	ebx,DWORD PTR 16[esp]
	xor	esi,eax
DB	102,15,56,0,206
	mov	ebp,ecx
	rol	ecx,5
	paddd	xmm0,xmm7
	xor	esi,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,esi
	movdqa	XMMWORD PTR [esp],xmm0
	add	eax,DWORD PTR 20[esp]
	xor	ebp,edi
	psubd	xmm0,xmm7
	mov	esi,ebx
	rol	ebx,5
	xor	ebp,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,ebp
	add	edi,DWORD PTR 24[esp]
	xor	esi,edx
	mov	ebp,eax
	rol	eax,5
	xor	esi,ecx
	add	edi,eax
	ror	ebx,7
	add	edi,esi
	add	edx,DWORD PTR 28[esp]
	xor	ebp,ecx
	mov	esi,edi
	rol	edi,5
	xor	ebp,ebx
	add	edx,edi
	ror	eax,7
	add	edx,ebp
	add	ecx,DWORD PTR 32[esp]
	xor	esi,ebx
DB	102,15,56,0,214
	mov	ebp,edx
	rol	edx,5
	paddd	xmm1,xmm7
	xor	esi,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,esi
	movdqa	XMMWORD PTR 16[esp],xmm1
	add	ebx,DWORD PTR 36[esp]
	xor	ebp,eax
	psubd	xmm1,xmm7
	mov	esi,ecx
	rol	ecx,5
	xor	ebp,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,ebp
	add	eax,DWORD PTR 40[esp]
	xor	esi,edi
	mov	ebp,ebx
	rol	ebx,5
	xor	esi,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,esi
	add	edi,DWORD PTR 44[esp]
	xor	ebp,edx
	mov	esi,eax
	rol	eax,5
	xor	ebp,ecx
	add	edi,eax
	ror	ebx,7
	add	edi,ebp
	add	edx,DWORD PTR 48[esp]
	xor	esi,ecx
DB	102,15,56,0,222
	mov	ebp,edi
	rol	edi,5
	paddd	xmm2,xmm7
	xor	esi,ebx
	add	edx,edi
	ror	eax,7
	add	edx,esi
	movdqa	XMMWORD PTR 32[esp],xmm2
	add	ecx,DWORD PTR 52[esp]
	xor	ebp,ebx
	psubd	xmm2,xmm7
	mov	esi,edx
	rol	edx,5
	xor	ebp,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,ebp
	add	ebx,DWORD PTR 56[esp]
	xor	esi,eax
	mov	ebp,ecx
	rol	ecx,5
	xor	esi,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,esi
	add	eax,DWORD PTR 60[esp]
	xor	ebp,edi
	mov	esi,ebx
	rol	ebx,5
	xor	ebp,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,ebp
	mov	ebp,DWORD PTR 192[esp]
	add	eax,DWORD PTR [ebp]
	add	esi,DWORD PTR 4[ebp]
	add	ecx,DWORD PTR 8[ebp]
	mov	DWORD PTR [ebp],eax
	add	edx,DWORD PTR 12[ebp]
	mov	DWORD PTR 4[ebp],esi
	add	edi,DWORD PTR 16[ebp]
	mov	DWORD PTR 8[ebp],ecx
	mov	ebx,esi
	mov	DWORD PTR 12[ebp],edx
	mov	DWORD PTR 16[ebp],edi
	movdqa	xmm4,xmm1
	jmp	$L004loop
ALIGN	16
$L005done:
	add	ebx,DWORD PTR 16[esp]
	xor	esi,eax
	mov	ebp,ecx
	rol	ecx,5
	xor	esi,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,esi
	add	eax,DWORD PTR 20[esp]
	xor	ebp,edi
	mov	esi,ebx
	rol	ebx,5
	xor	ebp,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,ebp
	add	edi,DWORD PTR 24[esp]
	xor	esi,edx
	mov	ebp,eax
	rol	eax,5
	xor	esi,ecx
	add	edi,eax
	ror	ebx,7
	add	edi,esi
	add	edx,DWORD PTR 28[esp]
	xor	ebp,ecx
	mov	esi,edi
	rol	edi,5
	xor	ebp,ebx
	add	edx,edi
	ror	eax,7
	add	edx,ebp
	add	ecx,DWORD PTR 32[esp]
	xor	esi,ebx
	mov	ebp,edx
	rol	edx,5
	xor	esi,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,esi
	add	ebx,DWORD PTR 36[esp]
	xor	ebp,eax
	mov	esi,ecx
	rol	ecx,5
	xor	ebp,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,ebp
	add	eax,DWORD PTR 40[esp]
	xor	esi,edi
	mov	ebp,ebx
	rol	ebx,5
	xor	esi,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,esi
	add	edi,DWORD PTR 44[esp]
	xor	ebp,edx
	mov	esi,eax
	rol	eax,5
	xor	ebp,ecx
	add	edi,eax
	ror	ebx,7
	add	edi,ebp
	add	edx,DWORD PTR 48[esp]
	xor	esi,ecx
	mov	ebp,edi
	rol	edi,5
	xor	esi,ebx
	add	edx,edi
	ror	eax,7
	add	edx,esi
	add	ecx,DWORD PTR 52[esp]
	xor	ebp,ebx
	mov	esi,edx
	rol	edx,5
	xor	ebp,eax
	add	ecx,edx
	ror	edi,7
	add	ecx,ebp
	add	ebx,DWORD PTR 56[esp]
	xor	esi,eax
	mov	ebp,ecx
	rol	ecx,5
	xor	esi,edi
	add	ebx,ecx
	ror	edx,7
	add	ebx,esi
	add	eax,DWORD PTR 60[esp]
	xor	ebp,edi
	mov	esi,ebx
	rol	ebx,5
	xor	ebp,edx
	add	eax,ebx
	ror	ecx,7
	add	eax,ebp
	mov	ebp,DWORD PTR 192[esp]
	add	eax,DWORD PTR [ebp]
	mov	esp,DWORD PTR 204[esp]
	add	esi,DWORD PTR 4[ebp]
	add	ecx,DWORD PTR 8[ebp]
	mov	DWORD PTR [ebp],eax
	add	edx,DWORD PTR 12[ebp]
	mov	DWORD PTR 4[ebp],esi
	add	edi,DWORD PTR 16[ebp]
	mov	DWORD PTR 8[ebp],ecx
	mov	DWORD PTR 12[ebp],edx
	mov	DWORD PTR 16[ebp],edi
	pop	edi
	pop	esi
	pop	ebx
	pop	ebp
	ret
__sha1_block_data_order_ssse3 ENDP
ALIGN	64
$LK_XX_XX::
DD	1518500249,1518500249,1518500249,1518500249
DD	1859775393,1859775393,1859775393,1859775393
DD	2400959708,2400959708,2400959708,2400959708
DD	3395469782,3395469782,3395469782,3395469782
DD	66051,67438087,134810123,202182159
DB	83,72,65,49,32,98,108,111,99,107,32,116,114,97,110,115
DB	102,111,114,109,32,102,111,114,32,120,56,54,44,32,67,82
DB	89,80,84,79,71,65,77,83,32,98,121,32,60,97,112,112
DB	114,111,64,111,112,101,110,115,115,108,46,111,114,103,62,0
.text$	ENDS
.bss	SEGMENT 'BSS'
COMM	_OPENSSL_ia32cap_P:QWORD
.bss	ENDS
END
