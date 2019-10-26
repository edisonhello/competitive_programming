// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define vpii vector<pair<int,int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

#define data swedrftgyhujik

struct data {
    int val, pos;
};

data merge(data a, data b) {
    return data{ max(a.val, b.val), a.val > b.val ? a.pos : b.pos };
}

data st[20][200005];
long long ans = 0;

data query(int l, int r) {
    int d = r - l + 1;
    int z = __lg(d);
    return merge(st[z][l], st[z][r - (1 << z) + 1]);
}

set<int> *dfs(int l, int r) {
    if (l == r) {
        auto it = new set<int>();
        it->insert(st[0][l].val);
        return it;
    } else if (l > r) return new set<int>();
    data m = query(l, r);
    auto ls = dfs(l, m.pos - 1);
    auto rs = dfs(m.pos + 1, r);
    if (rs->size() < ls->size()) swap(ls, rs);
    for (int i : *ls) {
        ans += rs->count(m.val - i);
    }
    for (int i : *ls) rs->insert(i);
    rs->insert(m.val);
    delete ls;
    return rs;
}

int main(){
    CPPinput;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> st[0][i].val;
        st[0][i].pos = i;
    }
    for (int z = 1; (1 << z) <= n; ++z) {
        for (int i = 1; i + (1 << z) - 1 <= n; ++i) {
            st[z][i] = merge(st[z - 1][i], st[z - 1][i + (1 << (z - 1))]);
        }
    }
    dfs(1, n);
    cout << ans << endl;
}
