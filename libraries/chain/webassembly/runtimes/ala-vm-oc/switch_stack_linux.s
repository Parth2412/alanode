.file	"switch_stack_linux.s"
.text
.globl	alavmoc_switch_stack
.type	alavmoc_switch_stack, @function
alavmoc_switch_stack:
   movq %rsp, -16(%rdi)
   leaq -16(%rdi), %rsp
   movq %rdx, %rdi
   callq *%rsi
   mov (%rsp), %rsp
   retq
.size	alavmoc_switch_stack, .-alavmoc_switch_stack
.section	.note.GNU-stack,"",@progbits
