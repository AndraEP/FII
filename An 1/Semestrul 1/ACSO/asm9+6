#include <iostream>

using namespace std;

void factorial(...)
{
    _asm
    {
        CDECL EAX, ECX, EDX// - CALLER SAVED

        PUSH EAX
        PUSH ECX
        PUSH EDX

        CALL factorial
        ADD ESP, ...
        MOV EBX, EAX

        POP EDX
        POP ECX
        POP EAX

        //sau

        SUB ESP, 4
        PUSH AD
        MOV [ESP+32], EAX
        POP AD
        POP EAX
    }
}

int main()
{

}
