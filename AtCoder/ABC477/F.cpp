 #include <vector>
#include <iostream>
#include <queue>
#define mid ((l + r) / 2)

using namespace std;

struct Q { int a, b, c, d; };
struct Q2 { int idx, sgn, x, y; };
struct G {
  G *l{0}, *r{0};
  int64_t ing{0}, ingsum{0}, sum{0};
};

G* build(int l, int r) {
  G* g = new G;
  if (l == r) return g;
  g->l = build(l, mid);
  g->r = build(mid + 1, r);
  return g;
}

void modify(G* now, int l, int r, int i, int t, int j) {
  if (l == r) { // == i
    if (t == 1) { // start
      ++now->ing;
      now->ingsum += j;
      return;
    }
    --now->ing;
    now->sum = j - now->ingsum;
    now->ingsum = 0;
    return;
  }
  if (i <= mid) modify(now->l, l, mid, i, t, j);
  else modify(now->r, mid + 1, r, i, t, j);
  now->ing = now->l->ing + now->r->ing;
  now->ingsum = now->l->ingsum + now->r->ingsum;
  now->sum = now->l->sum + now->r->sum;
}

int64_t query(G* now, int l, int r, int ql, int qr, int j) {
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) {
    return (j + 1) * now->ing - now->ingsum + now->sum;
  }
  return query(now->l, l, mid, ql, qr, j) + query(now->r, mid + 1, r, ql, qr, j);
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> lr(n + 1);
  for (int i = 1; i <= n; ++i) cin >> lr[i].first >> lr[i].second;
  vector<vector<pair<int, int>>> ev(m + 2);
  for (int i = 1; i <= n; ++i) {
    ev[lr[i].first].emplace_back(i, +1);
    ev[lr[i].second + 1].emplace_back(i, -1);
  }
  vector<Q> qs(q);
  for (auto &[a, b, c, d] : qs) cin >> a >> b >> c >> d;
  vector<vector<Q2>> q2s(m + 2);
  for (int i = 0; i < q; ++i) {
    auto [a, b, c, d] = qs[i];
    q2s[c - 1].emplace_back(Q2{i, -1, a, b});
    q2s[d].emplace_back(Q2{i, 1, a, b});
  }
  // sort(q2s.begin(), q2s.end(), [](const auto &x, const auto &y) { return x.at < y.at; });
  G *rt;
  rt = build(1, n);
  vector<int64_t> ans(q);
  for (int j = 1; j <= m; ++j) {
    for (auto [i, t] : ev[j]) modify(rt, 1, n, i, t, j);
    for (auto [i, t, l, r] : q2s[j]) ans[i] += t * query(rt, 1, n, l, r, j);
  }
  for (auto x : ans) cout << x << '\n';
}
