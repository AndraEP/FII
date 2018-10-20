#include <stdio.h>
//Determinati numarul de vocale dintr-un sir de caractere
int lungime(char *)
{
 _asm{
	mov esi,[ebp+8]//sir
	xor eax,eax//nr vocale=0
_while:
	mov bl,[esi]
	cmp bl,0
	jz _gata
	//am extras o litera
	or bl,32//conversie litera mica
	cmp bl, 'a'
	jz vocala
	cmp bl, 'e'
	jz vocala
	cmp bl, 'i'
	jz vocala
	cmp bl, 'o'
	jz vocala
	cmp bl, 'u'
	jz vocala
	//consoala
	jmp _next_letter
vocala:
	inc eax
_next_letter:
	inc esi
	jmp _while
_gata:
 }
}

void main()
{
 char *sir="Numarul de vocale";
 int l;

 _asm{
	push sir
	call lungime
	add esp,4
	mov l,eax
 }

 printf("Numarul de vocale este: %d\n", l);
}
