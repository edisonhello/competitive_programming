#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 300006;
const LL INF = (1LL << 60) + 880301;

LL dp[N];
LL a[N];

LL pre[N];

int determine[N];

LL cal(int j,int i)
{
    int mid = (j + i) >> 1;
    return (pre[i] - pre[mid] - (i - mid)*a[mid]) + ( a[mid]*(mid - j + 1) - (pre[mid] - pre[j-1]));
}

LL n;
int k;

void update(int id,LL val,int deter)
{
    //cout << "id = "<<id<<" , val = "<<val<<" , deter = "<<deter<<endl;
    if (dp[id] > val)
    {
        dp[id] = val;
        determine[id] = deter;
    }
}

int solve(int L,int R,int deter_L,int deter_R)
{
    //cout << "L = "<<L<<" , R = "<<R<<" , deter_L = "<<deter_L<<" , deter_R = "<<deter_R<<endl;
    if (L == R)
    {
        for (int i = deter_L;min(deter_R,L-k)>=i;i++)
        {
            update(L,dp[i] + cal(i+1,L),i);
        }
        return determine[L];
    }
    int mid = (L+R) >> 1;
    int ret = solve(L,mid,deter_L,deter_R);
    solve(mid+1,R,ret,deter_R);
}

int main ()
{
    //LL n,k;
    scanf("%lld %d",&n,&k);
    dp[0] = 0;
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
        dp[i] = INF;
    }
    sort(a+1,a+n+1);
    for (int i=1;n>=i;i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    solve(k,n,0,n);
    printf("%lld\n",dp[n]);
}
