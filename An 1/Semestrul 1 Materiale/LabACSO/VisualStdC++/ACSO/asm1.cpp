#include <iostream>

using namespace std;

int main()
{
    short v[100];
    _asm
    {
        LEA ESI, v
        MOV WORD PTR [ESI], 0
    }
    cout << v[0];
    return 0;
}
/*
    _asm
    {
        mov eax, 0
        ADD [ESI], 2
        MOV [ESI], 2
        INC [ESI]
        XOR [ESI], 2
        NOT [ESI]
        + BYTE PTR
        + WORD PTR
        + DWORD PTR

        XOR AX, AX
        MOV [ESI], AX

        ROR rotate right reg/mem, imn/CL
        ROL rotate left reg/mem, imn/CL

        RCR rotate carry right
        RCL rotate carry left
    }
}
*/
