#include <iostream>

using namespace std;

int f (int, int)
{
    _asm
    {
        PUSH EBP
        MOV EBP, ESP
        SUB ESP, x

        MOV ESP, EBP
        POP EBP
        RET
    }
}

int main()
{
    int r;
    _asm
    {
        PUSH 3
        PUSH 2
        CALL f
        ADD ESP, 8
        EBP+8, +12, +16 sunt primii parametri
    }
    //r = f(2, 3);
}
