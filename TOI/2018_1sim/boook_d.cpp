/*input
5
40
0 25 -45
1 8 5
2 19 23
3 37 -15
4 78 33
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
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
#define MAX 100900
#define INF 0x3f3f3f3f

int all = 1000000000000000000LL;
struct N{ int id , x , y;} x[MAX];
PII mp(int a , int b){
    if(a > b) swap(a , b);
    return make_pair(a , b);
}
PII ans;
int trs(int a , int b){
    return ((a & ((1ll << 32) - 1)) << 31) | (b & ((1ll << 32) - 1));
}
double calc(N a , N b){
    int v1 = a.x - b.x , v2 = a.y - b.y;
    if(all == v1 * v1 + v2 * v2) ans = min(ans , mp(a.id , b.id));
    if(all  > v1 * v1 + v2 * v2){
    	all = v1 * v1 + v2 * v2;
    	ans = mp(a.id , b.id);
    }
    return sqrt(v1 * v1 + v2 * v2);
}
double dis = 1e100 , r;
int n , k;
cc_hash_table<int , int> cc;
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 0 , n) cin >> x[i].id >> x[i].x >> x[i].y;
    random_shuffle(x , x + n);

    REP(i , 1 , n){
        double val = calc(x[i - 1] , x[i]);
        if(fabs(val - dis) <= 1e-9) ans = min(ans , mp(x[i - 1].id , x[i].id));
        if(val < dis) dis = val , ans = mp(x[i - 1].id , x[i].id);
    }
    // cout << dis << " " << dis * dis << endl;
    r = dis / 2;
    REP(i , 0 , n){
        int idx = floor(x[i].x / r) , idy = floor(x[i].y / r);
        double tmp = 1e100;
        PII ppp;
        REP(ii , idx - 5 , idx + 5) REP(jj , idy - 5 , idy + 5){
            if(cc.find(trs(ii , jj)) != cc.end()){
                int to = cc[trs(ii , jj)];
                double val = calc(x[to] , x[i]);
                if(fabs(val - tmp) <= 1e-9) ppp = min(ppp , mp(x[to].id , x[i].id));
                if(val < tmp) tmp = val , ppp = mp(x[to].id , x[i].id);
            }
        }
        if(fabs(tmp - dis) <= 1e-9) ans = min(ans , ppp);
        if(tmp < dis){
            cc.clear();
            dis = tmp , ans = ppp , r = dis / 2;
            REP(ii , 0 , i + 1)
                cc[trs(floor(x[ii].x / r) , floor(x[ii].y / r))] = ii;
        }
        else {
            cc[trs(idx , idy)] = i;
        }
    }
    // REP(i , 0 , n) REP(j , i + 1 , n) calc(x[i] , x[j]);
    if(cc.size() != n) exit(7122);
    cout << ans.A << " " << ans.B << " " << all << endl;

    return 0;
}
