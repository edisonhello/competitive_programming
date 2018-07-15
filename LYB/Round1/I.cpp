/*input
5
1 2
1 3
1 4
4 5
*/
#pragma GCC optimize("Ofast", "no-math-errno", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <>
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
#define MAX 300900
#define INF 0x3f3f3f3f

inline int gtx() {
    const int N = 4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}
inline int rit(){
	char c = gtx();
	int res = 0;
	while(!isdigit(c)) c = gtx();
	while(isdigit(c)) res = res * 10 + c - '0' , c = gtx();
	return res;
}

int n;
int in[MAX] , out[MAX] , sp[MAX][20] , pos = 0 , dep[MAX];
vector<int> v[MAX];
void DFS0(int now , int fa , int deep){
    in[now] = ++pos;
    dep[now] = deep;
    sp[now][0] = fa;
    for(auto to : v[now]) if(to != fa)
        DFS0(to , now , deep + 1);
    out[now] = ++pos;
}
inline int FA(int fa , int now){
    return (in[fa] <= in[now] && out[now] <= out[fa]);
}
inline int LCA(int a , int b){
    if(FA(a , b)) return a;
    RREP(i , 20 - 1 , 0) if(FA(sp[a][i] , b) == 0) a = sp[a][i];
    return sp[a][0];
}
inline int DIS(int a , int b){
	if(a == b) return 0;
    return dep[a] + dep[b] - dep[LCA(a , b)] * 2;
}
void solveinit(){
    DFS0(1 , 0 , 0) , out[0] = ++pos;
    REP(j , 1 , 20) REP(i , 1 , n + 1) sp[i][j] = sp[sp[i][j - 1]][j - 1];
}

pair<int , PII> son[MAX] , pre[MAX] , base;
int ans[MAX];
pair<int , PII> T(int a , int b){ return mp(DIS(a , b) , mp(a , b)); }
pair<int , PII> MERGE(pair<int , PII> v1 , pair<int , PII> v2){
	if(v1.A == -1 || v2.A == -1) return v1.A == -1 ? v2 : v1;
	pair<int , PII> big = max(v1 , v2);
	big = max(big , T(v1.B.A , v2.B.A));
	big = max(big , T(v1.B.A , v2.B.B));
	big = max(big , T(v1.B.B , v2.B.A));
	big = max(big , T(v1.B.B , v2.B.B));
	return big;
}

void DFS2(int now , int fa){
	vector<int> sol;
	for(auto to : v[now]) if(to != fa) sol.pb(to);
	vector<pair<int , PII>> fr , ba;
	
	base = MERGE(pre[now] , mp(0 , mp(now , now)));
	if(sol.size() == 1) pre[sol[0]] = base;
	else {
        fr.resize(sol.size());
		REP(i , 0 , sol.size())
			base = MERGE(base , son[sol[i]]) , fr[i] = base;

		base = MERGE(pre[now] , mp(0 , mp(now , now)));
        ba.resize(sol.size() - 1);
		RREP(i , sol.size() - 1 , 0)
			base = MERGE(base , son[sol[i]]) , ba[i] = base;
		reverse(ALL(ba));
		REP(i , 0 , sol.size()){
			int to = sol[i];
			if(i + 1 == sol.size()) pre[to] = fr[i - 1];
			else if(i == 0)         pre[to] = ba[i + 1];
			else pre[to] = MERGE(fr[i - 1] , ba[i + 1]);
		}

	}
	for(auto to : sol) DFS2(to , now);
}

void DFS(int now , int fa){
	son[now] = mp(0 , mp(now , now));
	for(auto to : v[now]) if(to != fa){
		DFS(to , now);
		son[now] = MERGE(son[now] , son[to]);
	}
}
void DFS3(int now , int fa){
	if(pre[now].A != -1) ans[now] += pre[now].A;
	for(auto to : v[now]) if(to != fa){
		DFS3(to , now);
		ans[now] += son[to].A;
	}
}
int32_t main(){
    // IOS;
    // cin >> n;
    n = rit();
    REP(i , 1 , n){
        int a = rit() , b = rit();
        // cin >> a >> b;
        v[a].pb(b) , v[b].pb(a);
    }
    solveinit();
    int root = 1;
    DFS(root , 0);
    pre[root].A = -1;
    DFS2(root , 0);
    DFS3(root , 0);
    // REP(i , 1 , n + 1) DB4(son[i].A , son[i].B.A , son[i].B.B , "");
    // cout << endl;
    // REP(i , 1 , n + 1) DB4(pre[i].A , pre[i].B.A , pre[i].B.B , "");
    REP(i , 1 , n + 1) printf("%d\n" , ans[i]);
    // cout << ans[i] << endl;
    return 0;
}
