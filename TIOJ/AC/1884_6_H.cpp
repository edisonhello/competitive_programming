#include<bits/stdc++.h>

#define ll long long

using namespace std;
inline int rit(){
    int t=0,key=1;
    char j;
    do{
            j=getchar();
            if(j=='-')key=-1;
    }while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t*key;
}


int main(){
    vector<ll> pos,fnt,bak;
    ll t=rit();
    //ll t=1;
    while(t--){
        ll n=rit(),k=rit(),l=rit();
        pos.clear();pos.resize(n+2);
        fnt.clear();fnt.resize(n+2);
        bak.clear();bak.resize(n+2);

        for(ll i=1;i<=n;i++){
            pos[i]=rit();
        }

        pos[0] = fnt[0] = 0;
        for(ll i=1;i<=n;i++){
            if(i-k>=0){
                fnt[i] = fnt[i-k]+pos[i];
            }
            else{
                fnt[i] = pos[i];
            }
            fnt[i] += min(pos[i],l-pos[i]);
        }
        bak[n+1] = 0;
        pos[n+1] = l;
        for(ll i=n;i>=1;i--){
            if(i+k<=n+1){
                bak[i] = bak[i+k]+l-pos[i];
            }
            else{
                bak[i] = l-pos[i];
            }
            bak[i] += min(pos[i],l-pos[i]);
        }

        ll ans = ((ll)1<<60);
        for(ll i=0;i<=n;i++){
            ans = min(ans,fnt[i] +bak[i+1]);
        }
        printf("%lld\n",ans);
    }
}
