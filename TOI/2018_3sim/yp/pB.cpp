#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

#define F first
#define S second

const int N = 1006;

pii p[N];
char clr[N];

LL id[N];

LL hhash(LL a,LL b,LL c,LL d)
{
    return a * 35465464 + b * 51321324 + c * 72834872 + d * 34234665;
}

set<LL> st;

pii operator-(const pii &p1,const pii &p2)
{
    return make_pair(p1.F - p2.F,p1.S - p2.S);
}

int cross(pii a,pii b)
{
    return (a.F - b.F) * (a.S - b.S);
}

int sgn(int x)
{
    if (x==0) return 0;
    else return x>0?1:-1;
}

int main ()
{
    int n;
    scanf("%d",&n);
    if (n == 4)
    {
        puts("1");
        return 0;
    }
    for (int i=1;n>=i;i++)
    {
        scanf("%d %d %d",&p[i].F,&p[i].S,&clr[i]);
        id[i] = ((rand()<<30)^rand());
    }
    for (int i=1;n>=i;i++)
    {
        for (int j=i+1;n>=j;j++)
        {
            //cut a line at p[i] --- p[j]
            vector<int> neg,_0,pos;
            for (int k=1;n>=k;k++)
            {
                if (k == i || k == j) _0.push_back(k);
                else if (sgn(cross(p[i] - p[k], p[j] - p[k]) ) == -1) neg.push_back(k);
                else pos.push_back(k);
            }
            //first case : _0 with all other
            for (int i2 : _0)
            {
                for (int j2:pos)
                {
                    for (int _=1;n>=_;_++)
                    {
                        clrs[ sgn( cross(p[i] - p[_], p[j] - p[_]) ) + 4 + sgn() ]
                    }
                }
            }
        }
    }
}
