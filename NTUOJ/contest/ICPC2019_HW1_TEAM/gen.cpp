#include <bits/stdc++.h>
using namespace std;

struct E {
    int u, v;
    bool t;
    E(int u, int v) : u(u), v(v), t(rand() % 2) {}
    E(int u, int v, int w) : u(u), v(v), t(w) {}
};

vector<E> es;
vector<int> djs, id;

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }
void U(int x, int y) { djs[F(x)] = F(y); }

int main() {
    srand(time(0) * clock());
    int n = 10; 
    for (int i = 1; i < n; ++i) es.emplace_back(i, rand() % i);
    cerr << "meow" << endl;
    for (int i = 0, nn = n; i < nn; ++i) {
        if (rand() < RAND_MAX / 5) {
            int sz = rand() % 3 + 1;
            es.emplace_back(i, n++, 1);
            cerr << "sz = " << sz << " " << i << " " << n << endl;
            while (sz--) {
                es.emplace_back(n - 1, n, 1);
                ++n;
            }
            es.emplace_back(i, n - 1, 1);
        }
    }
    cerr << "pog" << endl;
    djs.resize(n); id.resize(n);
    for (int i = 0; i < n; ++i) djs[i] = i;
    int ce = 0;
    for (E e : es) if (!e.t) U(e.u, e.v); else ++ce;
    int m = 0;
    for (int i = 0; i < n; ++i) if (!id[F(i)]) id[F(i)] = ++m;
    cout << m << " " << ce << endl;
    for (E e : es) if(e.t) cout << id[F(e.u)] << " " << id[F(e.v)] << endl;
}
