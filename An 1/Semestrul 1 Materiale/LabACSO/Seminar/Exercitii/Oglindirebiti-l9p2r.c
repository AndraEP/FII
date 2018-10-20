#include <stdio.h>

//Sa se scrie codul in limbaj de asamblare care oglindeste bitii  unui numar

void main(){
	unsigned int number;
	number = 140;

	_asm{
		/* Completati */
		mov ebx, number
		xor eax,eax
		mov ecx,0
_loop:
		cmp ecx,32
		jz _done
		shl eax,1
		shr ebx,1
		jnc _next_bit
		or eax,1
_next_bit:
		inc ecx
		jmp _loop
_done:
		mov number, eax
	}
	if( number != 822083584)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
}
