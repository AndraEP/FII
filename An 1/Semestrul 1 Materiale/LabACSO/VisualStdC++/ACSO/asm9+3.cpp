#include <iostream>

using namespace std;

void f (...)
{
    _asm
    {
        MOV ESI, [EBP+8]
        MOV EDI, [EBP+12]
        MOV EBX, [ESI]
        MOV ECX, [EDI]
        MOV [EDI], EBX
        MOV [ESI], ECX
    }
}

int main()
{
    int a=2;
    int b=3;
    f (&a, &b);
    cout << a << b; //3, 2
    return 0;
}
