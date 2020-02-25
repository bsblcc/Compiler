.section	.rodata
.global	main
string1:
	.string	"sddddd%d"



.type	main, @function
.text	
main:
	pushl	%ebp
	movl	%esp, %ebp



	movl	$2323, %eax




	movl	%eax, %esi
	movl	$string1, %edi

	call	printf




	leave	
	ret	
