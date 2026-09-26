#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {

int q; cin >> q;
string s, t; cin >> s >> t;
vector<pair<int, int>> qs(q);
for (auto &[i, j] : qs) cin >> i >> j, --i, --j;

set<int> iss;

for (int i = 0; i + t.size() - 1 < s.size(); ++i) {
bool is = 1;
for (int j = 0; j < t.size(); ++j) {
if (s[i + j] != t[j]) is = 0;
}
if (is) { iss.insert(i); }
}

for (auto [i, j] : qs) {
if (j - i + 1 < t.size()) { cout << "No\n"; continue; }
j -= t.size() - 1;
auto lb = iss.lower_bound(i);
auto ub = iss.upper_bound(j);
if (lb == ub) cout << "No\n";
else cout << "Yes\n";
}

}
