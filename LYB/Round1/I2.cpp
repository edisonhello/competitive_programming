#pragma GCC optimize("Ofast", "no-math-errno", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define MAX 300900
#define INF 0x3f3f3f3f

unsigned int n;
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
int LCA(int a , int b){
    if(FA(a , b)) return a;
    RREP(i , 20 - 1 , 0) if(FA(sp[a][i] , b) == 0) a = sp[a][i];
    return sp[a][0];
}
int DIS(int a , int b){
	if(a == b) return 0;
    return dep[a] + dep[b] - dep[LCA(a , b)] * 2;
}
void solveinit(){
    DFS0(1 , 0 , 0) , out[0] = ++pos;
    for(auto j=1u;j<20u;++j) for(auto i=1u;i<=n;++i) sp[i][j] = sp[sp[i][j - 1]][j - 1];
}

pair<int , PII> son[MAX] , pre[MAX] , base;
int ans[MAX];
pair<int , PII> T(int a , int b){ return mp(DIS(a , b) , mp(a , b)); }
pair<int , PII> MERGE(pair<int , PII> &v1 , pair<int , PII> v2){
    if(v1.A == -1) return v2; if(v2.A == -1) return v1;
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
        for(auto i=0u;i<sol.size();++i)
			base = MERGE(base , son[sol[i]]) , fr[i] = base;

		base = MERGE(pre[now] , mp(0 , mp(now , now)));
        ba.resize(sol.size());
		RREP(i , sol.size() - 1 , 0)
			base = MERGE(base , son[sol[i]]) , ba[sol.size() - 1 - i] = base;
		reverse(ALL(ba));
        for(auto i=0u;i<sol.size();++i){
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
		pair<int , PII> big = max(son[now] , son[to]);
		int v1 = dep[son[now].B.A] > dep[son[now].B.B] ? son[now].B.A : son[now].B.B;
		int v2 = dep[son[ to].B.A] > dep[son[ to].B.B] ? son[ to].B.A : son[ to].B.B;
		son[now] = max(big , mp(dep[v1] + dep[v2] - dep[now] * 2 , mp(v1 , v2)));
	}
}
void DFS3(int now , int fa){
	if(pre[now].A != -1) ans[now] += pre[now].A;
	for(auto to : v[now]) if(to != fa){
		DFS3(to , now);
		ans[now] += son[to].A;
	}
}
inline int gtx() {
    const int N = 4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread_unlocked(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}
inline int rit(){
	char c = gtx();
	int res = 0;
	while(!isdigit(c)) c = gtx();
	while(isdigit(c)) res = res * 10 + (c & 15) , c = gtx();
	return res;
}
struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; T t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite_unlocked(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
int32_t main(){
    n = rit();
    for(int i = 1 , a , b; i < n; ++i){
        a = rit(); b = rit();
        v[a].pb(b) , v[b].pb(a);
    }
    solveinit();
    int root = 1;
    DFS(root , 0);
    pre[root].A = -1;
    DFS2(root , 0);
    DFS3(root , 0);
    for(auto i=1u;i<=n;++i)pit(ans[i]);
    return 0;
}
