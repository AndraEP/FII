#include <iostream>

using namespace std;

int f2 (int, int)
{
    _asm
    {

    }
}

int f (int a, int b)
{
    return a+b;
}

int main()
{
    int r;
    _asm
    {
        PUSH 3
        PUSH 2
        CALL f2
        ADD ESP, 8 //elimina de pe stiva var loc
        EBP+8, +12, +16 sunt primii parametri
    }
    //r = f(2, 3);
}
