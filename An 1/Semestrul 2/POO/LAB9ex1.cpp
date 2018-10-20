//main

#include "MyClass.h"

int main()
{
    int n = 5;
    int v[5] = {1, 5, 3, 4, 2};
    Array <int> a (v, n);

    for (auto it : a)  cout << a[it] << " ";
    cout << endl;
    auto cmp1 = [] (const int &e1, const int &e2) -> int {if (e1 == e2) return 1; else if (e1 < e2) return -1; else return 1;};
    a.Sort (cmp1);
    for (auto it : a) cout << a[it] << " ";
    cout << endl;
    
    a (v, n);
    for (auto it : a) cout << a[it] << " ";
    cout << endl;
    Compare *cmp2 = new IntCompare;
    a.Sort(cmp2);
    for (auto it : a) cout << a[it] << " ";
    cout << endl;
    delete cmp2;

    auto it = a.GetBeginIterator();
    ++it;
    cout << *(it.GetElement());

    try
    {
        //cout << a[5];
        //int x = 6; a += x;
    }
    catch (exception& e)
    {
        cout << "Exceptie: " << e.what() << endl;
    }
}


//class

#include "MyClass.h"

const char* Exceptie1::what() const throw()
{
    return "Index-ul este in afara domeniului!";
}

const char* Exceptie2::what() const throw()
{
    return "Capacitatea nu este suficienta!";
}

int IntCompare::CompareElements (void* e1, void* e2)
{
    int aux1 = *(int*)e1, aux2 = *(int*)e2;
    if (aux1 == aux2) return 0;
    else if (aux1 < aux2) return -1;
    else return 1;
}

template <class T>
ArrayIterator<T>::ArrayIterator()
{
    Current = 0;
}

template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator ++ ()
{
    ++Current;
    return *this;
}

template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator -- ()
{
    --Current;
    return *this;
}

template <class T>
bool ArrayIterator<T>::operator = (ArrayIterator<T>& otherIterator)
{
    Current = otherIterator.Current;
    return 1;
}

template <class T>
bool ArrayIterator<T>::operator != (ArrayIterator<T> otherIterator)
{
    return Current != otherIterator.Current;
}

template <class T>
int ArrayIterator<T>::operator * ()
{
    return Current;
}

template <class T>
T* ArrayIterator<T>::GetElement()
{
    return ptr->List[Current];
}

template <class T>
Array<T>::Array()
{
    Capacity = 0;
    Size = 0;
}

template <class T>
Array<T>::~Array()
{
    if (Capacity > 0) delete[] List;
}

template <class T>
Array<T>::Array (int capacity)
{
    Capacity = capacity;
    List = new T* [Capacity];
    Size = 0;
}

template <class T>
Array<T>::Array (const Array<T> &otherArray)
{
    Capacity = otherArray.Capacity;
    List = new T* [otherArray.Capacity];
    Size = otherArray.Size;
    for (int i = 0; i < otherArray.Size; ++i)
    {
        List[i] = otherArray.List[i];
    }
}

template <class T>
Array<T>::Array (const int *v, const int n)
{
    Capacity = n;
    List = new T* [n];
    Size = n;
    for (int i = 0; i < n; ++i)
    {
        List[i] = (int*)&v[i];
    }
}

template <class T>
bool Array<T>::operator() (const int *v, const int n)
{
    Exceptie2 OutOfMemory;
    if (Capacity < n)
    {
        throw OutOfMemory;
        //this->~Array();
        //Capacity = n;
        //List = new T* [n];
    }
    Size = n;
    for (int i = 0; i < n; ++i)
    {
        List[i] = (int*)&v[i];
    }
    return 1;
}

template <class T>
T& Array<T>::operator [] (int index)
{
    Exceptie1 OutOfRange;
    if (index < 0 || index > Size - 1) throw OutOfRange;
    return *List[index];
}

template <class T>
const Array<T>& Array<T>::operator += (const T &newElem)
{
    Exceptie2 OutOfMemory;
    if (Capacity < Size + 1)
    {
        throw OutOfMemory;
    }
    List[++Size] = (int*)&newElem;
    return *this;
}

template <class T>
const Array<T>& Array<T>::Insert (int index, const T &newElem)
{
    Exceptie1 OutOfRange;
    Exceptie2 OutOfMemory;
    if (index < 0 || index > Size - 1) throw OutOfRange;
    if (Capacity < Size + 1) throw OutOfMemory;
    for (int i = Size - 1; i >= index; --i)
    {
        List[i+1] = List[i];
    }
    ++Size;
    List[index] = (int*)&newElem;
    return *this;
}

template <class T>
const Array<T>& Array<T>::Insert (int index, const Array<T> otherArray)
{
    Exceptie1 OutOfRange;
    Exceptie2 OutOfMemory;
    if (index < 0 || index > Size - 1) throw OutOfRange;
    if (Capacity < Size + otherArray.Size) throw OutOfMemory;
    for (int i = Size - 1; i >= index; --i)
    {
        List[i + otherArray.Size] = List[i];
    }
    Size += otherArray.Size;
    for (int i = 0; i < otherArray.Size; ++i)
    {
        List[index+i] = otherArray.List[i];
    }
    return *this;
}

template <class T>
const Array<T>& Array<T>::Delete (int index)
{
    Exceptie1 OutOfRange;
    if (index < 0 || index > Size - 1) throw OutOfRange;
    for (int i = index; i < Size; ++i)
    {
        List[i] = List[i+1];
    }
    --Size;
    return *this;
}

template <class T>
bool Array<T>::operator = (const Array<T> &otherArray)
{
    Exceptie2 OutOfMemory;
    if (Capacity < otherArray.Size)
    {
        throw OutOfMemory;
        //this->~Array();
        //Capacity = otherArray.Capacity;
        //List = new T* [otherArray.Capacity];
    }
    Size = otherArray.Size;
    for (int i = 0; i < otherArray.Size; ++i)
    {
        List[i] = otherArray.List[i];
    }
    return 1;
}

template <class T>
void Array<T>::Sort()
{
    for (int i = 0; i < Size - 1; ++i)
    {
        for (int j = i + 1; j < Size; ++j)
        {
            if (*List[i] > *List[j]) std::swap (List[i], List[j]);
        }
    }
}

template <class T>
void Array<T>::Sort (int (*compare) (const T&, const T&))
{
    for (int i = 0; i < Size - 1; ++i)
    {
        for (int j = i + 1; j < Size; ++j)
        {
            if (compare(*List[i], *List[j]) > 0) std::swap (List[i], List[j]);
        }
    }
}

template <class T>
void Array<T>::Sort (Compare *comparator)
{
    for (int i = 0; i < Size - 1; ++i)
    {
        for (int j = i + 1; j < Size; ++j)
        {
            if (comparator->CompareElements(List[i], List[j]) > 0) std::swap (List[i], List[j]);
        }
    }
}

template <class T>
int Array<T>::BinarySearch (const T& elem)
{
    int s = 0, d = Size - 1, m;
    while (s <= d)
    {
        m = (s + d) / 2;
        if (elem == *List[m]) return m;
        else if (elem < *List[m]) d = m - 1;
        else if (elem > *List[m]) s = m + 1;
    }
    return -1;
}

template <class T>
int Array<T>::BinarySearch (const T& elem, int (*compare) (const T&, const T&))
{
    int s = 0, d = Size - 1, m;
    while (s <= d)
    {
        m = (s + d) / 2;
        int tmp = compare (elem, *List[m]);
        if (tmp == 0) return m;
        else if (tmp < 0) d = m - 1;
        else if (tmp > 0) s = m + 1;
    }
    return -1;
}

template <class T>
int Array<T>::BinarySearch (const T& elem, Compare *comparator)
{
    int s = 0, d = Size - 1, m;
    while (s <= d)
    {
        m = (s + d) / 2;
        int tmp = comparator->CompareElements ((void*)&elem, List[m]);
        if (tmp == 0) return m;
        else if (tmp < 0) d = m - 1;
        else if (tmp > 0) s = m + 1;
    }
    return -1;
}

template <class T>
int Array<T>::Find (const T& elem) 
{
    for (int i = 0; i < Size; ++i)
    {
        if (*List[i] == elem) return i;
    }
    return -1;
}

template <class T>
int Array<T>::Find (const T& elem, int (*compare) (const T&, const T&))
{
    for (int i = 0; i < Size; ++i)
    {
        if (compare(*List[i], elem) == 0) return i;
    }
    return -1;
}

template <class T>
int Array<T>::Find (const T& elem, Compare *comparator)
{
    for (int i = 0; i < Size; ++i)
    {
        if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
    }
    return -1;
}

template <class T>
int Array<T>::GetSize()
{
    return Size;
}

template <class T>
int Array<T>::GetCapacity()
{
    return Capacity;
}

template <class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
    ArrayIterator<T> aux;
    aux.Current = 0;
    aux.ptr = this;
    return aux;
}

template <class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
    ArrayIterator<T> aux;
    aux.Current = Size;
    aux.ptr = this;
    return aux;
}

template <class T>
ArrayIterator<T> Array<T>::begin()
{
    return GetBeginIterator();
}

template <class T>
ArrayIterator<T> Array<T>::end()
{
    return GetEndIterator();
}

template class ArrayIterator <int>;
template class Array <int>;
