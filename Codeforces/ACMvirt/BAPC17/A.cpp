#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
    int m,n; ld r; cin>>m>>n>>r;
    int ax,ay,bx,by; cin>>ax>>ay>>bx>>by;
    ld ans=0;
    ans+=r/n*abs(ay-by);
    ld mn=1e20,add=0;
    int yy=min(ay,by);
    while(yy>=0){
        ld sr=r/n*yy;
        mn=min(mn,sr*acos(-1)/m*abs(ax-bx)+add);
        --yy; add+=r/n*2;
    }
    cout<<fixed<<setprecision(10)<<ans+mn<<endl;
}
