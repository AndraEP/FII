#include <iostream>

using namespace std;

int g (...)
{
    _asm
    {
        XOR EAX, EAX
        MOV EDI, [EBP+4]
        MOV AL, [EDI+2]
        SHR EAX, 2
    }
}

int main()
{
    cout << g(2, 3, 4, 5);
    return 0;
}
