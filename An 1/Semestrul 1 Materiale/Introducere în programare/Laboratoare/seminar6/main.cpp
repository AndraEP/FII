#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next, *pred;
} *prim, *ultim, *p, *q;

void citire (nod *&prim, nod *&ultim)
{
    int x, n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>x;
        if (prim==0)
        {
            prim=ultim=new nod;
            prim->info=x;
            prim->next=0;
        }
        else
        {
            nod *nou=new nod;
            nou->info=x;
            nou->next=0;
            ultim->next=nou;
            ultim=nou;
        }
    }
}

int palindrom (nod *p, nod *q)
{
    p=prim;
    q=ultim;
    while (p!=q && p->pred!=q)
    {
        if (p->next->info!=q->info)
            return 0;
        p=p->next;
        q=q->pred;
    }
    return 1;
}

int main()
{
    nod *prim=0, *ultim=0;
    citire (prim, ultim);
    cout<<palindrom (prim, ultim);
    return 0;
}
