#include <stdio.h>
//Construiti matricea unitate (1 pe diagonala, 0 in rest)

void matrice_unitate(int *, int )
{
 _asm{
	mov esi, [ebp+8]//p
	mov ecx, [ebp+12]//n
	mov eax,ecx
	mul ecx// eax = n*n (numarul de elemente din matrice)
	mov edx,eax//n*n
	//punem zero peste tot
	xor ecx, ecx
_while_zero:
	cmp ecx,edx
	jz _gata
	mov dword ptr[esi],0
	inc ecx
	add esi,4
	jmp _while_zero
_gata:
	//acum punem 1 pe diagonala principala
	mov esi, [ebp+8]//p
	mov ecx, [ebp+12]//n
	lea edx,[4*ecx+4]//ofsetul intre doua elemente consecutive de pe diagonala principala
_while_unu:
	cmp ecx,0
	jz _finish
	dec ecx
	mov dword ptr [esi], 1
	add esi, edx//adresa urmatorului element de pe diagonala principala
	jmp _while_unu
_finish:
 }
}

void main()
{
 int n=5;
 int mat[5][5];
 int *p = mat[0];
 
 _asm
 {
	push n
	push p
	call matrice_unitate
	add esp,8
 }

 for(int i=0; i<n; i++)
 {
 for(int j=0; j<n; j++)
 printf("%d ", mat[i][j]);
 printf ("\n");
 }
}
