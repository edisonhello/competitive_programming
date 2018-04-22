#ifdef not_code
posibility for positive: p ,
Noder choose positive chance: 1
both pos: p, Noder +a
both append: 1-p, Noder -(a+b)/2
both neg: 0, Noder +b
expect value: ap-(1-p)*(a+b)/2
Noder choose positive chance: 0
both pos: 0, Noder +a
both append: p, Noder -(a+b)/2
both neg: 1-p, Noder +b
expect value: bp-(1-p)*(a+b)/2
want ap-(1-p)*(a+b)/2 == b(1-p)-p*(a+b)/2
then 2*ap+(p-1)*(a+b) == 2*b(1-p)-p*(a+b)
     2*ap+(a+b)p+2*bp+(a+b)p == (a+b)+2*b
     p ( 2a + a+b + 2b + a+b) == a + 3b
#endif

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t; cin>>t; while(t--){
        int a,b; cin>>a>>b;
        int zi=a+3*b;
        int mu=2*a+a+b+2*b+a+b;
        int g=__gcd(zi,mu);
        zi/=g; mu/=g;
        cout<<zi<<"/"<<mu<<'\n';
    }
}
