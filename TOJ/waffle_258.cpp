#include <bits/stdc++.h>
#define maxn 1000005
#define INF 1e18
using namespace std;
struct point {
	double x, y;
} p[maxn], t[maxn];
int n;
bool cmpx ( point a, point b ){
	return a.x < b.x;
}
bool cmpy ( point a, point b ){
	return a.y < b.y;
}
double dis ( point a, point b ){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double mindis ( int l, int r ){
	if ( l >= r ) return INF;
	if ( r-l == 1 ) return dis(p[l], p[r]);
	if ( r-l == 2 ){
		double d1 = dis(p[l], p[r]);
		double d2 = dis(p[l+1], p[r]);
		double d3 = dis(p[l], p[r-1]);
		return min(min(d1, d2), d3);
	}
	int mid = (l+r)/2;
	double d = min(mindis(l, mid), mindis(mid+1, r));
	int cnt = 0;
	for ( int i=mid; i>=l&&p[mid].x-p[i].x<d; --i ) t[cnt++] = p[i];
	for ( int i=mid; i<=r&&p[i].x-p[mid].x<d; ++i ) t[cnt++] = p[i];
	sort(t, t+cnt, cmpy);
	for ( int i=0; i<cnt; ++i )
		for ( int j=1; j<=3&&i+j<cnt; ++j )
			d = min(d, dis(t[i], t[i+j]));
	return d;
}
int main(){
	ios::sync_with_stdio ( false );
	cin.tie(0);
	cin >> n;
	for ( int i=0; i<n; ++i ) cin >> p[i].x >> p[i].y;
	sort(p, p+n, cmpx);
	cout << fixed << setprecision(6) << mindis(0, n-1) << '\n';
	return 0;
}
