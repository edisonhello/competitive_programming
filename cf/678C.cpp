#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull g(ull a,ull b){
    ull orab = (ull)a*(ull)b;
    while(a&&b){
        ull mx = max(a,b);
        ull mn = min(a,b);
        mx -= mx/mn*mn;
        a = mx;
        b = mn;
    }
    return orab/max(a,b);
}

int main(){
    ull n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    ull gab=g(a,b);
    // cout<<gab<<endl;
    cout<<(n/a-n/gab)*p+(n/b-n/gab)*q+n/gab*max(p,q)<<endl;
}
