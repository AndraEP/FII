#include <iostream>

using namespace std;

const int L = 10;
const int C = 10;

int f (int, int)
{
    _asm
    {
        RET
    }
}

int main()
{
    int i=0, j=0;
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
    //r = f(2, 3);
}
