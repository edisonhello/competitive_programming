#include<bits/stdc++.h>
using namespace std;
#define ull long long

const ull mod=1024615919;
const ull base=10;

int n;
string s;
ull hsh[1000006],pre[1000006],pp[1000006],ipp[1000006];

ull get(int L,int R){
    ull seghsh=(pre[R]-(L?pre[L-1]:0)+mod*2)%mod+mod;
    return seghsh%mod*ipp[n-1-R]%mod;
}

void check(int leftLen,int L,int R,int rightLen){
    int lL=0,lR=leftLen-1;
    int rL=n-rightLen,rR=n-1;
    // cout<<lL<<" "<<lR<<" "<<L<<" "<<R<<" "<<rL<<" "<<rR<<endl;
    if(leftLen<1 || R<L || rightLen<1)return;
    if(leftLen>1 && s[0]==0)return;
    if(R-L+1>1 && s[L]==0)return;
    if(rightLen>1 && s[R+1]==0)return;
    // cout<<get(lL,lR)<<" "<<get(L,R)<<" "<<get(rL,rR)<<endl;
    if((get(lL,lR)+get(L,R))%mod == get(rL,rR)){
        for(int i=0;i<n;++i){
            if(i==L)cout<<'+';
            cout<<(char)(s[i]+'0');
            if(i==R)cout<<'=';
        }
        cout<<endl;
        exit(0);
    }
}

ull pw(ull b,ull n,ull m,ull a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    cin>>s; n=s.size();
    for(char &ch:s)ch-='0';
    pp[0]=1; for(int i=1;i<1000006;++i)pp[i]=pp[i-1]*base%mod;
    ipp[1000005]=pw(pp[1000005],mod-2,mod); for(int i=1000004;i>=0;--i)ipp[i]=ipp[i+1]*base%mod;
    for(int i=n-1;i>=0;--i)hsh[i]=s[i]*pp[n-1-i]%mod;
    pre[0]=hsh[0]; for(int i=1;i<n;++i)pre[i]=(pre[i-1]+hsh[i])%mod;
    // cout<<"hsh: "; for(int i=0;i<n;++i)cout<<hsh[i]<<" "; cout<<endl;
    // cout<<"pre: "; for(int i=0;i<n;++i)cout<<pre[i]<<" "; cout<<endl;
    int leftLen=n/2,rightLen=n/2;
    int L=leftLen,R=s.size()-1-rightLen;
    if(L>R)--L,--leftLen;
    while(R-L+1<n){
        check(leftLen,L,R,rightLen);
        if(leftLen==rightLen)--leftLen,--L;
        else --rightLen,++R;
    }
    for(int L=1;L<n-1;++L){
        leftLen=L;
        rightLen=(n-leftLen+1)/2;
        int R=n-rightLen-1;
        check(leftLen,L,R,rightLen);
    }
    exit(404);
}
