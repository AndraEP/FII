#include <iostream>

using namespace std;

//Paduraru Andra - Elena, anul 1, grupa A4
//exercitiul 1

int f1 (int x[100], int n)
{
    int f=0, i;
    for (i=1; i<=n; i++)
        f=f+i*x[i];
    return f;
}

int f2 (int x[100], int n)
{
    int f=0, i;
    for (i=1; i<=n; i++)
        f=f+i*x[n+1-i];
    return 2*f;
}

int f3 (int x[100], int n)
{
    int f=x[1], i;
    for (i=2; i<=n; i++)
        f=f+f*x[i];
    return f;
}

//exercitiul 2

int f4 (int x[100], int y[100], int n)
{
    int f=0, i;
    for (i=1; i<=n; i++)
    {
        if (x[i]<y[i])
            f=f+x[i];
        else
            f=f+y[i];
    }
    return f;
}

int f5 (int x[100], int y[100], int n)
{
    int f=0, i;
    for (i=1; i<=n; i++)
        f=f+x[i]/y[n+1-i];
    return f;
}

int f6 (int x[100], int y[100], int n)
{
    int f=0, i;
    for (i=1; i<=n; i++)
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

//exercitiul 3

void f7 (int x[100], int y[100], int z[100], int n)
{
    int i;
    for (i=1; i<=n; i++)
        if (x[i]<y[i])
            z[i]=x[i];
        else
            z[i]=y[i];
    for (i=1; i<=n; i++)
        cout<<z[i];
}

int cmmdc (int a, int b)
{
    int r;
	while (b!=0)
	{  r=a%b;
	   a=b;
	   b=r;
	}
	return a;
}

void f8(int x[100],int y[100] ,int z[100], int n)
{
    for(int i=1;i<=n;i++)
    {
        z[i]=cmmdc(x[i], y[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<z[i];
}

void f9 (int x[100], int y[100], int z[100], int n)
{
    int uc, i;
    for (i=1; i<=n; i++)
    {
        uc=x[i]+y[i];
        z[i]=uc%10;
    }
    for (i=1; i<=n; i++)
        cout<<z[i];
}

//exercitiul 4

bool f10 (int x[100], int y[100], int z[100], int n)
{
    int contor=0, i;
    for (i=1; i<=n; i++)
    {
        if (z[i]==x[i]*y[i])
            contor++;
    }
    if (contor==n)
        return true;
    else return false;
}

int cmmmc(int a, int b)
{
	int p=a*b, c;
    while (a!=b)
    {
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }
    c=p/a;
    return c;
}

bool f11 (int x[100], int y[100], int z[100], int n)
{
    int contor=0, d, i;
    for (i=1; i<=n; i++)
    {
        d=cmmmc(x[i]*2, y[n+1-i]*3);
        if (z[i]==d)
            contor++;
    }
    if (contor==n)
        return true;
    else return false;
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

//exercitiul 5

int f13 (int x[100], int n)
{
    int k=1;
    for (int i=1; i<n; i++)
        if (x[i]!=x[i+1])
            k=0;
    return k;
}

int f14 (int x[100], int n)
{
    int s=0, a, b, i;
    for(i=1;i<=n;i++)
    {
        a=x[i];
        b=x[n-i+1];
        while (a!=b)
            if (a>b)
                a=a-b;
            else
                b=b-a;
        if (a==1)
            s++;
    }
    return s;
}

int f15 (int x[100], int n)
{
    int contor=0;
    for (int i=1; i<=n; i++)
        if (x[i]==x[1])
            contor++;
    return contor;
}

//exercitiul 6

void f16 (int x[100], int n)
{
    int aux;
    for(int i=1; i<=n/2; i++)
    {
        aux=x[i];
        x[i]=x[n-i+1];
        x[n-i+1]=aux;
    }

    for(int i=1; i<=n; i++)
        cout<<x[i];
}

void f17 (int x[100], int n)
{
    int aux, i;
    for (i=1; i<n; i=i+2)
    {
        aux=x[i];
        x[i]=x[i+1];
        x[i+1]=aux;
    }
    for (i=1; i<=n; i++)
        cout<<x[i];
}

void f18 (int x[100], int n)
{
    int aux=x[1], i;
    for (i=1; i<n; i++)
        x[i]=x[i+1];
    x[n]=aux;
    for (i=1; i<=n; i++)
        cout<<x[i];
}

//exercitiul 7

void f19 (int x[100], int n)
{
    int aux=x[n], i;
    for (i=n; i>1; i--)
        x[i]=x[i-1];
    x[1]=aux;
    for (i=1; i<=n; i++)
        cout<<x[i];
}

void f20 (int x[100], int n)
{
    int i;
    for (i=2; i<=n; i=i+2)
        x[i]=0;
    for (i=1; i<=n; i++)
        cout<<x[i];
}

void f21 (int x[100], int n)
{
    int i;
    for (i=1; i<=n; i++)
        x[i]=i*x[i];
    for (i=1; i<=n; i++)
        cout<<x[i];
}

//exercitiul 8

void f22 (int x[100], int n)
{
    int i;
    for (i=2; i<=n; i=i+2)
        x[i]=-x[i];
    for (i=1; i<=n; i++)
        cout<<x[i];
}

void f23 (int x[100], int n)
{
    int i;
    for (i=1; i<=n; i=i+3)
        x[i]=0;
    for (i=1; i<=n; i++)
        cout<<x[i];
}

void f24 (int x[100], int n)
{
    int i;
    for (i=1; i<=n; i++)
        x[i]=(n+1-i)*x[i];
    for (i=1; i<=n; i++)
        cout<<x[i];
}

//exercitiul 9

int f25 (int x[100], int n)
{
    int contor=0;
    for (int i=2; i<n; i++)
    {
        if (x[i]==x[i-1]+x[i+1])
            contor++;
    }
    if (x[1]==x[2])
        contor++;
    if (x[n]==x[n-1])
        contor++;
    return contor;
}

int f26 (int x[100], int n)
{
    int contor=0, a, b;
    for(int i=1; i<n; i++)
    {
        a=x[i];
        b=x[i+1];
        while(a!=b)
            if(a>b)
                a=a-b;
            else
                b=b-a;
        if(a==1)
            contor++;
    }
    return contor;
}

int f27 (int x[100], int n)
{
    int contor=0;
    for (int i=3; i<=n; i=i+3)
        if (x[i]<0)
            contor++;
    return contor;
}

//exercitiul 10

int f28 (int x[100], int n)
{
    int contor=0, s=0;

    for(int i=1;i<=n;i++)
        s=s+x[i];
    s=s/n;
    for(int i=1;i<=n;i++)
        if(x[i]<s)
            contor++;
    return contor;
}

int f29 (int x[100], int n)
{
    int contor=0, nr, a, inv;
    for(int i=1; i<=n; i++)
    {
        nr=x[i];
        while(nr!=0)
        {
            a=nr%10;
            nr=nr/10;
            inv=inv*10+a;
        }
        if(x[i]==inv)
            contor++;
    }
    return contor;
}

int f30 (int x[100], int n)
{
    int contor=0;
    for(int i=1; i<=n; i=i+2)
        if((x[i]>=0)&&(x[i]%2==0))
            contor++;
    return contor;
}

int main()
{
    int x[100],y[100],z[100],n;

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i];

    cout<<"elem y"<<endl;
    for(int i=1;i<=n;i++)
        cin>>y[i];

    cout<<"f1= "<<f1(x,n)<<endl;
    cout<<"f2= "<<f2(x,n)<<endl;
    cout<<"f3= "<<f3(x,n)<<endl;

    cout<<"f4= "<<f4(x,y,n)<<endl;
    cout<<"f5= "<<f5(x,y,n)<<endl;
    cout<<"f6= "<<f6(x,y,n)<<endl;

    cout<<"f7=> "; f7(x,y,z,n);
    cout<<"f8=> "; f8(x,y,z,n);
    cout<<"f9=> "; f9(x,y,z,n);

    cout<<"f10=> "<<f10(x,y,z,n)<<endl;
    cout<<"f11=> "<<f11(x,y,z,n)<<endl;
    cout<<"f12=> "<<f12(x,y,z,n)<<endl;

    cout<<"k1= "<<f13(x,n)<<endl;
    cout<<"k2= "<<f13(x,n)<<endl;
    cout<<"k1= "<<f13(x,n)<<endl;

    cout<<"f16=> "; f16(x, n);
    cout<<"f17=> "; f17(x, n);
    cout<<"f18=> "; f18(x, n);

    cout<<"f19=> "; f19(x, n);
    cout<<"f20=> "; f20(x, n);
    cout<<"f21=> "; f21(x, n);

    cout<<"f22=> "; f22(x, n);
    cout<<"f23=> "; f23(x, n);
    cout<<"f24=> "; f24(x, n);

    cout<<"k4=  "<<f25(x, n)<<endl;
    cout<<"k5=  "<<f26(x, n)<<endl;
    cout<<"k6=  "<<f27(x, n)<<endl;

    cout<<"k7= "<<f28(x, n)<<endl;
    cout<<"k8= "<<f29(x, n)<<endl;
    cout<<"k9= "<<f30(x, n)<<endl;

    return 0;
}
