#include <stdio.h>

//Calculati suma elementelor pare dintr-un vector.
int suma_pare_vector (int *, int )
{
 _asm
 {
	mov esi,[ebp+8]//v
	mov edx,[ebp+12]//nr
	xor ecx,ecx//index
	xor eax,eax//suma = 0
_while:
	cmp ecx,edx
	jz _final
	mov ebx, [esi]
	test ebx,1
	jnz _impar
	//par
	add eax,ebx
_impar:
	add esi,4
	inc ecx
	jmp _while
_final:

 }
}

void main()
{
 int v[5]={5,1,2,3,6};
 int *p=v;
 int s;

 _asm{
	push 5
	push p
	call suma_pare_vector
	add esp,8
	mov s, eax
 }

 printf("Suma: %d", s);
}
