#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rit(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define pb push_back
using namespace std;

int main(){
    int ts;rit(ts);while(ts--){
        int n; scanf("%d",&n);
        ll a[100005];
        for(int i=0;i<n;i++){
        	int x,y;
        	scanf("%d%d",&x,&y);
        	a[i]=24897*x+24893*y;
		}
		sort(a,a+n);
		ll mid=a[n/2]+a[n/2-1];
		printf("%d %d %lld\n",24897,24893,mid/2);
    }
}
