#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

struct node {
  node *l, *r;
  int pri, sz, val, mn;

  int lmn() { return l ? l->mn : 1000000000; }
  int rmn() { return r ? r->mn : 1000000000; }
  int lz() { return l ? l->sz : 0; }
  int rz() { return r ? r->sz : 0; }
  void pull() {
    mn = min(val, min(lmn(), rmn()));
    sz = lz() + rz() + 1;
  }
  node(int v = 0) : l(0), r(0), pri(rand()), sz(1), val(v), mn(v) {}
};

node *merge(node *l, node *r) {
  if (!l) return r;
  if (!r) return l;
  if (l->pri > r->pri) {
    l->r = merge(l->r, r);
    l->pull();
    return l;
  }
  r->l = merge(l, r->l);
  r->pull();
  return r;
}

void split_sz(node *now, int sz, node *&a, node *&b) {
  if (!now) {
    a = b = 0;
    return;
  }
  if (now->lz() >= sz) {
    b = now;
    split_sz(now->l, sz, a, b->l);
    b->pull();
  } else {
    a = now;
    split_sz(now->r, sz - 1 - now->lz(), a->r, b);
    a->pull();
  }
}

int find_first_less(node *now, int val) {
  if (now->mn >= val) return -1;
  if (now->lmn() < val) return find_first_less(now->l, val);
  if (now->val < val) return now->lz();
  return now->lz() + 1 + find_first_less(now->r, val);
}

node *get_left(node *now) {
  if (now->l) return get_left(now->l);
  return now;
}

void print(node *now) {
  if (!now) return;
  if (now->l) {
    cerr << "[";
    print(now->l);
    cerr << "]";
  }
  cerr << now->val;
  if (now->r) {
    cerr << "[";
    print(now->r);
    cerr << "]";
  }
}

int main() {
  srand(time(0) * clock() * clock());
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    string ss = s;
    sort(ss.begin(), ss.end());
    if (ss >= t) {
      cout << -1 << '\n';
      continue;
    }

    node *root = 0;
    for (char c : s) {
      root = merge(root, new node(c));
    }

    // cerr << "inited" << endl;
    // print(root);
    // cerr << endl;

    int64_t mn = LLONG_MAX, now = 0;
    for (char c : t) {
      node *left = get_left(root);
      // cerr << "left->val = " << left->val << " c = " << c << endl;
      if (left->val == c) {
        // cerr << "got same" << endl;
        int res = find_first_less(root, c); // how many left
        if (res != -1) {
          mn = min(mn, now + res);
        }

        node *a, *b;
        split_sz(root, 1, a, b);
        delete a;
        root = b;
      } else if (left->val < c) {
        // cerr << "got less" << endl;
        mn = min(mn, now);
        break;
      } else {
        // cerr << "got larger" << endl;
        int res = find_first_less(root, c); // how many left
        if (res != -1) {
          mn = min(mn, now + res);
        }

        res = find_first_less(root, c + 1);
        if (res != -1) {
          now += res;

          node *a, *b, *c, *d;
          split_sz(root, res, a, d);
          split_sz(d, 1, b, c);
          delete b;
          root = merge(a, c);
        } else break;
      }
    }
    cout << mn << '\n';
  }
}
