#include "MyClass.h"
#include <iostream>

int main()
{
    Friend b; b.Name = "andrei";
    Agenda a; a.Add (&b);
    cout << a.SearchByName("andrei")->Name << endl;
    a.Delete ("andrei");
    a.Add (&b);
    list <Friend> l = a.Friends();
    for (auto it : l)
    {
        cout << it.Name << endl;
    }
}
