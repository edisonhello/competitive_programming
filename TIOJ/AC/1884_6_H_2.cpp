#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll mx = ((ll)1<<60);

inline int rit(){
    int t=0,k=1;char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int main(){
    vector<ll> pos,fnt,bak;
    ll t=rit();
    while(t--){

    ll n=rit(),k=rit(),l=rit();

    pos.clear();fnt.clear();bak.clear();
    pos.resize(n+2);fnt.resize(n+2);bak.resize(n+2);

    for(ll i=1;i<=n;i++){
        pos[i]=rit();
    }

    pos[0] = fnt[0]  = 0;
    for(ll i=1;i<=n;i++){/*i*\0/*/
        if(i-k>=0)fnt[i] = fnt[i-k]+pos[i];
        else{fnt[i] = pos[i];}
        fnt[i] += min(pos[i], l-pos[i]);
    }

    pos[n+1] = l;
    bak[n+1] = 0;
    for(ll i=n;i>=1;i--){
        if(i+k<=n+1)bak[i] = bak[i+k]+l-pos[i];
        else{bak[i] = l-pos[i];}
        bak[i] += min(pos[i], l-pos[i]);
    }

    ll ans=mx;
    for(ll i=0;i<=n;i++){
        ans = min(ans,fnt[i]+bak[i+1]);
    }
    printf("%lld\n",ans);


}}
