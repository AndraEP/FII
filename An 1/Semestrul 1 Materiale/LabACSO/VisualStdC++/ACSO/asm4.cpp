#include <iostream>

using namespace std;

int main()
{
    /*short s=0;
    int r=0;
    do
    {
        r+=s;
        s++;
    } while (s<10);
    cout << r;*/
    short s;
    int r;
    _asm
    {
        XOR EAX, EAX //r
        XOR ECX, ECX //s
        _do:
            /*MOVSX ECX, CX
            ADD EAX, ECX cam prost, in conditiile in care aveam sus XOR CX, CX*/
            ADD EAX, ECX
            INC ECX
            CMP ECX, 10
            JL _do
        MOV r, EAX;
    }
    cout << r;
    return 0;
}
/*ca sa nu pierdem flaguri:
PUSH FD
---
---
POP FD
*/
