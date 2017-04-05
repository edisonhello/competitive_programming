#include<iostream>
using namespace std;
#define ll long long

ll n,m,k;

ll proc(ll mx,ll p){
    if(p>mx){
        return mx*(mx+1)/2+p-mx;
    }
    return (mx+mx-p+1)*p/2;
}
bool gt(ll t){
    ll ned=0;
    ned+=t;
    ned+=proc(t-1,k-1);
    ned+=proc(t-1,n-k);
    return ned<=m;
}

int main(){
    cin>>n>>m>>k;
    ll L=1,R=m;
    while(R>L){
        ll M=(L+R)>>1;
        if(gt(M))L=M+1;
        else R=M;
    }
    if(gt(L))cout<<L<<endl;
    else cout<<L-1<<endl;
}
