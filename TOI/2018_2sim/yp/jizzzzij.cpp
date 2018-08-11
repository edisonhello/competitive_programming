#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1006;
const int INF = (1<<20);
const LL mod = 1000000007;

int dp[N][N];
LL cnt[N][N];

vector<int> G[N];

void kirino(int s)
{
    memset(dp[s],-1,sizeof(dp[s]));
    dp[s][s] = 0;
    cnt[s][s] = 1;
    queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int t=que.front();
        que.pop();
        for (int i:G[t])
        {
            if (dp[s][i] == -1)
            {
                dp[s][i] = dp[s][t] + 1;
                cnt[s][i] = cnt[s][t];
                que.push(i);
            }
            else if (dp[s][i] == dp[s][t] + 1)
            {
                cnt[s][i] += cnt[s][t];
                cnt[s][i] %= mod;
            }
        }
    }
}

vector<int> depth[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i=1;n>=i;i++)
    {
        kirino(i);
    }
    for (int i=1;n>=i;i++)
    {
        LL ans=0;
        for (int j=1;n>=j;j++)
        {
            depth[j].clear();
        }
        for (int j=1;n>=j;j++)
        {
            depth[ dp[i][j] ].push_back(j);
        }
        for (int j=1;n>=j;j++)
        {
            for (int k=0;depth[j].size()>k;k++)
            {
                for (int l=k+1;depth[j].size()>l;ll++)
                {
                    if (dp[ depth[j][k] ][i] + dp[i][ depth[j][l] ] == dp[ depth[] ][k])
                    {
                        ans += cnt[j][i] * cnt[i][k];
                        ans %= mod;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
}
