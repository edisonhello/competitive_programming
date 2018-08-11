#include <bits/stdc++.h>
using namespace std;

const int N = 1006;
//const int INF = (1<<20);
const int mod = 1000000007;

int dp[N][N];
int cnt[N][N];
int sz[N];

int G[N][N];

//vector<int> G[N];

int que[1006];

void kirino(int s)
{
    dp[s][s] = 1;
    cnt[s][s] = 1;
    int qe=0,qs=0;
    que[++qe] = s;
	while (qs != qe)
    {
        int t=que[++qs];
		for (int ii = 1;ii <= sz[t];++ii)
        {
            int i = G[t][ii];
			if (dp[s][i] == 0)
            {
                dp[s][i] = dp[s][t] + 1;
                cnt[s][i] = cnt[s][t];
                que[++qe] = i;
            }
            else if (dp[s][i] == dp[s][t] + 1)
            {
                cnt[s][i] += cnt[s][t];
                if (cnt[s][i] >= mod) cnt[s][i] -= mod;
				//cnt[s][i] %= mod;
            }
        }
    }
}

int get_int()
{
	char c;
}

int main (){

    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i <= m;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x][++sz[x]] = y;
        G[y][++sz[y]] = x;
    }
    for (int i=1; i <= n;++i)
    {
        kirino(i);
    }
    for (int i=1;i <= n;++i)
    {
        int ans=0;
        for (int j=1;j <= n;++j)
        {
            if (j == i) continue;
			for (int k=j+1;k <= n;++k)
            {
                if (k==i) continue;
                if (dp[i][j] + dp[i][k] == dp[j][k]+1)
                {
                    ans += (cnt[i][j] * 1LL * cnt[i][k] % mod);
                    if (ans >= mod) ans -= mod;
                }
            }
        }
        ans += ans;
        if (ans >= mod) ans -= mod;
        printf("%lld\n",ans);
    }
}
