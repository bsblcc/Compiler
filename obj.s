.section	.rodata
string1:
	.string "%ld"
.global	main
.type	main, @function
.text	
main:
	pushq	%rbp
	movq	%rsp, %rbp
BB1:
	leaq	-32(%rbp), %rbx
	movq	%rbx, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	$1, 0(%rsi)
	movq	-40(%rbp), %rdi
	movq	$10, 8(%rdi)
	movq	-40(%rbp), %r8
	movq	$1, 16(%r8)
	jmp	BB3
BB2:
	leave	
	ret	
BB3:
	movq	-40(%rbp), %rbx
	movq	-40(%rbp), %rsi
	xor	%r15, %r15
	movq	8(%rsi), %r15
	cmpq	0(%rbx), %r15
	setne	%r15b
	movzbq	%r15b, %rdi
	cmpq	$1, %rdi
	je	BB4
	jmp	BB5
BB4:
	movq	-40(%rbp), %rbx
	movq	-40(%rbp), %rsi
	movq	0(%rbx), %rdi
	imul	16(%rsi), %rdi
	movq	-40(%rbp), %r8
	movq	%rdi, 16(%r8)
	movq	-40(%rbp), %r9
	movq	0(%r9), %r10
	addq	$1, %r10
	movq	-40(%rbp), %r11
	movq	%r10, 0(%r11)
	jmp	BB3
BB5:
	movq	-40(%rbp), %rbx
	movq	16(%rbx), %rsi
	movq	$string1, %rdi
	call	printf
	movq	$0, %rax
	jmp	BB2
