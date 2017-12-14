#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ld long double

ld ans;
map<int,int> mp;


main(){
    int n; cin>>n;
    ld tot=0,t;
    for(int i=1,cnt;i<=n;++i){
        cin>>t;
        ld tmptot=tot; cnt=i-1;
        auto it1=mp.find(t-1),it2=mp.find(t),it3=mp.find(t+1);
        if(it1!=mp.end())tmptot-=(t-1)*1ll*it1->second,cnt-=it1->second;
        if(it2!=mp.end())tmptot-=(t  )*1ll*it2->second,cnt-=it2->second;
        if(it3!=mp.end())tmptot-=(t+1)*1ll*it3->second,cnt-=it3->second;
        ans+=t*cnt-tmptot;
        tot+=t; ++mp[t];
    }
    cout<<fixed<<setprecision(0)<<ans<<endl;
}
