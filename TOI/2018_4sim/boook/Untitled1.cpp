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
//#define endl "\n"
///----------------------------
#define int long long
#define MAX 80900
#define INF 0x3f3f3f3f

vector<PII> ki[MAX] , be[MAX];
vector<int> v[MAX];
set<PII> cc[MAX];
int n , x[MAX] , p[MAX] , las[MAX];
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
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1) cin >> p[i];
	REP(i , 2 , n + 1) v[p[i]].pb(i) , v[i].pb(p[i]);
	
	REP(i , 2 , n + 1) if(x[i] >= x[1]) x[i] = -1;
	
	DFS(1 , 0);
	int ans = 0;
	vector<int> sol;
	for(auto to : cc[1]) ans += las[to.B];
	int all = ans;
	while(all != 0){
		auto tmp = prev(cc[1].end());
		sol.pb((*tmp).B);
		all -= x[(*tmp).B];
		DBGG("now = " , (*tmp).B);
		x[(*tmp).B] = -1;
		REP(i , 1 , n + 1) ki[i].clear() , be[i].clear() , cc[i].clear();
		MEM(las , 0);
		DFS(1 , 0);
	}
	
	sort(ALL(sol));
	cout << ans << endl;
	for(auto to : sol) cout << to << " "; cout << endl;
	return 0;
}



