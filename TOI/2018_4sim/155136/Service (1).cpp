#include <bits/stdc++.h>
using namespace std;

typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,int> pdi;
const int N = 200006;

int u[N],v[N],l[N];
int p[N],r[N],d[N];

long long tot_weight = 0;

const ld eps = 1e-9;

bool vis[N]; 
ld dp[N];
ld from_u[N],from_v[N];

vector<pii> G[N];

int n,m,k;

bool check(ld s)
{
    for (int i=1;i <= n; ++i)
    {
        dp[i] = 0;
    }
    memset(vis,0,sizeof(vis));
    priority_queue<pdi> pq;
    for (int i=1;i <= m;++i)
    {
        from_u[i] = from_v[i] = 0;
    }
    for (int i=1;i <= k;++i)
    {
        dp[ p[i] ] = r[i] + s * d[i];
        if (dp[ p[i] ] >= tot_weight) return true;
        pq.push(make_pair( dp[ p[i] ]  , p[i]));
    }
    int i,from,to,id,len;
    while (!pq.empty())
    {
        pdi _ = pq.top();
        pq.pop();
        if (vis[_.second]) continue;
        i=_.second;
        vis[i] = true;
        for (pii p:G[i])
        {
            from = i;
            to = p.first;
            id = p.second;
            len = l[ id ];
            if (from == u[id]) from_u[id] = max(from_u[id],dp[i]);
            else from_v[id] = max(from_v[id],dp[i]);
            if (vis[to] && from_u[id] + from_v[id] +eps < l[id]) return false;
            else if (vis[to]) continue;
            if (dp[i] + eps >= len && dp[to] +eps < dp[i] - len)
            {
                dp[to] = dp[i] - len;
                pq.push(make_pair(dp[to],to));
            }
        }
    }
    for (int i=1;i <= m;++i)
    {
        if (from_u[i] + from_v[i] + eps < l[i]) return false;
    }
    return true;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n >> m >>k;
    tot_weight = 0;
    for (int i=1;i <= m;++i)
    {
        cin >> u[i] >> v[i] >> l[i];
        tot_weight += l[i];
        G[ u[i] ].push_back( make_pair( v[i] ,i) );
        G[ v[i] ].push_back( make_pair( u[i] ,i) );
    }
    for (int i=1;i <= k;++i)
    {
        cin >> p[i] >> r[i] >> d[i];
        if (!r[i] && !d[i])
        {
            --k;
            --i;
        }
    }
    if (!check(1e20))
    {
        cout << -1 << endl;
        return 0;
    }
    ld l=0,r = 1e16;
    int cnt=74;
    while (cnt--)
    {
        ld mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(12) << r << endl;
}
