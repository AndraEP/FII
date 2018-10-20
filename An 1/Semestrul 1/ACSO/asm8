#include <iostream>

using namespace std;

int f (int, int)
{
    _asm
    {
        RET
    }
}

int main()
{
    int m[10][10];
    ///m[i][j]=0;
    ///unsigned &m[0][0]+(i*c+j)*4
    _asm
    {
        LEA EDI, m
        MOV EBX, i
        MOV ECX, j
        //v1:
        IMUL EBX, 10
        ADD EBX, ECX
        MOV DWORD PTR [EDI+EBX*4], 0

        //v2 fara IMUL:
        /*MOV EAX, EBX
        MOV ESI, 10
        MUL ESI
        ADD EAX, ECX
        MOV DWORD PTR [EDI+EAX*4], 0*/
    }
    return 0;
    //r = f(2, 3);
}
