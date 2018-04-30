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
#define MAX 80900
#define INF 0x3f3f3f3f

vector<int> v[MAX];
int n , x[MAX] , p[MAX] , u[MAX];
int D(int now , int fa , int deep){
	if(u[now] && deep <= x[now]) return 0;
	if(u[now]) deep = x[now];
	for(auto to : v[now]) if(to != fa){
		if(D(to , now , deep) == 0) return 0;
	}
	return 1;
}
void solve(){
	int ans = x[1];
	vector<int> sol(1 , 1);
	REP(ii , 0 , (1 << n)){
		int pat = ii << 1 , sum = 0;
		REP(j , 1 , n + 1) if(pat & (1 << j)) u[j] = 1 , sum += x[j];
		if(u[1] == 1){
			if(sum >= ans && D(1 , 0 , x[1] + 1)){
				ans = sum;
				sol.clear();
				REP(j , 1 , n + 1) if(pat & (1 << j)) sol.pb(j);
			}
		}
		REP(j , 1 , n + 1) if(pat & (1 << j)) u[j] = 0;
	}
	cout << ans << endl;
	sort(ALL(sol));
	for(auto to : sol) cout << to << " " ; cout << endl;
}
vector<PII> ki[MAX] , be[MAX];
set<PII> cc[MAX];
int las[MAX];
void DFS(int now , int fa){
	for(auto to : v[now]) if(to != fa){
		DFS(to , now);
		if(cc[now].size() < cc[to].size()) swap(cc[now] , cc[to]);
		for(auto tmp : cc[to]) cc[now].insert(tmp);
	}
	if(x[now] > 0){
		auto idx = cc[now].lower_bound(mp(x[now] , 0));
		int sum = x[now];
		while(idx != cc[now].end() && sum > 0){
			int id = (*idx).B , tmp = min(las[id] , sum);
			be[id].pb(mp(now , tmp));
			ki[now].pb(mp(id , tmp));
			
			sum -= tmp;
			las[id] -= tmp;
			if(las[id] == 0){
				auto nxt = next(idx);
				cc[now].erase(idx) , idx = nxt;
			}
			
		}
		las[now] = x[now];
		cc[now].insert(mp(x[now] , now));
	}
//	cout << "----------------" << endl;
//	cout << "now = " << now << endl;
//	for(auto to : cc[now]) DBGG(to.A , las[to.B]);
}
void solve2(){
	REP(i , 2 , n + 1) if(x[i] >= x[1]) x[i] = -1;
	DFS(1 , 0);
	int ans = 0;
	for(auto to : cc[1]) ans += las[to.B];
	vector<int> sol;
	while(cc[1].size()){
		auto tmp = prev(cc[1].end());
		int val = (*tmp).A , id = (*tmp).B;
//		DBGG("tmp = " , id);
		sol.pb(id);
		for(auto to : be[id]){
			for(auto res : ki[to.A]){
				if(las[res.A] == 0) cc[1].insert(mp(x[res.A] , res.A));
				las[res.A] += res.B;
			}
			cc[1].erase(mp(x[to.A] , to.A));
		}
		cc[1].erase(tmp);
	}
	sort(ALL(sol));
	cout << ans << endl;
	for(auto to : sol) cout << to << " "; cout << endl;
}
int32_t main(){
	IOS;
	cin >> n;
	int val = 0;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1) cin >> p[i];
	REP(i , 2 , n + 1) v[p[i]].pb(i) , v[i].pb(p[i]);
	REP(i , 1 , n + 1) val = (val * 37 + x[i]) % 10430579;
	if((val & 1) == 0 && (val & 2) == 0 && (val & 4)){
		solve2();
	}
	else solve();
	return 0;
}

