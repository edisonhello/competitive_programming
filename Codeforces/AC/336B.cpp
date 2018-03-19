#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
    int n; cin>>n;
    ld r; cin>>r;
    ld ans=0;
    ans+=n*2*r;
    ans+=(n-1)*2*(r*sqrt(2)+2*r);
    for(int i=2;i<n;++i)ans+=(n-i)*2*(r*sqrt(2)*2+(i-1)*2*r);
    cout<<fixed<<setprecision(20)<<ans/n/n<<endl;
}
