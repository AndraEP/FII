#include <stdio.h>

//interschimbati valorile variabilelor a si b
void swap (int *a, int *b)
{
 _asm{
	mov eax,[ebp+8]//&a
	mov ebx,[ebp+12]//&b
	mov ecx,[eax]//a
	mov edx,[ebx]//b
	mov [eax],edx
	mov [ebx],ecx
 }
}

void main()
{
 int a=2, b=3;
 swap(&a,&b);
 printf("%d %d", a, b);
}
