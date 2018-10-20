#include "StackVector.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    Vector <int> vi;
    vi.InsertAtEnd (1);
    vi.InsertAtEnd (3);
    vi.Insert (2, 2);
    vi.Delete (1);
    vi.InsertAtEnd(1);
    vi.Sortare();

    Stack <Vector <int>> sti;
    sti.Push (vi);
    sti.Top().Afisare();
    sti.Pop();

    cout << endl;

    Vector <char*> vc;
    vc.InsertAtEnd ("string1");
    vc.InsertAtEnd ("string3");
    vc.Insert ("string2", 2);
    vc.Delete (1);
    vc.InsertAtEnd ("string1");
    vc.Sortare();

    Stack <Vector <char*>> stc;
    stc.Push (vc);
    stc.Top().Afisare();
    stc.Pop();
}
