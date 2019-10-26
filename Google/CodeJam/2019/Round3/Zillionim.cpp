// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<fstream>
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

const long long e10 = 10000000000;
const long long e12 = 1000000000000;

int hole;

long long zero_step(set<long long> &tk) {
    for (auto it = tk.begin(); next(it) != tk.end(); ++it) {
        auto nx = next(it);
        if (*nx - *it < 2 * e10) continue;
        return true;
    }
    return false;
}

long long bot_one_step(set<long long> tk) {
    for (auto it = tk.begin(); next(it) != tk.end(); ++it) {
        auto nx = next(it);
        if (*nx - *it < 2 * e10) continue;
        long long nn = (*nx - (*it + e10)) / 2 + *it + e10 / 2;
        tk.insert(nn);
        if (zero_step(tk)) { return nn; }
        tk.erase(nn);
    }
    return -1;
}

long long my_one_step(set<long long> tk) {
    for (auto it = tk.begin(); next(it) != tk.end(); ++it) {
        auto nx = next(it);
        if (*nx - *it < 2 * e10) continue;
        long long nn = (*nx - (*it + e10)) / 2 + *it + e10 / 2;
        if (nn == 1 || nn == e12 - e10 + 1) continue;
        tk.insert(nn);
        if (zero_step(tk)) { return nn; }
        tk.erase(nn);
    }
    return -1;
}


int main(){
    CPPinput;
    ofstream calog("log");
    int t, w; cin >> t >> w; while (t--) {
        calog << "new game! " << endl;
        set<long long> tk;
        auto is_good = [&] (long long x) {
            auto it = tk.lower_bound(x);
            auto p = prev(it);
            return x - *p >= e10 && *it - x >= e10;
        };
        auto put = [&] (long long x) {
            cout << x << endl;
            calog << "I put " << x << endl;
            tk.insert(x);
        };
        tk.insert(1 - e10); tk.insert(e12 + 1);
        hole = 0;
        long long p; while (cin >> p) {
            calog << "Receive " << p << endl;
            if (p == -1) exit(0);
            if (p == -2 || p == -3) break;
            tk.insert(p);
            if (is_good(1) && !hole) {
                if (tk.count(e10 + 1));
                else if (is_good(e10 + 1)) {
                    put(e10 + 1);
                    ++hole;
                    continue;
                }
            }
            if (is_good(e12 - e10 + 1) && !hole) {
                if (tk.count(e12 - e10 - e10 + 1));
                else if (is_good(e12 - e10 - e10 + 1)) {
                    put(e12 - e10 - e10 + 1);
                    ++hole;
                    continue;
                }
            }

            /* long long good = my_one_step(tk);
            if (good != -1) {
                put(good);
                continue;
            } */

            long long good = -1;
            for (auto it = tk.begin(); next(it) != tk.end(); ++it) {
                auto nx = next(it);
                if (*nx - *it < 2 * e10) continue;
                long nn = *it + e10;
                tk.insert(nn);
                if (nn != 1 && nn != e12 - e10 + 1 /* && bot_one_step(tk) == -1 */) {
                    good = nn;
                    break;
                }
                tk.erase(nn);
            }
            if (good != -1) {
                put(good);
                continue;
            }



            if (is_good(1)) { put(1); continue; }
            if (is_good(e12 - e10 + 1)) { put(e12 - e10 + 1); continue; }
        }
    }
}
