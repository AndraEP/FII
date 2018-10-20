#include <iostream>
#include <exception>

using namespace std;

class Exceptie1 : public exception
{
	virtual const char* what() const throw();};

class Exceptie2 : public exception
{
    virtual const char* what() const throw();
};

class Compare
{
  public:
    virtual int CompareElements (void* e1, void* e2) = 0;
    virtual ~Compare() {};
};

class IntCompare : public Compare
{
    int CompareElements (void* e1, void* e2);
};

template <class T>
class Array;

template <class T>
class ArrayIterator
{
  public: //private:
    int Current; //mai adaugati si alte date si functii necesare pentru iterator
    Array<T>* ptr;
  public:
    ArrayIterator();
    ArrayIterator<T>& operator ++ ();
    ArrayIterator<T>& operator -- ();
    bool operator = (ArrayIterator<T>& otherIterator);
    bool operator != (ArrayIterator<T> otherIterator);
    int operator * ();
    T* GetElement();
};

template <class T>
class Array
{
  public: //private:
    T** List; //lista cu pointeri la obiecte de tipul T*
    int Capacity; //dimensiunea listei de pointeri
    int Size; //cate elemente sunt in lista
  public:
    Array(); //Lista nu e alocata, Capacity si Size = 0
    ~Array(); //destructor
    Array (int capacity); //Lista e alocata cu 'capacity' elemente
    Array (const Array<T> &otherArray); //constructor de copiere
    Array (const int *v, const int n); //constructor de copiere utilizabil
    bool operator () (const int *v, const int n);
    T& operator[] (int index); //arunca exceptie daca index este out of range
    const Array<T>& operator += (const T &newElem); //adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert (int index, const T &newElem); //adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert (int index, const Array<T> otherArray); //adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete (int index); //sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    bool operator = (const Array<T> &otherArray);
    void Sort(); //sorteaza folosind comparatia intre elementele din T
    void Sort (int (*compare) (const T&, const T&)); //sorteaza folosind o functie de comparatie
    void Sort (Compare *comparator); //sorteaza folosind un obiect de comparatie
                                     //functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch (const T& elem); //cauta un element folosind binary search in Array
    int BinarySearch (const T& elem, int (*compare) (const T&, const T&)); //cauta un element folosind binary search si o functie de comparatie
    int BinarySearch (const T& elem, Compare *comparator); //cauta un element folosind binary search si un comparator
    int Find (const T& elem); //cauta un element in Array
    int Find (const T& elem, int (*compare) (const T&, const T&)); //cauta un element folosind o functie de comparatie
    int Find (const T& elem, Compare *comparator); //cauta un element folosind un comparator
    int GetSize(); 
    int GetCapacity();
    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
    ArrayIterator<T> begin();
    ArrayIterator<T> end();
};
