#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mine(ll a,ll b,ll c,ll d){
    while(1){
        if(b==d){
            return b;
        }
        if(b>100000){
            return -1;
        }
        if(b<d)b+=a;
        else d+=c;
    }
}
#undef ll
#define ll int
ll op1(ll a,ll b,ll c,ll d){
    for(int i=min(a,d);i<100000;++i){
        if((i-b)%a==0 && (i-d)%c==0)return i;
    }
    return -1;
}
#undef ll
#define ll long long

int main(){
    cout<<op1(1,1,1,2);
    ll a,b,c,d;
    // cin>>a>>b>>c>>d;
    // PDE3(mine(a,b,c,d),op1(a,b,c,d));
    for(int i=1;i<=100;++i){
        for(int j=1;j<=100;++j){
            for(int k=1;k<=100;++k){
                for(int l=1;l<=100;++l){
                    cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                    if(mine(i,j,k,l)!=op1(i,j,k,l)){
                        return 0;
                    }
                }
            }
        }
    }
}
