#include <iostream>

using namespace std;

const int L = 10;
const int C = 10;
int i=0, j=0;

int f (int[][C])
{
    _asm
    {
        MOV EDI, [EBP+8] //m
        MOV EDX, i //i
        MOV ECX, j //j
        IMUL EBX, C //c
        ADD EBX, ECX
        MOV DWORD PTR [EDI+4*EBX], 0
    }
}

int main()
{
    //int m[L][C];
    int **m;
    m = (int**)malloc(L*4);
    for (int i=0; i<L; i++)
    {
        m[i] = (int*)malloc(C*4);
    }
    ///*(m+1)=...
    _asm
    {
        LEA EDI, m
        MOV EBX, i
        MOV ECX, j
        MOV ESI, [EDI+4*EBX] //adresa primului element de pe linia i
        MOV DWORD PTR [ESI+4*ECX], 0 //adresa lui i, j
    }
    return 0;
}
