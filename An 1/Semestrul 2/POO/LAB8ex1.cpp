#include <iostream>
#include <vector>
#include <functional>

template <class T>
void Sort (std::vector <T> &lista, int (*Compare) (T &e1, T &e2))
{
    for (unsigned int i = 0; i < lista.size() - 1; i++)
    {
        for (unsigned int j = i + 1; j < lista.size(); j++)
        {
            if (Compare (lista[i], lista[j])) std::swap (lista[i], lista[j]);
        }
    }
}

int main()
{
    int i, n, x;
    std::vector <int> v;
    std::cin >> n;
    for (i = 0; i < n; i++)
    {
        std::cin >> x;
        v.push_back (x);
    }
    auto cmp = [] (auto &e1, auto &e2) -> int {return e1 > e2;};
    Sort <int> (v, cmp);
    for (i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
    }
}
