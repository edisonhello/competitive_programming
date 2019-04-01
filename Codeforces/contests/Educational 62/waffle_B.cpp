#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie(0);
	int t, n, cnta, cntb;
	string s;
	cin >> t;
	while ( t-- ){
		cin >> n;
		cin >> s;
		if ( s[0] != '<' || s[s.size()-1] != '>' || n == 1 ) {
			cout << 0 << '\n';
			continue;
		}
		cnta = cntb = 0;
		for ( int i=0; i<s.size()&&s[i]=='<'; ++i ) ++cnta;
		for ( int i=s.size()-1; i>=0&&s[i]=='>'; ++i ) ++cntb;
		cout << min(cnta, cntb) << '\n';
	}
	return 0;
}
