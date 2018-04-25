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
#define MAX 1010
#define INF 0x3f3f3f3f

PII operator-(PII x , PII y){ return mp(x.A - y.A , x.B - y.B); } 
int cross(PII x , PII y){
	long long val = 1LL * x.A * y.B - 1LL * x.B * y.A;
	if(val > 0) return  1;
	if(val < 0) return -1;
	return 0;
}
int n , id[MAX];
PII x[MAX];
string s[MAX];
int same(int i , int j){
	if(s[i] == "W" || s[j] == "W") return 1;
	return s[i] == s[j];
}
vector<int> sol;
int32_t main(){
	IOS;                    
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B >> s[i];
	REP(i , 1 , n + 1) if(x[i].A ==     0 && x[i].B == 10000) swap(x[1] , x[i]) , swap(s[1] , s[i]);
	REP(i , 1 , n + 1) if(x[i].A ==     0 && x[i].B ==     0) swap(x[2] , x[i]) , swap(s[2] , s[i]);
	REP(i , 1 , n + 1) if(x[i].A == 10000 && x[i].B == 10000) swap(x[3] , x[i]) , swap(s[3] , s[i]);
	REP(i , 1 , n + 1) if(x[i].A == 10000 && x[i].B ==     0) swap(x[4] , x[i]) , swap(s[4] , s[i]);
	
	REP(i , 1 , n + 1) if(s[i] != "W") sol.pb(i);
	REP(i , 1 , n + 1){
		if(same(i , 1)) id[i] = 1;
		if(same(i , 2)) id[i] = 2;
		if(same(i , 3)) id[i] = 4;
		if(same(i , 4)) id[i] = 8;
	}
	random_shuffle(ALL(sol));
	int v1 = 0 , v2 = 0;
	REP(i , 1 , n + 1) REP(j , 1 , n + 1){
		if(i == j) continue;
		if(same(i , 1) == 0 && same(i , 2) == 0) continue;
		if(same(j , 3) == 0 && same(j , 4) == 0) continue;
        cout<<i<<" "<<j<<endl;
		
		int ok = 0 , c = 0 , d = 0;
		for(auto k : sol){
			if(k == i || k == j) continue;
			int val = cross(x[j] - x[i] , x[k] - x[i]);

			if(val == 1) c |= id[k];
			if(val == -1) d |= id[k];
			if((((c & 3) == 0 && (d & 12) == 0) || ((d & 3) == 0 && (c & 12) == 0)) == 0) break;
		}
		if((c & 3) == 0 && (d & 12) == 0) ok = 1;
		if((d & 3) == 0 && (c & 12) == 0) ok = 1;
		v1 += ok;
	}
	
	REP(i , 1 , n + 1) REP(j , 1 , n + 1){
		if(i == j) continue;
		if(same(i , 1) == 0 && same(i , 3) == 0) continue;
		if(same(j , 2) == 0 && same(j , 4) == 0) continue;
		int ok = 0 , c = 0 , d = 0;
		for(auto k : sol){
			if(k == i || k == j) continue;
			int val = cross(x[j] - x[i] , x[k] - x[i]);
		
			if(val == 1) c |= id[k];
			if(val == -1) d |= id[k];
			if((((c & 5) == 0 && (d & 10) == 0) || ((d & 5) == 0 && (c & 10) == 0)) == 0) break;
		}
		if((c & 5) == 0 && (d & 10) == 0) ok = 1;
		if((d & 5) == 0 && (c & 10) == 0) ok = 1;
		v2 += ok;
	}

	v1 /= 2 , v2 /= 2;
	cout << 1LL * v1 * v2 << endl;
	return 0;
}




