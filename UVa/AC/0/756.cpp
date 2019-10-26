#include<bits/stdc++.h>
using namespace std;

const int M=23*28*33;

int pw(int b,int n,int mod,int a=1){
    while(n){
        if(n&1)a=1ll*a*b%mod;
        b=1ll*b*b%mod; n>>=1;
    } return a;
}

int phi(int x){
    int p=x;
    for(int i=2;i<=x;++i){
        int c=0;
        while(x%i==0)x/=i,++c;
        if(c)p=p/i*(i-1);
    }
    if(x==1)return p;
    else return p-1;
}

int inv(int x,int mod){ 
    // cout<<"get inv of "<<x<<" in "<<mod<<endl;
    // cout<<"phi "<<mod<<" is "<<phi(mod)<<endl;
    return pw(x,phi(mod)-1,mod); }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // cout<<(M/23)*inv(M/23,23)%23<<endl;
    // cout<<(M/28)*inv(M/28,28)%28<<endl;
    // cout<<(M/33)*inv(M/33,33)%33<<endl;
    int ts=0;
    long long p,e,i,d; while(cin>>p>>e>>i>>d){
        if(p==-1)return 0;
        p%=23; e%=28; i%=33;
        // p+=23; e+=28; i+=33;
        long long x=p*(M/23)*inv(M/23,23)+
                    e*(M/28)*inv(M/28,28)+
                    i*(M/33)*inv(M/33,33);
        x%=M;
        while(x<=0)x+=M;
        // cout<<"x="<<x<<endl;
        // cout<<"x = "<<x<<endl;
        // while(x<=d)x+=M;
        int ans=x-d;
        ans%=M; if(ans<=0)ans+=M;
        cout<<"Case "<<(++ts)<<": the next triple peak occurs in ";
        cout<<ans;
        cout<<" days."<<'\n';
    }
}
