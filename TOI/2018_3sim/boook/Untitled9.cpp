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
#define ALL(i) i.begin() , i.end()
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///---------------------------
#define int long long
#define MAX 220
#define INF 2000000000000000000LL

PII operator+(PII x , PII y){ return mp(x.A + y.A , x.B + y.B); } 
int n , m , s , t , k , d[MAX][MAX] , w[MAX][MAX] , inq[MAX][MAX] , best[MAX];
int e[20900][3];
vector<int> v[MAX];
PII dis[MAX][MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> s >> t >> k;
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) d[i][j] = INF;
	REP(i , 1 , n + 1) d[i][i] = 0;
	REP(i , 1 , m + 1){
		int a , b , c;
		cin >> a >> b >> c;
		e[i][0] = a , e[i][1] = b , e[i][2] = c;
		v[a].pb(i) , v[b].pb(i);
		d[a][b] = min(d[a][b] , c);
		d[b][a] = min(d[b][a] , c);
	}
	REP(k , 1 , n + 1) REP(i , 1 , n + 1) REP(j , 1 , n + 1) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
	
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) dis[i][j] = mp(INF , INF);
	REP(now , 1 , n + 1){
		best[now] = INF;
		for(auto id : v[now]){
			int to = e[id][0] ^ e[id][1] ^ now;
			if(d[now][t] == d[to][t] + e[id][2]){
				if(best[now] == INF || to <= best[now]) 
					best[now] = to;
			}
		}
	}
	REP(now , 1 , n + 1){
		for(auto id : v[now]){
			int to = e[id][0] ^ e[id][1] ^ now;
			if(to == best[now]) 
			     dis[now][to] = min(dis[now][to] , mp(0LL , -e[id][2]));
			else dis[now][to] = min(dis[now][to] , mp(1LL , -e[id][2]));
		}
	}
	REP(k , 1 , n + 1) REP(i , 1 , n + 1) REP(j , 1 , n + 1) dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
//	PII tmp = dis[3][3];
//	DBGG(tmp.A , tmp.B);
	int ans = d[s][t];
	REP(now , 1 , n + 1){
		if(d[s][now] + d[now][t] == d[s][t]){
			int ww = dis[now][now].A;
			int vv = -dis[now][now].B;
			ans = max(ans , d[s][t] + (k / ww) * vv);
		}
	}
	cout << ans << endl;
	return 0;
}









