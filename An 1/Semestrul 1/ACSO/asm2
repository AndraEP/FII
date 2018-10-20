#include <iostream>

using namespace std;

int main()
{
    int a;
    if (a>10)
    {
        a++;
    }
    else
    {
        a--;
    }
    _asm
    {
        CMP a, 10
        JLE _else
        INC a
        JMP dupa_if
        _else:
            DEC a
        dupa_if:
    }
    cout << a;
    return 0;
}
