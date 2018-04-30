#include <bits/stdc++.h>
using namespace std;

typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,int> pdi;
const int N = 200006;

int u[N],v[N],l[N];
int p[N],r[N],d[N];

const ld eps = 1e-9;

//bool done[N];  //point done or not
bool vis[N];   //do or not
ld dp[N];  //now range
ld from_u[N],from_v[N];

vector<pii> G[N];  //{to,index}

int n,m,k;

bool check(ld s)
{
    for (int i=1;n>=i;++i)
    {
        //done[i] = false;
        dp[i] = 0;
        vis[i] = false;
    }
    priority_queue<pdi> pq;
    for (int i=1;m>=i;++i)
    {
        from_u[i] = from_v[i] = 0;
    }
    for (int i=1;k>=i;++i)
    {
        dp[ p[i] ] = r[i] + s * d[i];
        pq.push(make_pair( dp[ p[i] ]  , p[i]));
    }
    while (!pq.empty())
    {
        pdi _ = pq.top();
        pq.pop();
        //cout << "_ = " << _.first << " , i = " << _.second << " , dp = " << dp[ _.second ] << endl;
        if (vis[_.second]) continue;
        int i=_.second;
        vis[i] = true;
        for (pii p:G[i])
        {
            int from = i;
            int to = p.first;
            int id = p.second;
            ld len = l[ id ];
            if (from == u[id]) from_u[id] = max(from_u[id],dp[i]);
            else from_v[id] = max(from_v[id],dp[i]);
            if (vis[to]) continue;
            if (dp[i] + eps >= len && dp[to] +eps < dp[i] - len)
            {
                dp[to] = max(dp[to],dp[i] - len);
                pq.push(make_pair(dp[to],to));
            }
        }
    }
    for (int i=1;m>=i;++i)
    {
        if (from_u[i] + from_v[i] + eps < l[i]) return false;
    }
    return true;
}

//#define getchar_unlocked getchar

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

int main ()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cin >>n >> m >>k;
    clock();
    n = rit();
    m = rit();
    k = rit();
    for (int i=1;m>=i;++i)
    {
        u[i] = rit();
        v[i] = rit();
        l[i] = rit();
        //cin >> u[i] >> v[i] >> l[i];
        G[ u[i] ].push_back( make_pair( v[i] ,i) );
        G[ v[i] ].push_back( make_pair( u[i] ,i) );
    }
    for (int i=1;k>=i;++i)
    {
        p[i] = rit();
        r[i] = rit();
        d[i] = rit();
        //cin >> p[i] >> r[i] >> d[i];
    }
    if (!check(1e20))
    {
        cout << -1 << endl;
        return 0;
    }
    ld l=0,r = 1e16;
    int cnt=75;
    while (cnt--)
    {
        ld mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(12) << r << endl;
}
