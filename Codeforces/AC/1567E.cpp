#include <bits/stdc++.h>
using namespace std;
#define cans(x) (1ll * (x) * ((x) + 1) / 2)
#define data dete

struct data {
  int lest, rest;
  int llen, rlen, len;
  long long ans;

  void init(int v) {
    lest = rest = v;
    llen = rlen = len = 1;
    ans = 1;
  }

  void pull_from(data l, data r) {
    ans = l.ans + r.ans;
    if (l.rest <= r.lest) {
      ans -= cans(l.rlen);
      ans -= cans(r.llen);
      ans += cans(l.rlen + r.llen);
    }

    lest = l.lest;
    rest = r.rest;
    llen = l.llen;
    if (l.llen == l.len && l.rest <= r.lest) llen += r.llen;
    rlen = r.rlen;
    if (r.rlen == r.len && l.rest <= r.lest) rlen += l.rlen;
    len = l.len + r.len;
  }
} seg[200005 * 4];

int a[200005];

#define mid ((l + r) >> 1)
#define lc(o) ((o * 2) + 1)
#define rc(o) ((o * 2) + 2)
void build(int o, int l, int r) {
  if (l == r) {
    seg[o].init(a[l]);
    return;
  }
  build(lc(o), l, mid);
  build(rc(o), mid + 1, r);
  seg[o].pull_from(seg[lc(o)], seg[rc(o)]);
}

void modify(int o, int l, int r, int x, int y) {
  if (l == r) {
    seg[o].init(y);
    return;
  }
  if (x <= mid) modify(lc(o), l, mid, x, y);
  else modify(rc(o), mid + 1, r, x, y);
  seg[o].pull_from(seg[lc(o)], seg[rc(o)]);
}

data query(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return seg[o];
  }
  if (qr <= mid) return query(lc(o), l, mid, ql, qr);
  else if (ql > mid) return query(rc(o), mid + 1, r, ql, qr);
  data d;
  d.pull_from(query(lc(o), l, mid, ql, qr),
              query(rc(o), mid + 1, r, ql, qr));
  return d;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  build(0, 1, n);

  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      modify(0, 1, n, a, b);
    } else {
      data answer = query(0, 1, n, a, b);
      cout << answer.ans << '\n';
    }
  }
}
