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
#define MAX 1000
#define INF 0x3f3f3f3f

PII operator-(PII x , PII y){ return mp(x.A - y.A , x.B - y.B); } 
int cross(PII x , PII y){
	int val = 1LL * x.A * y.B - 1LL * x.B * y.A;
	return val;
}
int n , len , use[MAX];
double w[MAX];
vector<PII> v[MAX];
int check(PII a , PII b , PII c){
	PII aa = c - a , bb = c - b;
	int val = cross(aa , bb);
	if(val > 0) return  1;
	if(val < 0) return -1;
	return 0;
}
double DIS(PII x , PII y){
	double v1 = x.A - y.A;
	double v2 = x.B - y.B;
	return sqrt(v1 * v1 + v2 * v2);
}
double solve(){
	vector<PII> sol , fr , ba;
	REP(i , 0 , n) if(use[i]) for(auto to : v[i]) sol.pb(to);
	sort(ALL(sol));
	REP(i , 0 , sol.size()){
		while(fr.size() >= 2 && check(fr[fr.size() - 1] , fr[fr.size() - 2] , sol[i]) != -1) fr.pop_back();
		fr.pb(sol[i]);
	}
	RREP(i , sol.size() - 1 , 0){
		while(ba.size() >= 2 && check(ba[ba.size() - 1] , ba[ba.size() - 2] , sol[i]) != -1) ba.pop_back();
		ba.pb(sol[i]);
	}
	double val = 0;
	REP(i , 1 , fr.size()) val += DIS(fr[i - 1] , fr[i]);
	REP(i , 1 , ba.size()) val += DIS(ba[i - 1] , ba[i]);
	return val;
}
int32_t main(){
	cin >> n >> len;
	REP(i , 0 , n){
		int nn , a , b; cin >> nn;
		REP(j , 1 , nn + 1) cin >> a >> b , v[i].pb(mp(a , b));
	}
	REP(i , 0 , n){
		REP(j , 0 , v[i].size()){
			int now = j , nxt = (j + 1) % v[i].size();
			w[i] += cross(v[i][now] , v[i][nxt]);
		}
		w[i] = abs(w[i]) / 2;
	}
	//REP(i , 0 , n) cout << i << " " << w[i] << endl;
	double ans = 0;
	REP(i , 0 , (1 << n)){
		REP(j , 0 , n) if(i & (1 << j)) use[j] = 1;
		double val = solve() , sum = 0;
		if(val <= len){
			REP(j , 0 , n) if(i & (1 << j)) sum += w[j];
			ans = max(ans , sum);
		}
		REP(j , 0 , n) if(i & (1 << j)) use[j] = 0;
	}
	printf("%.1f\n" , ans);
	return 0;
}
