#include <iostream>

using namespace std;

int main()
{
    int a=0;
    int r=0;
    while (a<=10)
    {
        r+=a;
        a++;
    }
    _asm
    {
        MOV ECX, 0 //LEA EAX, A ; MOV DWORD PTR [EAX], 0
        MOV EAX, 0
        _while:
        CMP ECX, 10
        JG gata
        //ADD nu merge pentru 2 mem-uri
        /*MOV EAX, r
        ADD EAX, a
        MOV r, EAX
        //SAU, un cod mai performant:
        MOV EAX, a
        ADD r, EAX
        //SAU, un cod si mai performant stocandu-l pe r ca si EAX cu MOV EAX, 0 la inceput si mutandu-l inapoi in r la final
        ADD EAX, a
        //SAU, si mai performant:*/
        ADD EAX, ECX
        INC ECX
        JMP _while
        gata: MOV r, EAX
    }
    cout << r;
    return 0;
}
