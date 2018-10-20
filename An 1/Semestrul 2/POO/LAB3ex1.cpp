#include "BigNumber.h"
#include <bits/stdc++.h>

BigNumber::BigNumber()
{
    memset (Number, 0, sizeof(Number));
    CharactersCount = 1;
    Number[1] = 0;
}

BigNumber::BigNumber (int value)
{
    memset (Number, 0, sizeof(Number));
    if (value)
    {
        CharactersCount = 0;
        while (value)
        {
            Number[++CharactersCount] = value%10;
            value /= 10;
        }
    }
    else
    {
        CharactersCount = 1;
        Number[1] = 0;
    }
}

BigNumber::BigNumber (const char *number)
{
    memset (Number, 0, sizeof(Number));
    CharactersCount = strlen(number);
    for (unsigned int i = 0; i < CharactersCount; ++i)
    {
        Number[CharactersCount-i] = number[i] - '0';
    }
}

BigNumber::BigNumber (const BigNumber &number)
{
    memset (Number, 0, sizeof(Number));
    CharactersCount = number.CharactersCount;
    memcpy (Number, number.Number, sizeof(number));
}

bool BigNumber::Set (int value)
{
    if (value < 0) return 0;
    if (value)
    {
        CharactersCount = 0;
        while (value)
        {
            Number[++CharactersCount] = value%10;
            value /= 10;
        }
    }
    else
    {
        CharactersCount = 1;
        Number[1] = 0;
    }
    return 1;
}

bool BigNumber::Set (const char *number)
{
    if (number[0] == '-') return 0;
    CharactersCount = strlen(number);
    for (unsigned int i = 0; i < CharactersCount; ++i)
    {
        Number[CharactersCount-i] = number[i] - '0';
    }
    return 1;
}

BigNumber BigNumber::operator + (const BigNumber &number)
{
    BigNumber A (*this);
    BigNumber B (number);
    A.CharactersCount = std::max (A.CharactersCount, B.CharactersCount);
    unsigned int T = 0;
    for (unsigned int i = 1; i <= A.CharactersCount; ++i)
    {
        A.Number[i] += B.Number[i] + T;
        T = A.Number[i] / 10;
        A.Number[i] %= 10;
    }
    if (T)
    {
        A.Number[++A.CharactersCount] = T;
    }
    return A;
}

BigNumber BigNumber::operator * (const BigNumber &number)
{
    BigNumber A (*this);
    BigNumber B (number);
    BigNumber C;
    if ((A.CharactersCount == 1 && A.Number[1] == 0) || (B.CharactersCount == 1 && B.Number[1] == 0))
    {
        C.CharactersCount = 1;
        C.Number[1] = 0;
        return C;
    }
    C.CharactersCount = A.CharactersCount + B.CharactersCount;
    unsigned int it_A = 0, it_B, sum, carry;
    for (unsigned int i = 1; i <= A.CharactersCount; ++i)
    {
        carry = 0;
        it_B = 1;
        for (unsigned int j = 1; j <= B.CharactersCount; ++j)
        {
            sum = A.Number[i]*B.Number[j] + C.Number[it_A + it_B] + carry;
            carry = sum / 10;
            C.Number[it_A + it_B] = sum % 10;
            ++it_B;
        }
        if (carry > 0)
        {
            C.Number[it_A + it_B] += carry;
        }
        ++it_A;
    }
    while (C.CharactersCount>=1 && C.Number[C.CharactersCount] == 0)
    {
        C.CharactersCount--;
    }
    return C;
}

BigNumber BigNumber::operator - (const BigNumber &number)
{
    BigNumber A (*this);
    BigNumber B (number);
    if (A < B) return 0;
    unsigned int T = 0;
    for (unsigned int i = 1; i <= A.CharactersCount; ++i)
    {
        A.Number[i] -= B.Number[i] + T;
        if (A.Number[i] < 0) T = 1; else T = 0;
        if (T) A.Number[i] += 10;
    }
    while (A.Number[A.CharactersCount] == 0) A.CharactersCount--;
    return A;
}

BigNumber BigNumber::operator / (const BigNumber &number)
{
    BigNumber A (*this);
    BigNumber B (number);
    BigNumber C;
    BigNumber R;
    C.CharactersCount = A.CharactersCount;
    R.CharactersCount = 0;
    for (unsigned int i = A.CharactersCount; i>=1; --i)
    {
        R = R * BigNumber(10);
        R.CharactersCount++;
        R.Number[1] = A.Number[i];
        C.Number[i] = 0;
        while (R > B)
        {
            C.Number[i]++;
            R = R - B;
        }
        if (R == B)
        {
            C.Number[i]++;
            R=0;
        }
    }
    while (C.Number[C.CharactersCount] == 0 && C.CharactersCount > 1) C.CharactersCount--;
    return C;
}

bool operator == (const BigNumber &n1, const BigNumber &n2)
{
    if (n1.CharactersCount != n2.CharactersCount) return 0;
    for (unsigned int i = 1; i <= n1.CharactersCount; ++i)
    {
        if (n1.Number[i] != n2.Number[i]) return 0;
    }
    return 1;
}

bool operator != (const BigNumber &n1, const BigNumber &n2)
{
    if (n1.CharactersCount != n2.CharactersCount) return 1;
    for (unsigned int i = 1; i <= n1.CharactersCount; ++i)
    {
        if (n1.Number[i] != n2.Number[i]) return 1;
    }
    return 0;
}

bool operator < (const BigNumber &n1, const BigNumber &n2)
{
    if (n1.CharactersCount < n2.CharactersCount) return 1;
    if (n1.CharactersCount > n2.CharactersCount) return 0;
    for (unsigned int i = 1; i <= n1.CharactersCount; ++i)
    {
        if (n1.Number[i] < n2.Number[i]) return 1;
        if (n1.Number[i] > n2.Number[i]) return 0;
    }
    return 0;
}

bool operator > (const BigNumber &n1, const BigNumber &n2)
{
    if (n1.CharactersCount > n2.CharactersCount) return 1;
    if (n1.CharactersCount < n2.CharactersCount) return 0;
    for (unsigned int i = 1; i <= n1.CharactersCount; ++i)
    {
        if (n1.Number[i] > n2.Number[i]) return 1;
        if (n1.Number[i] < n2.Number[i]) return 0;
    }
    return 0;
}

bool operator >= (const BigNumber &n1, const BigNumber &n2)
{
    if (n1.CharactersCount > n2.CharactersCount) return 1;
    if (n1.CharactersCount < n2.CharactersCount) return 0;
    for (unsigned int i = 1; i <= n1.CharactersCount; ++i)
    {
        if (n1.Number[i] > n2.Number[i]) return 1;
        if (n1.Number[i] < n2.Number[i]) return 0;
    }
    return 1;
}

bool operator <= (const BigNumber &n1, const BigNumber &n2)
{
    if (n1.CharactersCount < n2.CharactersCount) return 1;
    if (n1.CharactersCount > n2.CharactersCount) return 0;
    for (unsigned int i = 1; i <= n1.CharactersCount; ++i)
    {
        if (n1.Number[i] < n2.Number[i]) return 1;
        if (n1.Number[i] > n2.Number[i]) return 0;
    }
    return 1;
}

BigNumber::operator int ()
{
    int result = 0;
    for (unsigned int i = CharactersCount; i >= 1; --i)
    {
        result *= 10;
        result += Number[i];
    }
    return result;
}

int BigNumber::operator [] (unsigned int index)
{
    if (index < 1 || index > CharactersCount) return 0;
    return Number[CharactersCount-index+1];
}

BigNumber BigNumber::operator () (unsigned int start, unsigned int end)
{
    if (start < 1 || start > CharactersCount || end < 1 || end > CharactersCount || start > end) return 0;
    BigNumber result;
    result.CharactersCount = end-start+1;
    for (unsigned int i = start, k = 1; i <= end; ++i, ++k)
    {
        result.Number[end-start+1-k+1] = Number[CharactersCount-i+1];
    }
    return result;
}
