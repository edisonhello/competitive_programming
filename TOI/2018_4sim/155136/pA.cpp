#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

int deg[N];
int dp[N];
vector<int> G[N];
int vis[N];

#define SZ(x) ((int)(x).size())

vector<int> on_cycle;

void dfs_cycle(int now)
{
    vis[now] = 2;
    on_cycle.push_back(now);
    for (int i:G[now])
    {
        if (!vis[i])
        {
            dfs_cycle(i);
        }
    }
}

#define getchar_unlocked getchar

int rit()
{
    int val=0;
    char c;
    do {
        c = getchar_unlocked();
    } while (c < '0' || c > '9');
    val += (c - '0');
    while(true) {
        c = getchar_unlocked();
        if (c < '0' || c > '9') break;
        val *= 10;
        val += (c - '0');
    }
    return val;
}

inline int val(int x,int mod)
{
    return (x%mod + mod)%mod;
}

int tree_son[N];

int main ()
{
    int n;
    //n = rit();
    scanf("%d",&n);
    assert(n >= 3);
    for (int i=1;n>=i;i++)
    {
        int x,y;
        //cin >> x >> y;
        //x = rit();
        //y = rit();
        scanf("%d %d",&x,&y);
        //cout << "x = " << x << " , y = " << y << endl;
        G[x].push_back(y);
        G[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    queue<int> que;
    for (int i=1;n>=i;i++)
    {
        //for (int j:G[i]) cout << "i = " << i << " , j = " << j <<endl;
        if (deg[i] == 1)
        {
            que.push(i);
            dp[i] = 1;
        }
    }
    int ans=0;
    while (!que.empty())
    {
        int t=que.front();
        que.pop();
        vis[t] = true;
        //cout << "t = " << t  << " , dp = " << dp[t] << endl;
        //calculate t as LCA
        int mx1=0,mx2=0;
        int sons = 0;
        //cout << "yee" << endl;
        vector<int> ___; ___.push_back(0); ___.push_back(0);
        for (int i:G[t])
        {
            //cout << "i =  " << i << endl;
            if (vis[i] == 1)
            {
                //cout << "i = " <<i << endl;
                sons++;
                ___.push_back(dp[i]);
                /*int val = dp[i];
                if (val > mx1)
                {
                    mx2 = mx1;
                    mx1 = val;
                }
                else if (val > mx2)
                {
                    mx2 = val;
                }*/
            }
        }
        sort(___.begin(),___.end());
        reverse(___.begin(),___.end());
        //cout << "mx1 = " << mx1 << " , mx2 = " << mx2 << " , sons = " << sons << " , ans = " << mx1 + mx2 + 1 + (sons >= 2 ? sons-2 : 0) + 1 << endl;
        //cout << "finish " << endl;
        ans = max(ans,___[0] + ___[1] + 1 + (sons >= 2 ? sons-2 : 0) + 1);
        for (int i:G[t])
        {
            if (vis[i]) continue;
            dp[i] = max(dp[i],dp[t] + 1 + SZ(G[i]) - 2);
            deg[i]--;
            tree_son[i] += (tree_son[t] + 1);
            if (deg[i] == 1) que.push(i);
        }
    }
    //cout << "before in cycle ans = " << ans << endl;
    for (int i=1;n>=i;i++)
    {
        if (!vis[i])
        {
            dfs_cycle(i);
        }
        if (vis[i] == 2)
        {
            int sons = 0;
            vector<int> ___; ___.push_back(0); ___.push_back(0);
            int t=i;
            for (int i:G[t])
            {
                //cout << "i =  " << i << endl;
                if (vis[i] == 1)
                {
                    //cout << "i = " <<i << endl;
                    sons++;
                    ___.push_back(dp[i]);
                    /*int val = dp[i];
                    if (val > mx1)
                    {
                        mx2 = mx1;
                        mx1 = val;
                    }
                    else if (val > mx2)
                    {
                        mx2 = val;
                    }*/
                }
            }
            sort(___.begin(),___.end());
            reverse(___.begin(),___.end());
            //cout << "mx1 = " << mx1 << " , mx2 = " << mx2 << " , sons = " << sons << " , ans = " << mx1 + mx2 + 1 + (sons >= 2 ? sons-2 : 0) + 1 << endl;
            //cout << "finish " << endl;
            ans = max(ans,___[0] + ___[1] + 1 + (sons >= 2 ? sons-2 : 0) + 1);
            if (dp[i]) --dp[i];
        }
    }
    int nn = SZ(on_cycle);
    /*cout << "nn = " <<nn << endl;
    for (int i=0;nn>i;i++)
    {
        cout << "on_cycle[" << i << "] = " << on_cycle[i] << " , dp = " << dp[ on_cycle[i] ] << endl;
    }*/
    for (int i=0;nn>i;i++)
    {
        //cout << "i = " << i << " , on_cycle = " << on_cycle[i] <<endl;
        for (int j = i+1;nn>j;j++)
        {
            //cout << "i = " <<i << " , j = " << j << endl;
            //i --> j
            int tmp_ans = dp[ on_cycle[i] ] + dp[ on_cycle[j] ];
            if (dp[ on_cycle[i] ]) --tmp_ans,assert(SZ(G[ on_cycle[i] ]) > 2);
            if (dp[ on_cycle[j] ]) --tmp_ans,assert(SZ(G[ on_cycle[j] ]) > 2);
            for (int k=i;j>=k;k++)
            {
                tmp_ans++;
                if (k != i && k != j) tmp_ans += SZ( G[ on_cycle[k] ] ) - 2;
            }
            //cout << "before yee tmp_ans = " << tmp_ans <<endl;
            if (val(i-1,nn) == j && val(j+1,nn) == i) ;
            else if (val(i-1,nn) == val(j+1,nn) ) tmp_ans++;
            else tmp_ans += 2;
            ans = max(ans,tmp_ans);
            //cout << "tmp_ans1 = " << tmp_ans << endl;
            //j --> i
            tmp_ans = dp[ on_cycle[i] ] + dp[ on_cycle[j] ];
            if (dp[ on_cycle[i] ]) --tmp_ans;
            if (dp[ on_cycle[j] ]) --tmp_ans;
            for (int k=j;k != i; k = val(k+1,nn))
            {
                tmp_ans++;
                if (k != i && k != j) tmp_ans += SZ( G[ on_cycle[k] ] )-2;
            }
            if (val(j-1,nn) == i && val(i+1,nn) == j) ;
            else if (val(j-1,nn) == val(i+1,nn)) tmp_ans++;
            else tmp_ans += 2;
            ans = max(ans,tmp_ans);
            //cout << "tmp_ans2 = " << tmp_ans <<endl;
        }
    }
    assert(ans <= n);
    printf("%d\n",ans);
}
