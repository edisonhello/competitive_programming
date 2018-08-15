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
#define MAX 300900
#define INF 0x3f3f3f3f
 
PII operator + (PII x , PII y){ return mp(x.A + y.A , x.B + y.B); }
 
int t , n , m , q[MAX][3] , ans[MAX];
int cc[1009][509][2];
vector<int> v[MAX];
inline void init(int now){
    REP(i , 0 , now + 1) v[i].clear();
    MEM(cc , 0);
}
inline int TRS(char now){
    int val;
    if(now >= '0' && now <= '9') val = now - '0';
    if(now >= 'a' && now <= 'z') val = now - 'a' + 10;
    if(now >= 'A' && now <= 'Z') val = now - 'A' + 36;
    return (1LL << val);
}
int32_t main(){
    IOS;
    cin >> t;
    REP(times , 0 , t){
        cin >> n;
        init(n);
        int len = n;
        vector<PII> all;
        REP(i , 1 , n + 1){
            int xxx = n + 1 - i;
            for(int T = 0 ; T < len ; ++ T , xxx += 2){
                char now; cin >> now;
                all.pb(xxx , i);
                cc[xxx][i][1] = TRS(now);
            }
            len ++;
        }len = n + n - 2;
        REP(i , n + 1 , n + n){
            int xxx = i - n + 1;
            for(int T = 0 ; T < len ; ++ T , xxx += 2){
                char now; cin >> now;
                all.pb(xxx , i);
                cc[xxx][i][1] = TRS(now);
            }
            len --;
        }
        cin >> m;
        REP(i , 1 , m + 1){
            cin >> q[i][0] >> q[i][1] >> q[i][2];
            v[q[i][2]].pb(i);
        }
        REP(i , 1 , n + 1){
            int now = i % 2 , nxt = 1 - i % 2;
            for(auto idx : v[i]){
                int xx = q[idx][0] + (i - 1) * 2;
                int yy = q[idx][1];
                ans[idx] = cc[xx][yy][now];
            }
 
            for(auto to : all){
                int val = cc[to.A][to.B][now];
                for(auto vv : {mp(-1 , -1) , mp( 1 , -1) , mp(-2 ,  0) ,
                        mp( 2 ,  0) , mp(-1 ,  1) , mp(1 ,  1)}){
                    val |= cc[to.A + vv.A][to.B + vv.B][now];                  
                }
                cc[to.A][to.B][nxt] = val;
            }
        }
        REP(i , 1 , m + 1){
            int val = ans[i] , cnt = 0;
            while(val) cnt += val % 2 , val >>= 1;
            cout << cnt << endl;
        }
    }
    return 0;
}
