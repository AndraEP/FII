#include <iostream>
#include <cstring>

template <class T>
class Stack
{
    T s[100];
    unsigned int length = 0;
  public:
    void Push (T element)
    {
        s[++length] = element;
    }
    void Pop()
    {
        --length;
    }
    T Top()
    {
        return s[length];
    }
    void Afisare()
    {
        for (unsigned int i = 1; i <= length; ++i)
        {
            std::cout << s[i] << " ";
        }
    }
};

template <class T>
class Vector
{
    T v[100];
    unsigned int length = 0;
  public:
    void Insert (T element, unsigned int poz)
    {
        for (unsigned int i = length; i >= poz; --i)
        {
            v[i+1] = v[i];
        }
        v[poz] = element;
        ++length;
    }
    void Delete (unsigned int poz)
    {
        for (unsigned int i = poz; i < length; ++i)
        {
            v[i] = v[i+1];
        }
        --length;
    }
    void InsertAtEnd (T element)
    {
        v[++length] = element;
    }
    void Afisare()
    {
        for (unsigned int i = 1; i <= length; ++i)
        {
            std::cout << v[i] << " ";
        }
    }
    void Sortare()
    {
        for (unsigned int i = 1; i < length; ++i)
        {
            for (unsigned int j = i+1; j <= length; ++j)
            {
                if (v[i] > v[j])
                {
                    T aux;
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }
    }
};

template <>
void Vector<char*>::Sortare()
{
    for (unsigned int i = 1; i < length; ++i)
    {
        for (unsigned int j = i+1; j <= length; ++j)
        {
            if (strcmp (v[i], v[j]) > 0)
            {
                char* aux;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
