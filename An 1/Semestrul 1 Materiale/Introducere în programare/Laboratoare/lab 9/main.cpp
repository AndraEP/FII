#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

//ex1

int f1 (int x[100], int n)
{
    int f=0;
    for (int i=1; i<=n; i++)
        f=f+i*x[i];
    return f;
}

int f2 (int x[100], int n)
{
    int f=0;
    for (int i=1; i<=n; i++)
        f=f+i*x[n+1-i];
    return 2*f;
}

int f3 (int x[100], int n)
{
    int f=x[1];
    for (int i=2; i<=n; i++)
        f=f+f*x[i];
    return f;
}

//ex2

int f4 (int x[100], int y[100], int n)
{
    int f=0;
    for (int i=1; i<=n; i++)
        if (x[i]<y[i])
            f=f+x[i];
        else
            f=f+y[i];
    return f;
}

int f5 (int x[100], int y[100], int n)
{
    int f=0;
    for (int i=1; i<=n; i++)
        f=f+x[i]/y[n+1-i];
    return f;
}

int f6 (int x[100], int y[100], int n)
{
    int f=0;
    for (int i=1; i<=n; i++)
    {
        int s=0;
        int a=x[i]+y[i];
        while (a>0)
        {
            s=s+a%10;
            a=a/10;
        }
        f=f+s;
    }

    return f;
}

//ex 3 similar cu 2
//ex4

void f7 (int x[100], int y[100], int z[100], int n)
{
    int f=0;
    for (int i=1; i<=n; i++)
        if (x[i]<y[i])
            z[i]=x[i];
        else
            z[i]=y[i];
    for (i=1; i<=n; i++)
        cout<<z[i];
}

void f8 (int x[100], int y[100], int z[100], int n)
{
    int f=0;
    for (int i=1; i<=n; i++)
        z[i]=cmmdc(x[i], y[n+1-1]);
    for (i=1; i<=n; i++)
        cout<<z[i];
}

int cmmdc(int a, int b)
{
	int r;
	while (b!=0)
	{  r=a%b;
	   a=b;
	   b=r;
	}
	return a;
}

int f9 (int x[100], int y[100], int z[100], int n)
{
    int a;
    for (int i=1; i<=n; i++)
        {a=x[i]+y[i];
        z[i]=a%10;}
    for (i=1; i<=n; i++)
        cout<<z[i];
}

//ex5

bool f10 (int x[100], int y[100], int z[100], int n)
{
    int contor=0, a;
    for (int i=1; i<=n; i++)
    {
        if (z[i]==x[i]*y[i])
            contor++;
    }
    if (contor==n)
        return true;
    else return false;
}

bool f11 (int x[100], int y[100], int z[100], int n)
{
    int contor=0, a;
    for (int i=1; i<=n; i++)
        {d=cmmmc(x[i]*2, y[n+1-i]*3);
        if (z[i]==d)
            contor++;}
    if (contor==n)
        return true;
    else return false;
}

int cmmmc(int a, int b)
{
	int p=a*b;
    while (a!=b)
    {
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }
    cmmmc=p/a;
    return cmmmc;
}

bool f12 (int x[100], int y[100], int z[100], int n)
{
    int contor=0, pc;
    for (int i=1; i<=n; i++)
    {
        pc=x[i]+y[i]*i;
        while (pc>9)
            pc=pc/10;
        if (z[i]==pc)
            contor++;
    }
    if (contor==n)
        return true;
    else return false;
}

//ex6

