#include <stdio.h>
#include <malloc.h>
//Construiti matricea unitate (1 pe diagonala, 0 in rest)
void matrice_unitate(int **, int )
{
        _asm{
                mov esi,[ebp+8]//mat
				mov edx,[ebp+12]//nr
				xor ecx,ecx//index
_while:
				cmp ecx,edx
				jz _finish
				mov edi,[esi]
				xor eax,eax//index in vectorul de int-uri
_while_2:
				cmp eax,ecx
				jz _finish_while_2
				mov dword ptr [edi],0
				inc eax
				add edi,4
				jmp _while_2
_finish_while_2:
				//suntem pe diagonala principala
				mov dword ptr [edi],1
				inc eax
				add edi,4
				//continuam pe linia curenta
_while_3:
				cmp eax,edx
				jz _finish_while_3
				mov dword ptr [edi],0
				inc eax
				add edi,4
				jmp _while_3
_finish_while_3:
				inc ecx
				add esi,4
				jmp _while
_finish:
        }
}

void main()
{
        int n=5,i;
        int **mat;
 mat = (int**)malloc(n*sizeof(int*));
        for(i=0;i<n;i++){
 mat[i] = (int*)malloc(n*sizeof(int));
        }

        _asm
        {
			push n
            push mat
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

