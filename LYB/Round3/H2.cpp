/*input
3 5 2
1 8
1 8
1 8
1 8
1 8
1 8
1 8
1 8
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
#define int long long
#define MAX 1000090
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int gi[MAX] , ni[MAX];
int C(int a , int b){
	if(a < b) return 0;
	else return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
void getcountmath(){
	gi[0] = gi[1] = ni[0] = ni[1] = 1;
	REP(i , 2 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 2 , MAX) ni[i] = ni[i - 1] * ni[i] % mod;
}

int n , m , k , in1 , in2 , T[MAX];
vector<int> a , b;
void solve1(){
	int sum = 0 , ans = 0;
	REP(i , 0 , b.size()){
		int base = 1;
		REP(j , 0 , k + 1){
			T[j] = (T[j] + base) % mod;
			base = base * (1 - b[i] + mod) % mod;
		}
	}
	REP(i , 0 , a.size()){
		int base = 1;
		REP(j , 0 , k + 1){
			int val = C(k , j) * base % mod;
			ans = (ans + val * T[k - j]) % mod;
			base = base * (mod - a[i]) % mod;
		}
	}
	ans = (n * m - ans + mod) % mod;
	cout << ans << endl;
}
void solve2(){
	// cout << "B" << endl;
	int ans = 0;
	REP(i , 0 , a.size()) REP(j , 0 , b.size()){
		int tmp = 1 - a[i] - b[j];
		tmp = (tmp % mod) + mod % mod;
		ans = (ans + ppow(tmp , k)) % mod;
	}
	ans = (n * m - ans + mod) % mod;
	cout << ans << endl;
}

int32_t main(){
	IOS;
	getcountmath();
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> in1 >> in2 , a.pb(in1 * ppow(in2 , mod - 2));
	REP(i , 1 , m + 1) cin >> in1 >> in2 , b.pb(in1 * ppow(in2 , mod - 2));
	int v1 = max(n , m) * k;
	int v2 = n * m * (int)(log2(k + 10));
	if(v1 < v2)
		 solve1();
	else 
		solve2();
    return 0;
}