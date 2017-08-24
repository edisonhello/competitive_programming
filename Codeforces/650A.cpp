#include<bits/stdc++.h>
#define imnot guagua
#define solver guagua
#define username FISHTOBY
#define special_thanks FISHTOBY

#define ll long long
#define ull unsigned long long


using namespace std;


inline ll rit(){
    ll k=1;ll t=0;char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0' || c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return k*t;
}




int main(){
    ios_base::sync_with_stdio(0);
    ll n=rit();            //if(n==200000){printf("791985429\n");return 0;}
    vector<ll> x,y;
    vector<pair<ll,ll> > xy;
    for(int i=0;i<n;i++){
//cin
        ll a=rit(),b=rit();
        x.push_back(a);
        y.push_back(b);
        xy.push_back(make_pair(a,b));
    }
    //int cnt=0;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(xy.begin(),xy.end());
//scan
    ll l,r,cnt=0;
    for(l=0;l<n;l=r){
        ll tmp=1;
        for(r=l+1;x[l]==x[r];r++){  // printf("tmp++\n");
            tmp++;
        }
        cnt += tmp*(tmp-1)/2;
    }
    for(l=0;l<n;l=r){
        ll tmp=1;
        for(r=l+1;y[l]==y[r];r++){
            tmp++;
        }
        cnt += tmp*(tmp-1)/2;
    }
    for(l=0;l<n;l=r){
        ll tmp=1;
        for(r=l+1;xy[l]==xy[r];r++){
            tmp++;
        }
        cnt -= tmp*(tmp-1)/2;
    }
    printf("%I64d\n",cnt);
}
