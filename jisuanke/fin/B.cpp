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

pair<int, int> get() {
    string s; cin >> s;
    int i, b;
    switch (s[1]) {
        case 'm': b = 1; break;
        case 's': b = 2; break;
        case 'p': b = 3; break;
        case 'z': b = 4; break;
    }
    i = s[0] - '0';
    return make_pair(b, i);
}

int cnt[15];

bool listen(vector<pair<int, int>> card) {
    map<pair<int, int>, int> mp;
    for (pair<int, int> p) mp[p]++;
    for (auto &p : mp) if (p.second > 4) return 0;
    vector<int> v[5];
    for (pair<int, int> p : card) v[p.first].push_back(p.second);
    int eye = 0, cnt = 0;
    for (int i = 1; i <= 4; ++i) {
        memset(cnt, 0, sizeof(cnt));
        for (int j : v[i]) ++cnt[j];
        if (i == 4) {
            for (int j = 1; j <= 7; ++j) {
                if (cnt < 2) continue;
                v[i][j] -= 2;
                int cc = 0;
            }
        } else {

        }
    }
}

int main(){
    CPPinput;
    vector<pair<int, int>> v;
    for (int i = 0; i < 13; ++i) v.push_back(get());
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == 4 && j == 8) break;
            vector<pair<int, int>> vv = v;
            vv.emplace_back(i, j);
            if (listen(vv)) par(i, j);
        }
    }
}
