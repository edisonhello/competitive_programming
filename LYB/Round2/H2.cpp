/*input
4 6 3
1 2 3
2 3 4
3 4 5
1 2 6
2 3 7
3 4 8
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 220
#define INF 1000000000000000LL

struct N{ int from , to , cap , flow , cost; };
struct MCMF{
    int s , t;
    int a[MAX] , d[MAX] , p[MAX] , inq[MAX];
    vector<int> g[MAX];
    vector<N> e;
    int ADDE(int f , int t , int c , int cost){
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0 ,  cost});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0 , -cost});
    }
    int Bellmanford(int &flow , int &cost){
        MEM(inq , 0);
        REP(i , 0 , MAX) d[i] = INF;
        queue<int> qu;
        d[s] = 0 , a[s] = INF , qu.push(s);
        while(qu.size()){
            int now = qu.front(); qu.pop();
            inq[now] = 0;
            for(auto i : g[now]){
                N to = e[i];
                if(to.cap > to.flow && d[to.to] > d[now] + to.cost){
                    a[to.to] = min(a[now] , to.cap - to.flow);
                    d[to.to] = d[now] + to.cost;
                    p[to.to] = i;
                    if(inq[to.to] == 0){
                        inq[to.to] = 1;
                        qu.push(to.to);
                    }
                }
            }
        }
        if(d[t] == INF) return 0;
        flow += a[t];
        cost += a[t] * d[t];
        for(int i = t ; i != s ; i = e[p[i]].from){
            e[p[i] ^ 0].flow += a[t];
            e[p[i] ^ 1].flow -= a[t];
        }
        return 1;
    }
    PII FLOW(int s , int t){
        this -> s = s , this -> t = t;
        int flow = 0 , cost = 0;
        while(Bellmanford(flow , cost));
        return mp(flow , cost);
    }
} dc;
int n , m , k , x[MAX][3];

int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , m + 1) cin >> x[i][0] >> x[i][1] >> x[i][2];
    int s = n + 1, t = n + 2;
    dc.ADDE(s , 1 , k , 0);
    REP(i , 1 , m + 1) dc.ADDE(x[i][0] , x[i][1] , 1 , x[i][2]);
    dc.ADDE(n , t , k , 0);
    PII ans = dc.FLOW(s , t);
    if(ans.A != k) cout << -1 << endl;
    else cout << ans.B << endl;
    return 0;
}