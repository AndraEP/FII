#include "StrVector.h"
#include <cstdio>

using namespace std;

int main()
{
    StrVector v = {"Test", "for", "C++"};
    auto count = v.GetCount();
    auto it = v.GetIterator();
    for (auto index = 0; index < count; index++, it++)
    {
        printf("%s\n", *it);
    }
    for (auto element : v)
    {
        printf("%s\n", element);
    }
}
