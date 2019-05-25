#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; 
    for (int ts = 1; ts <= T; ++ts) {
        string s; cin >> s >> s;
        cout << "Case #" << ts << ": ";
        for (char c : s) {
        	if (c == 'E') cout << 'S';
        	else cout << 'E';
		}
		cout << endl;
    }
}
