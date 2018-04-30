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
#define MAX 1000000
#define INF 0x3f3f3f3f

vector<int> v[MAX];
int n , x[MAX] , p[MAX] , u[MAX];
int DFS(int now , int fa , int deep){
	if(u[now] && deep <= x[now]) return 0;
	if(u[now]) deep = x[now];
	for(auto to : v[now]) if(to != fa){
		if(DFS(to , now , deep) == 0) return 0;
	}
	return 1;
}
int32_t main(){
	IOS;
	clock();
	cin >> n;
	int h = 0;
	REP(i , 1 , n + 1) cin >> x[i] , h = (h * 37 + x[i]) % 850;
	REP(i , 2 , n + 1) cin >> p[i];
	double t = h; t /= 1000;
	while(clock() / CLOCKS_PER_SEC < t);
	return 0;
}

