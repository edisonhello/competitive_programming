#include <bits/stdc++.h>
using namespace std;

const int N = 10006;
const int M = 202;
const int INF = 1000000007;

int dp[N][M];

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef double ld;

#define F first
#define S second

int qL,qR;

vector<piii> G[N];

bool found = false;

ld ans = 0.0;

void dfs(int now,int par)
{
    int son = 0;
    for (piii p:G[now])
    {
        if (p.F != par) dfs(p.F,now),++son;
    }
    dp[now][0] = 0;
    if (son == 0)
    {
        return;
    }
    for (piii p:G[now])
    {
        if (p.F != par)
        {
            int l = p.S.F;
            int w = p.S.S;
            vector<pii> v;
            for (int j=0;qR-l>=j;j++)
            {
                if (dp[p.F][j] < 0) continue;
                int tot = j+l;
                int neww = dp[p.F][j] + w;
                v.push_back(make_pair(tot,neww));
                //cout << "p.F = " << p.F <<" , j = " << tot << " , nnew = " << neww <<endl;
                /*for (int k=qR;k>=tot;k--)
                {
                    if (dp[now][k-tot] >= 0) dp[now][k] = max(dp[now][k],dp[now][k-tot] + neww);
                }*/
                //dp[now][j + l] = max(dp[now][j+l],dp[p.F][j] + w);
            }
            for (int j=qR;j>=0;j--)
            {
                for (pii p:v)
                {
                    if (j - p.F < 0) break;
                    int k=j;
                    dp[now][k] = max(dp[now][k],dp[now][k-p.F] + p.S);
                }
            }
        }
    }
    /*
    for (int i=0;M>i;i++)
    {
        cout << "dp[" << now << "][" << i << "] = " << dp[now][i] << endl;
    }
    */

    for (int i=qL;qR>=i;i++)
    {
        if (dp[now][i] < 0) continue;
        found = true;
        ans = max(ans,dp[now][i] * 1.0 / i);
    }
}

int main ()
{
    int n;
    scanf("%d %d %d",&n,&qL,&qR);
    for (int i=0;N>i;i++)
    {
        for (int j=0;M>j;j++)
        {
            dp[i][j] = -INF;
        }
    }
    for (int i=1;n>i;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        //++b;
        //++a;
        G[a].push_back({ b,{ c,d } });
        G[b].push_back({ a,{ c,d } });
    }
    dfs(1,1);
    if (!found) cout << -1 << endl;
    else cout << fixed << setprecision(12) << ans << endl;
}
