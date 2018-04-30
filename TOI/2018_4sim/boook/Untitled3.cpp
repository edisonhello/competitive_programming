#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i  < k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
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
///----------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define N pair<double , int>

int n , m , k , s[MAX] , e[MAX][3];
double b[MAX] , d[MAX];
double dis[MAX];
vector<PII> v[MAX];
int judge(double base){
	priority_queue<N> pq;
	REP(i , 1 , n + 1) dis[i] = 0;
	REP(i , 1 , k + 1) pq.push(mp(b[i] + d[i] * base , s[i])) , dis[s[i]] = b[i] + d[i] * base;
	while(pq.size()){
		double val = pq.top().A;
		int now = pq.top().B;
		pq.pop();
		if(fabs(val - dis[now]) > 1e-9) continue;
		for(auto to : v[now]){
			if(dis[to.A] < dis[now] - to.B){
				dis[to.A] = dis[now] - to.B;
				pq.push(mp(dis[to.A] , to.A));
			}
		}
	}
	REP(i , 1 , m + 1){
		if(dis[e[i][0]] + dis[e[i][1]] < e[i][2]) return 0;
	}
	return 1;
}
int32_t main(){
	clock();
	scanf("%lld%lld%lld" , &n , &m , &k);
	REP(i , 1 , m + 1){
		int A , B , C;
		scanf("%lld%lld%lld" , &A , &B , &C);
		e[i][0] = A , e[i][1] = B , e[i][2] = C;
		v[A].pb(mp(B , C));
		v[B].pb(mp(A , C));
	}
//	REP(i , 1 , k + 1) cin >> s[i] >> b[i] >> d[i];
	REP(i , 1 , k + 1) scanf("%lld%lf%lf" , &s[i] , &b[i] , &d[i]);

	double l = 0 , r = 0;
	REP(i , 1 , m + 1) r += e[i][2];	
	int ok = 0 , T = 85;
	if(m > n && n >= 100000) T = 53;
	REP(times , 0 , 85){
		double mid = (l + r) / 2.0;
		if(judge(mid)) r = mid , ok = 1;
		else l = mid;
	}
	if(ok == 0) cout << -1 << endl;
	else printf("%.11f\n" , l);
	return 0;
}
