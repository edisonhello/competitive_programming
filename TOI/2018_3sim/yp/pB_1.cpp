#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

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

pii operator+(const pii &p1,const pii &p2)
{
    return make_pair(p1.F + p2.F,p1.S + p2.S);
}

pii operator*(const LL d,const pii &p1)
{
    return make_pair(p1.F * d,p1.S * d);
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

int idx(char c)
{
    if (c == 'B') return 0;
    else if (c == 'R') return 1;
    else if (c == 'Y') return 2;
    else if (c == 'W') return 3;
}

string sssssss = "BRYW";

LL ans=0;

#define SZ(x) ((int)(x).size())

int check1(pii p1,pii p2,pii q1,pii q2)
{
    if (sgn(cross(p1-q1,p1-q2) * cross(p1-q2,p2-q2) )== -1 && sgn(cross(q1-p1,q1-p2) * cross(q2-p1,q2-p2)) == -1 ) return 1;  //inter
    else if (sgn(cross(p1-q1,p1-q2) * cross(p1-q2,p2-q2) )== 0 || sgn(cross(q1-p1,q1-p2) * cross(q2-p1,q2-p2)) == 0) return 2; //on
    return 3;  //nothing
}

int n;

void dfs(int now)
{
    if (now == n+1)
    {
        //did checking
        /*vector<int> v[4];
        for (int i=1;n>=i;i++)
        {
            v[idx(clr[i])].push_back(i);
        }*/
        bool can=true;
        /*
        for (int clra = 0;4>clra;clra++)
        {
            for (int clrb=clra+1;4>clrb;clrb++)
            {
                if (SZ(v[clra]) < 2 || SZ(v[clrb]) < 2) continue;
                for (int i1=0;SZ(v[clra])>i1;i1++)
                {
                    for (int i2=i1+1;SZ(v[clra])>i2;i2++)
                    {
                        for (int j1=0;SZ(v[clrb])>j1;j1++)
                        {
                            for (int j2=j1+1;SZ(v[clrb])>j2;j2++)
                            {
                                can &= check(p[ v[clra][i1] ] , p[ v[clra][i2] ] , p[ v[clrb][j1] ] , p[ v[clrb][j2] ]);
                                if (!can) break;
                            }
                            if (!can) break;
                        }
                        if (!can) break;
                    }
                    if (!can) break;
                }
                if (!can) break;
            }
            if (!can) break;
        }
        */
        can = false;
        set<pii> ee;
        ee.insert({0,0});
        ee.insert({10000,0});
        ee.insert({0,10000});
        ee.insert({10000,10000});
        for (int i1=1;n>=i1;i1++)
        {
            for (int i2=i1+1;n>=i2;i2++)
            {
                for (int j1=1;n>=j1;j1++)
                {
                    for (int j2=j1+1;n>=j2;j2++)
                    {
                        if (i1 == j1 && i2 == j2)
                        {
                            continue;
                        }
                        pii p1 = p[i1], p2 = p[i2], q1 = p[j1],q2 = p[j2];
                        //if (ee.find(p1) != ee.end() && ee.find(p2) != ee.end() && ee.find(q1) != ee.end() && ee.find(q2) != ee.end()) continue;
                        p1 = p1 + (-10003)*(p2 - p1);
                        p2 = p1 + 10003*(p2 - p1);
                        q1 = q1 + (-10003) * (q2 - q1);
                        q2 = q1 + 10003*(q2 - q1);
                        bool tmp=true;
                        for (int i=1;n>=i;i++)
                        {
                            for (int j=i+1;n>=j;j++)
                            {
                                if (clr[i] == clr[j])
                                {
                                    if (check1(p1,p2,p[i],p[j]) == 1 || check1(q1,q2,p[i],p[j]) == 1) tmp = false;
                                }
                                else
                                {
                                    if (check1(p1,p2,p[i],p[j]) == 3 || check1(q1,q2,p[i],p[j]) == 3) tmp = false;
                                }
                            }
                        }
                        if (tmp)
                        {
                            cout << i1 << ' ' << i2 << ' ' << j1 << ' ' << j2 << endl;
                        }
                        can |= tmp;
                    }
                }
            }
        }
        if (can) ++ans;
        return;
    }
    if (clr[now] != 'W') dfs(now+1);
    else
    {
        for (char i :sssssss)
        {
            clr[now] = i;
            dfs(now+1);
        }
    }
}

int main ()
{
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        cin >>p[i].F >> p[i].S >> clr[i];
        //scanf("%d %d %d",&p[i].F,&p[i].S,&clr[i]);
    }
    dfs(1);
    printf("%lld\n",ans);
}
