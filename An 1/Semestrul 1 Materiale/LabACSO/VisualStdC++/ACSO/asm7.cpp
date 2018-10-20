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
    int v[10];
    _asm
    {
        LEA ESI, v
        ADD ESI, 4
        MOV DWORD PTR [ESI], 0
        //
        MOV ECX, 0
        //...
        MOV DWORD PTR [ESI+ECX*4], 0
    }
    return 0;
    //r = f(2, 3);
}
