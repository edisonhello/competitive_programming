#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A first
#define B second
#define mp make_pair
#define pb push_back
#define PII pair<int , int>
#define ALL(i) i.begin() , i.end()
#define MEM(i , j) memset(i , j , sizeof i)
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///---------------------------
#define MAX 10900
#define INF 0x3f3f3f3f


double ans = -1;
int n , L , R , dp[MAX][210] , e[MAX][2] , tmp[MAX];
vector<PII> v[MAX];
void DFS(int now , int fa){
	for(auto id : v[now]) {
		int to = id.A , l = e[id.B][0] , w = e[id.B][1];
		if(to != fa){
			DFS(to , now);
			REP(i , 0 , MAX) tmp[i] = -1;
			REP(i , 0 , R + 1){
				int ll = i + l , ww = dp[to][i] + w;
				if(ll > R || dp[to][i] < 0) continue;
				else {
//					DB4("solve = " , ll , ww , dp[to][i]);
					REP(j , ll , R + 1){
						if(dp[now][j - ll] != -1)
							tmp[j] = max(tmp[j] , dp[now][j - ll] + ww);
					}
				}
			}
			REP(i , 0 , MAX) dp[now][i] = max(dp[now][i] , tmp[i]);
		}
	}
//	DBGG("now = " , now);
//	REP(i , 0 , R + 1) DB4(now , i , " = " , dp[now][i]);
	REP(i , L , R + 1) if(dp[now][i] != -1) ans = max(ans , (double)dp[now][i] / i);
}
int32_t main(){
	cin >> n >> L >> R;
	REP(i , 1 , n){
		int a , b;
		cin >> a >> b >> e[i][0] >> e[i][1];
		v[a].pb(mp(b , i));
		v[b].pb(mp(a , i));
	}
	MEM(dp , -1);
	REP(i , 0 , n) dp[i][0] = 0;
	DFS(0 , 0);
	if(ans < 0) cout << "-1" << endl;
	else printf("%.9f\n" , ans);
	return 0;
}











