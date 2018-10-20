#include <iostream>

using namespace std;

struct S
{
    int i;
    short s;
    char c;
};

short get_s (S*)
{
    _asm
    {
        MOV ESI, [EBP+8]
        MOV AX, [ESI+4]
    }
}

int main()
{
    S structura;
    structura.s = 10;
    cout << get_s(&structura);
}
