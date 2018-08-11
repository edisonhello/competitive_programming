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

int main ()
{
    LL n,k;
    scanf("%lld %lld",&n,&k);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for (int i=1;n>=i;i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    for (int i=1;n>=i;i++)
    {
        if (i < k)
        {
            dp[i] = INF;
            determine[i] = 0;
        }
        else
        {
            dp[i] = INF;
            for (int j=0;i-k>=j;j++)
            {
                LL ret = dp[j] + cal(j+1,i);
                if (ret < dp[i])
                {
                    dp[i] = ret;
                    determine[i] = j;
                }
                //dp[i] = min(dp[i],dp[j] + cal(j+1,i));
            }
        }
    }
    //check determine monocone
    for (int i=1;n>=i;i++)
    {
        cout << "i = "<<i<<" , deter = "<<determine[i] << endl;
        //assert(determine[i-1] <= determine[i]);
    }
    printf("%lld\n",dp[n]);
}
