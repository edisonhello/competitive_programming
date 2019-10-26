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

int take;

int dfs(vector<int> v) {
    static map<vector<int>, int> mp;
    if (auto it = mp.find(v); it != mp.end()) return it->second;
    set<int> st;
    if (take == 1) {
        for (int i = 0; i < (int)v.size(); ++i) if (v[i] > 0) {
            for (int ii = 1; ii <= v[i]; ++ii) {
                v[i] -= ii;
                st.insert(dfs(v));
                v[i] += ii;
            }
        }
    } else if (take == 2) {
        for (int i = 0; i < (int)v.size(); ++i) if (v[i] > 0) {
            for (int j = i + 1; j < (int)v.size(); ++j) if (v[j] > 0) {
                for (int ii = 1; ii <= v[i]; ++ii) {
                    v[i] -= ii;
                    for (int jj = 1; jj <= v[j]; ++jj) {
                        v[j] -= jj;
                        st.insert(dfs(v));
                        v[j] += jj;
                    }
                    v[i] += ii;
                }
            }
        }
    } else if (take == 3) {
        for (int i = 0; i < (int)v.size(); ++i) if (v[i] > 0) {
            for (int j = i + 1; j < (int)v.size(); ++j) if (v[j] > 0) {
                for (int k = j + 1; k < (int)v.size(); ++k) if (v[k] > 0) {
                    for (int ii = 1; ii <= v[i]; ++ii) {
                        v[i] -= ii;
                        for (int jj = 1; jj <= v[j]; ++jj) {
                            v[j] -= jj;
                            for (int kk = 1; kk <= v[k]; ++kk) {
                                v[k] -= kk;
                                st.insert(dfs(v));
                                v[k] += kk;
                            }
                            v[j] += jj;
                        }
                        v[i] += ii;
                    }
                }
            }
        }
    }
    for (int i = 0; ; ++i) {
        if (!st.count(i)) {
            return mp[v] = i;
        }
    }
}

void test() {
    take = 3;
    vector<int> v;
    set<vector<int>> st;
    for (int i = 1; i < 6; ++i) {
        v.push_back(i);
        for (int j = 1; j < 6; ++j) {
            v.push_back(j);
            for (int k = 1; k < 6; ++k) {
                v.push_back(k);
                for (int l = 1; l < 6; ++l) {
                    v.push_back(l);
                    for (int m = 1; m < 6; ++m) {
                        v.push_back(m);
                        for (int n = 1; n < 6; ++n) {
                            v.push_back(n);
                            // PDE(v, dfs(v));
                            if (dfs(v) == 0) {
                                vector<int> vv = v;
                                sort(vv.begin(), vv.end());
                                st.insert(vv);
                            }
                            v.pop_back();
                        }
                        v.pop_back();
                    }
                    v.pop_back();
                }
                v.pop_back();
            }
            v.pop_back();
        }
        v.pop_back();
    }
    PDE(st);
    exit(0);
}

int main(){
    CPPinput;
    // test();
    int n; cin >> n;
    // take = n / 2;
    vector<int> cnt(55, 0);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t; ++cnt[t];
    }
    for (int i = 0; i <= 50; ++i) {
        if (cnt[i] >= n / 2 + 1) {
            cout << "Bob" << endl;
            exit(0);
        } else if (cnt[i]) {
            cout << "Alice" << endl;
            exit(0);
        }
    }
    /* for (int &i : v) cin >> i;
    cout << dfs(v) << endl;
    int XOR = 0;
    for (int i : v) XOR ^= i;
    PDE(XOR); */ 
}
