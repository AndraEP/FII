#include <stdio.h>

//Calculul factorialului unui numar - recursiv

unsigned int fact_rec(unsigned int nr){
 _asm{
		mov esi, [ebp+8] //se pune nr in esi
		cmp esi, 2 		//comparare nr cu 2
		jnb apel_recursiv //Daca nr >= 2, se face saltul, altfel:
		mov eax, 1		// se returneaza 1
		jmp gata		//gata
apel_recursiv:
		dec esi			// nr-1
		push esi		
		call fact_rec
		add esp,4	//eax = fact(nr-1)
		mov esi, [ebp+8] // esi = nr
		mul esi //return fact(nr-1)*nr
gata:
 }
}

void main(){
 int nr,fact;
 printf("nr = ");
 scanf("%u",&nr);
 _asm{
	push nr
	call fact_rec
	add esp,4
	mov fact, eax
 }
 printf("%u! = %u",nr,fact);
}
