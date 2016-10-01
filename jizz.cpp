#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int n;

int main() {
  while (cin >> n) {
    v.clear();
    v.resize(n);
    // cout<<v.size()<<endl;
    printf("%x\n",v.begin());
    printf("%x\n",v.end());
    for (int i = 0; i < n; ++i) cout<<&v[i]<<' ';
    sort(v.begin(), v.end());
    for (int &i : v) cout << &i << ' ';
    cout << endl;
  }
  return 0;
}
