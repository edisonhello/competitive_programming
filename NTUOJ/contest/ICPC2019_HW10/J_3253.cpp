// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <utility>
#include <functional>
#include <complex>
#include <climits>
#include <random>
#include <thread>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <tuple>
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
#define pii pair<int, int>
#define vint vector<int>
#define vpii vector<pair<int, int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x, v) memset((x), (v), sizeof(x))
#define RZUNI(x) sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
#define FIN(fname) freopen(fname, "r", stdin)
#define FOUT(fname) freopen(fname, "w", stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl
#define data datadetedoto

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() printf("%s: Line %d", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), fflush(stdout)
#define DEBUG 1
#define exit(x) cout << "exit code " << x << endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x) & (-(x)))

void JIZZ(string output = ""){ cout << output; exit(0); }

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9+7;

namespace SAIS {
    enum type { L, S, LMS };
    const int maxn = 2e6 + 5;
    int bkt[maxn], cnt[maxn], lptr[maxn], rptr[maxn], tptr[maxn];
    int rev[maxn];
    void pre(const vector<int> &s, int sigma) {
        fill(bkt, bkt + s.size(), -1);
        fill(cnt, cnt + sigma, 0);
        for (int i = 0; i < s.size(); ++i) ++cnt[s[i]];
        int last = 0;
        for (int i = 0; i < sigma; ++i) {
            lptr[i] = last;
            last += cnt[i];
            rptr[i] = tptr[i] = last - 1;
        }
    }
    void induce(const vector<int> &s, const vector<type> &v) {
        for (int i = 0; i < s.size(); ++i) if (bkt[i] > 0) {
            if (v[bkt[i] - 1] == L) bkt[lptr[s[bkt[i] - 1]]++] = bkt[i] - 1;
        }
        for (int i = s.size() - 1; i >= 0; --i) if (bkt[i] > 0) {
            if (v[bkt[i] - 1] != L) bkt[rptr[s[bkt[i] - 1]]--] = bkt[i] - 1;
        }
    }
    bool equal(int l, int r, const vector<int> &s, const vector<type> &v) {
        do { if (s[l] != s[r]) return false; ++l, ++r; } while (v[l] != LMS && v[r] != LMS);
        return s[l] == s[r];
    }
    vector<int> radix_sort(const vector<int> &lms, const vector<int> &s, const vector<type> &v, int sigma) {
        pre(s, sigma); 
        for (int i = 0; i < lms.size(); ++i) bkt[tptr[s[lms[i]]]--] = lms[i];
        induce(s, v);
        vector<int> rt(lms.size());
        for (int i = 0; i < lms.size(); ++i) rev[lms[i]] = i;
        int prv = -1, rnk = 0;
        for (int i = 0; i < s.size(); ++i) {
            int x = bkt[i];
            if (v[x] != LMS) continue;
            if (prv == -1) {
                rt[rev[x]] = rnk;
                prv = x;
                continue;
            }
            if (!equal(prv, x, s, v)) ++rnk;
            rt[rev[x]] = rnk;
            prv = x;
        }
        return rt;
    }
    vector<int> counting_sort(const vector<int> &s) {
        vector<int> o(s.size());
        for (int i = 0; i < s.size(); ++i) o[s[i]] = i;
        return o;
    }
    vector<int> reconstruct(const vector<int> &sa, const vector<int> &s, const vector<type> &v) {
        vector<int> pos;
        for (int i = 0; i < s.size(); ++i) if (v[i] == LMS) pos.push_back(i);
        vector<int> rev(sa.size());
        for (int i = 0; i < sa.size(); ++i) rev[i] = pos[sa[i]];
        return rev;
    }
    vector<int> sais(const vector<int> &s, int sigma) {
        vector<type> v(s.size());
        v[s.size() - 1] = S;
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] < s[i + 1] || s[i] == s[i + 1] && v[i + 1] == S) v[i] = S;
            else v[i] = L;
        }
        for (int i = s.size() - 1; i >= 1; --i) {
            if (v[i] == S && v[i - 1] == L) v[i] = LMS;
        }
        vector<int> lms;
        for (int i = 0; i < s.size(); ++i) if (v[i] == LMS) lms.push_back(i);
        vector<int> r = radix_sort(lms, s, v, sigma);
        vector<int> sa;
        if (*max_element(r.begin(), r.end()) == r.size() - 1) sa = counting_sort(r);
        else sa = sais(r, *max_element(r.begin(), r.end()) + 1);
        sa = reconstruct(sa, s, v);
        pre(s, sigma);
        for (int i = sa.size() - 1; i >= 0; --i) bkt[tptr[s[sa[i]]]--] = sa[i];
        induce(s, v);
        return vector<int>(bkt, bkt + s.size());
    }
    vector<int> build(const string &s) {
        vector<int> v(s.size() + 1);
        for (int i = 0; i < s.size(); ++i) v[i] = s[i];
        v[v.size() - 1] = 0;
        vector<int> sa = sais(v, 256);
        return vector<int>(sa.begin() + 1, sa.end());
    }
}

int z[4000006];

void manacher(const string& t) {
    int l = 0, r = 0;
    for (int i = 1; i < t.length(); ++i) {
        z[i] = (r > i ? min(z[2 * l - i], r - i) : 1);
        while (i - z[i] >= 0 && i + z[i] < t.length() && t[i - z[i]] == t[i + z[i]]) ++z[i];
        if (i + z[i] > r) r = i + z[i], l = i;
    }
}

int Min[2000006];

int pos[2000006];

int aaa[2000006];
int pre[2000006];

int main() {
    CPPinput;
    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    string r = s + "#" + t;
    vector<int> sa = SAIS::build(r);
    PDE(r, sa);
    vector<int> v(sa.size(), 0), hi(sa.size(), 0);
    for (int i = 0; i < sa.size(); ++i) v[sa[i]] = i;
    int ind = 0; hi[0] = 0;
    for (int i = 0; i < sa.size(); ++i) {
        if (!r[i]) { ind = 0; continue; }
        while (i + ind < sa.size() && r[i + ind] == r[sa[v[i] - 1] + ind]) ++ind;
        hi[v[i]] = ind ? ind-- : 0;
    }

    PDE(hi);
    int ST = s.size() + 1;
    for (int i = 0; i < sa.size(); ++i) if (sa[i] == ST) { ST = i; break; }
    if (ST) Min[ST - 1] = hi[ST];
    for (int i = ST - 2; i >= 0; --i) Min[i] = min(Min[i + 1], hi[i + 1]);
    if (ST + 1 < sa.size()) Min[ST + 1] = hi[ST + 1];
    for (int i = ST + 2; i < sa.size(); ++i) Min[i] = min(Min[i - 1], hi[i]);

    for (int i = 0; i < s.size(); ++i) aaa[i] = Min[v[i]];

    string ss = "$";
    for (char c : s) ss += string(1, c) + "$";
    manacher(ss);

    PDE(s, ss);

    long long ans = 0;
    for (int i = 1; i < ss.size(); ++i) {
        int L = 
        int pa_len = 0, R = 0;
        if (i & 1) pa_len = z[i] / 2, R = i / 2 + pa_len / 2 + 1;
        else pa_len = z[i] / 2 + 1, R = i / 2 + pa_len / 2;
        int ext = Min[v[R]];
        // ans = max(ans, pa_len + ext * 2);
        ans += 
        PDE(i, pa_len, R, ext);
    }

    cout << ans << endl;
}
