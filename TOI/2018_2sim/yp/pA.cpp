#include <bits/stdc++.h>
using namespace std;

const int N = 5006;
const int NN = 19;
const int INF = 0x3f3f3f3f;

int cost[N][N];
int dp[(1<<NN)][NN];

int main ()
{
    int n,m1,m2;
    scanf("%d %d %d",&n,&m1,&m2);
    for (int q=1;m1>=q;q++)
    {
        int ii,jj,kk;
        scanf("%d %d %d",&ii,&jj,&kk);
        for (int i=0;ii>=i;i++)
        {
            for (int j=jj;n>j;j++)
            {
                cost[i][j] += kk;
            }
        }
    }
    for (int q=1;m2>=q;q++)
    {
        int ii,jj,kk;
        scanf("%d %d %d",&ii,&jj,&kk);
        for (int i=ii;n>i;i++)
        {
            for (int j=0;jj>=j;j++)
            {
                cost[i][j] += kk;
            }
        }
    }
    memset(dp,INF,sizeof(dp));
    dp[1][0] = 0;
    for (int mask=2;(1<<n)>mask;mask++)
    {
        for (int j=0;n>j;j++)
        {
            if (((1<<j)&mask) == 0) continue;
            //dp[mask][j] = INF;
            for (int k=0;n>k;k++)
            {
                if (j == k) continue;
                if (((1<<k)&mask) == 0) continue;
                dp[mask][j] = min(dp[mask][j], dp[ (mask^(1<<j)) ][k] + cost[k][j]);
            }
        }
    }
    int ans = INF;
    for (int i=0;n>i;i++)
    {
        ans = min(ans,dp[(1<<n)-1][i] + cost[i][0]);
    }
    printf("%d\n",ans);
}
