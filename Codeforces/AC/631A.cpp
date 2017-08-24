#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define imnot guagua
using namespace std;

inline ll rit(){
    ll t=0,key=1;
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
    ll n=rit();
    vector<ll> a,b;
    ll tmp;
    for(ll i=0;i<n;i++){
        tmp=rit();
        a.push_back(tmp);
    }sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        tmp=rit();
        b.push_back(tmp);
    }sort(b.begin(),b.end());

    ll _a=a.back();
    ll _b=b.back();

    ll cnta=0;
    while(_a){
        cnta++;
        _a>>=1;
    }ll cntb=0;
    while(_b){
        cntb++;
        _b>>=1;
    }                 //  cout<<"jizz"<<endl;

    /*bool a_[cnta];memset(a_,0,sizeof(a_));
    bool b_[cntb];memset(b_,0,sizeof(b_));*/
    ll ansa=0;
    for(ll i=0;i<cnta;i++){
        for(ll j=a.size()-1;j>=0;j--){
            if(a[j]&((ll)1<<i)){
                ansa+=((ll)1<<i);
                break;
            }
        }
    }ll ansb=0;
    for(ll i=0;i<cntb;i++){
        for(ll j=b.size()-1;j>=0;j--){
            if(b[j]&((ll)1<<i)){
                ansb+=((ll)1<<i);
                break;
            }
        }
    }

    ll ans=ansa+ansb;
    printf("%I64d\n",ans);



}

