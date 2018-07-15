/*input
3 2
1 2 3
1 4 1
2 3 2 3
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
#define MAX 5050
#define INF 1e15

struct djs{
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int a){ return Find(a); }
} ds;
struct N{ int from , to , cap , flow; };
struct dinic{
    int s , t , dep[MAX] , use[MAX] , res[MAX];
    vector<int> g[MAX];
    vector<N> e;
    void init(){
        REP(i , 0 , MAX) g[i].clear();
        e.clear();
    }
    int ADDE(int f , int t , int c){
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0});
        return e.size() - 2;
    }
    int BFS(){
        MEM(use , 0) , MEM(dep , 0);
        queue<int> qu;
        qu.push(s) , dep[s] = use[s] = 1;
        while(qu.size()){
            int now = qu.front(); qu.pop();
            for(auto i : g[now]){
                N to = e[i];
                if(use[to.to] == 0 && to.cap > to.flow){
                    use[to.to] = 1;
                    dep[to.to] = dep[now] + 1;
                    qu.push(to.to);
                }
            }
        }
        return use[t];
    }
    int DFS(int now , int lim){
        if(lim == 0 || now == t) return lim;
        int flow = 0 , tmp;
        for(int &i = res[now] ; i < g[now].size() ; i ++){
            N to = e[g[now][i]];
            if(dep[to.to] == dep[now] + 1){
                tmp = DFS(to.to , min(lim , to.cap - to.flow));
                if(tmp > 0){
                    e[g[now][i] ^ 0].flow += tmp;
                    e[g[now][i] ^ 1].flow -= tmp;
                    flow += tmp;
                    lim -= tmp;
                    if(lim == 0) break;
                }
            }
        }
        return flow;
    }
    int FLOW(int s , int t){
        this -> s = s , this -> t = t;
        int flow = 0;
        while(BFS()){
            MEM(res , 0);
            flow += DFS(s , INF);
        }
        for(auto to : e) if(to.cap != 0){
        	if(to.to == t);
        	else if(to.from == s && to.cap == to.flow);
            else ds.Union(to.from , to.to);// , DB4(to.from , to.to , to.flow , to.cap);;
        }
        return flow;
    }
}dc;
int n , m , v[MAX];
int32_t main(){
    IOS;
    dc.init();
    ds.init();

    cin >> n >> m;
    int s = 0 , t = n + m + 10 , all = 0;
    REP(i , 1 , n + 1) cin >> v[i];
    REP(i , 1 , n + 1) dc.ADDE(i , t , v[i]);

    REP(i , 1 , m + 1){

        int v1 , v2 , val;
        cin >> v1 >> val , all += val;
        dc.ADDE(s , i + n , val);
        REP(j , 1 , v1 + 1){
            cin >> v2;
            dc.ADDE(i + n , v2 , INF);
        }
    }

    int res = dc.FLOW(s , t);
    cout << all - res << endl;
    
    vector<int> ans;
    REP(i , 1 , n + 1) if(ds[i] == ds[s]) ans.pb(i);
    cout << ans.size() << endl;
    REP(i , 0 , ans.size()){
        if(i) cout << " ";
        cout << ans[i] ;
    }cout << endl;
    return 0;
}
