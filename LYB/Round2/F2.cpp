/*input
2 5 2
abcde
cbade
hello
eholl
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
#define MAX 40500
#define INF 0x3f3f3f3f

int t , k , l;
map<string , int> ans , how;
map<string , string> pre;
string sss;
// int T(string s){
//     int val = 0;
//     REP(i , 0 , s.size()) val = val * 10 + s[i] - '0';
//     return val;
// }
vector<pair<int , string>> sol;
void solveinit(){
    REP(i , 0 , k) sss += i + '0';
    queue<string> qu;
    qu.push(sss) , ans[sss] = 0; 

    while(qu.size()){
        string now = qu.front(); qu.pop();
        REP(i , 0 , k) if(i + l - 1 < k){
            string las = now , val = now.substr(i , l);
            las.erase(i , l);
            reverse(ALL(val));
            // cout << las + val << endl;
            // cout << val + las << endl;
            string to = las + val;
            if(ans.find(to) == ans.end()){
                ans[to] = ans[now] + 1;
                pre[to] = now;
                how[to] = i * 10 + 1;
                qu.push(las + val);
            }
            to = val + las;
            if(ans.find(to) == ans.end()){
                ans[to] = ans[now] + 1;
                pre[to] = now;
                how[to] = i * 10 + 0;
                qu.push(val + las);
            }
        }
    }
    for(auto to : ans) sol.pb(mp(to.B , to.A));
    sort(ALL(sol));
    // int big = 0;
    // for(auto to : sol){
    //     cout << to.A << " " << to.B << endl;
    //     // big = max(big , to.B);
    // }
    // cout << big << endl;
    // cout << ans.size() << endl;
}
int32_t main(){
    IOS;
    cin >> t >> k >> l;
    solveinit();
    string v1 , v2;
    REP(times , 0 , t){
        cin >> v1 >> v2;
        if(v1 == v2) cout << 0 << endl;
        else {
            string good;
            int step;
            REP(i , 0 , sol.size()){
                int ok = 1;
                REP(j , 0 , k){
                    if(v2[j] != v1[sol[i].B[j] - '0']){
                        ok = 0;
                        break;
                    }
                }
                if(ok){
                    step = sol[i].A;
                    good = sol[i].B;
                    break;
                }
            }

            if(good.size() == 0) cout << -1 << endl;
            else {
                cout << step << endl;
                stack<int> st;
                while(good != sss){
                    // cout << good << endl;
                    st.push(how[good]);
                    good = pre[good];
                }
                while(st.size()){
                    cout << st.top() / 10 + 1 << " " << st.top() % 10 << endl;
                    st.pop();
                }
            }
        }       
    }
    return 0;
}