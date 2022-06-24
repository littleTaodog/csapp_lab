	.file	"control.c"
	.text
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	cmpq	%rsi, %rdi
	jle	.L2
	subq	%rsi, %rax
	ret
.L2:
	subq	%rdi, %rsi
	movq	%rsi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	absdiff, .-absdiff
	.globl	absdiff_j
	.type	absdiff_j, @function
absdiff_j:
.LFB1:
	.cfi_startproc
	endbr64
	movq	%rsi, %rax
	cmpq	%rsi, %rdi
	jg	.L5
	subq	%rdi, %rax
	ret
.L5:
	subq	%rsi, %rdi
	movq	%rdi, %rax
.L6:
	endbr64
	ret
	.cfi_endproc
.LFE1:
	.size	absdiff_j, .-absdiff_j
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB2:
	.cfi_startproc
	endbr64
	movq	%rdx, %rcx
	cmpq	$3, %rdi
	je	.L14
	jg	.L9
	cmpq	$1, %rdi
	je	.L10
	cmpq	$2, %rdi
	jne	.L17
	movq	%rsi, %rax
	cqto
	idivq	%rcx
	jmp	.L8
.L17:
	movl	$2, %eax
	ret
.L9:
	subq	$5, %rdi
	cmpq	$1, %rdi
	ja	.L18
	movl	$1, %eax
	subq	%rdx, %rax
	ret
.L10:
	movq	%rdx, %rax
	imulq	%rsi, %rax
	ret
.L14:
	movl	$1, %eax
.L8:
	addq	%rcx, %rax
	ret
.L18:
	movl	$2, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	switch_eg, .-switch_eg
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
