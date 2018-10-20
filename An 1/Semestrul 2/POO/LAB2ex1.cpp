#include "MyString.h"

unsigned int MyString::strlen (const char *text)
{
    unsigned int i = 0;
    while (text[i] != 0) i++;
    return i;
}

void MyString::strcpy (char *dest, const char *src)
{
    unsigned int length = strlen (src);
    char *aux = new char[length+1];
    for (unsigned int i = 0; i < length; ++i) aux[i] = src[i];
    for (unsigned int i = 0; i < length; ++i) dest[i] = aux[i];
    dest[length] = 0;
    delete[] aux;
}

void MyString::strncpy (char *dest, const char *src, unsigned int length)
{ 
    if (length > strlen (src)) return;
    char *aux = new char[length+1];
    for (unsigned int i = 0; i < length; ++i) aux[i] = src[i];
    for (unsigned int i = 0; i < length; ++i) dest[i] = aux[i];
    delete[] aux;
}

void MyString::strcat (char *dest, const char *src)
{
    strcpy (dest + strlen (dest), src);
}

bool MyString::min (unsigned int a, unsigned int b)
{
    return (a<b)?a:b;
}

MyString::MyString()
{
    sir = new char[16];
    AllocatedSize = 16;
    Size = 0;
}

MyString::MyString (const char *text)
{
    unsigned int Len = strlen (text);
    sir = new char [Len+1];
    AllocatedSize = Len+1;
    strcpy (sir, text);
    Size = Len;
}

MyString::~MyString()
{
    delete[] sir;
}

unsigned int MyString::GetSize()
{
    return Size;
}

void MyString::Set (const char *text)
{
    unsigned int Len = strlen (text);
    if (Len+1 > AllocatedSize)
    {
        this->~MyString();
        sir = new char [Len+1];
        AllocatedSize = Len+1;
    }
    strcpy (sir, text);
    Size = Len;
}

void MyString::Set (MyString &m)
{
    if (m.Size+1 > AllocatedSize)
    {
        this->~MyString();
        sir = new char [m.Size+1];
        AllocatedSize = m.Size+1;
    }
    strcpy (sir, m.sir);
    Size = m.Size;
}

void MyString::Add (const char *text)
{
    unsigned int Len = strlen (text);
    if (Size+Len+1 > AllocatedSize)
    {
        char *aux = new char [Size+1];
        strcpy (aux, sir);
        this->~MyString();
        sir = new char [Size+Len+1];
        AllocatedSize = Size+Len+1;
        strcpy (sir, aux);
        delete[] aux;
    }
    strcat (sir, text);
    Size += Len;
}

void MyString::Add (MyString &m)
{
    if (Size+m.Size+1 > AllocatedSize)
    {
        char *aux = new char [Size+1];
        strcpy (aux, sir);
        this->~MyString();
        sir = new char [Size+m.Size+1];
        AllocatedSize = Size+m.Size+1;
        strcpy (sir, aux);
        delete[] aux;
    }
    strcat (sir, m.sir);
    Size += m.Size;
}

const char* MyString::GetText()
{
    return sir;
}

MyString* MyString::SubString (unsigned int start, unsigned int size)
{
    if (start+size > Size+1 || start < 1 || size < 1) return 0;
    char *aux = new char [size+1];
    strncpy (aux, sir+start-1, size); aux[size]=0;
    MyString *obj = new MyString (aux);
    delete[] aux;
    return obj;
}

bool MyString::Delete (unsigned int start, unsigned int size)
{
    if (start+size > Size+1 || start < 1 || size < 1) return 0;
    strcpy (sir+start-1, sir+start+size-1);
    Size -= size;
    return 1;
}

int MyString::Compare (const char *text)
{
    unsigned int Len = strlen (text);
    unsigned int End = min (Size, Len);
    for (unsigned int i=0; i<End; ++i)
    {
        if (sir[i] < text[i]) return -1;
        if (sir[i] > text[i]) return 1;
    }
    if (Size < Len) return -1;
    else if (Size > Len) return 1;
    else return 0;
}

int MyString::Compare (MyString &m)
{
    unsigned int End = min (Size, m.Size);
    for (unsigned int i=0; i<End; ++i)
    {
        if (sir[i] < m.sir[i]) return -1;
        if (sir[i] > m.sir[i]) return 1;
    }
    if (Size < m.Size) return -1;
    else if (Size > m.Size) return 1;
    else return 0;
}

char MyString::GetChar (unsigned int index)
{
    if (index < 1 || index > Size) return 0;
    return sir[index-1];
}

bool MyString::Insert (unsigned int index, const char *text)
{
    if (index < 1 || index > Size+1) return 0;
    unsigned int Len = strlen (text);
    if (Size+Len+1 > AllocatedSize)
    {
        char *aux = new char [Size+1];
        strcpy (aux, sir);
        this->~MyString();
        sir = new char [Size+Len+1];
        AllocatedSize = Size+Len+1;
        strcpy (sir, aux);
        delete[] aux;
    }
    strcpy (sir+index-1+Len, sir+index-1);
    strncpy (sir+index-1, text, Len);
    Size += Len;
    return 1;
}

bool MyString::Insert (unsigned int index, MyString &m)
{
    if (index < 1 || index > Size+1) return 0;
    if (Size+m.Size+1 > AllocatedSize)
    {
        char *aux = new char [Size+1];
        strcpy (aux, sir);
        this->~MyString();
        sir = new char [Size+m.Size+1];
        strcpy (sir, aux);
        delete[] aux;
    }
    strcpy (sir+index-1+m.Size, sir+index-1);
    strncpy (sir+index-1, m.sir, m.Size);
    Size += m.Size;
    return 1;

}

int MyString::Find (const char *text)
{
    unsigned int Len = strlen (text);
    for (unsigned int i=0; i<Size-Len+1; ++i)
    {
        bool ok = 1;
        for (unsigned int j=0; j<Len && ok; ++j)
        {
            if (sir[i+j] != text[j]) ok = 0;
        }
        if (ok) return i+1;
    }
    return -1;
}

int MyString::FindLast (const char *text)
{
    int LastPos = -1;
    unsigned int Len = strlen (text);
    for (unsigned int i=0; i<Size-Len+1; ++i)
    {
        bool ok = 1;
        for (unsigned int j=0; j<Len && ok; ++j)
        {
            if (sir[i+j] != text[j]) ok = 0;
        }
        if (ok) LastPos = i+1;
    }
    return LastPos;
}
