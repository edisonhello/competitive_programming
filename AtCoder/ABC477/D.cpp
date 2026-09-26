#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;


int main() {
int n, q; cin >> n >> q;
vector<pair<int, int>> qs(q);
for (int i = 0; i < q; ++i) {
int t; cin >> t;
if (t == 1) { int x; cin >> x; qs[i] = pair{t, x - 1}; }
else { char c; cin >> c; qs[i] = pair{t, static_cast<int>(c - 'a')}; }
}

set<int> unpaint, canpaint;
string ans(n, 0);
for (int i = 0; i < n; ++i) unpaint.insert(i), canpaint.insert(i);

auto toggle = [&canpaint](int x) { if (canpaint.count(x)) canpaint.erase(x); else canpaint.insert(x); };

for (auto [t, z] : qs) {
if (t == 1) toggle(z);
}

reverse(qs.begin(), qs.end());

for (auto [t, z] : qs) {
  cerr << "rev q t z " << t << ' ' << z << endl;
if (t == 2) {
for (int i : canpaint) { ans[i] = z; unpaint.erase(i); }
canpaint.clear();
}
if (t == 1) {
if (unpaint.count(z) == 0) continue;
toggle(z);
}

}

for (char c : ans) cout << static_cast<char>(c + 'a');
cout << endl;

}
