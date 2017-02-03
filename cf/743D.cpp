#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<utility>
#define ll long long

ll sum[200005],a[200005],mx[200005];
vector<int> G[200005];
ll ans=-(1ll<<60);

void d1(int now,int p){
    mx[now]=-(1ll<<60);
    sum[now]=a[now];
    for(int &i:G[now]){
        if(i==p)continue;
        d1(i,now);
        sum[now]+=sum[i];
        mx[now]=max({mx[now],sum[i]});
    }
    mx[now]=max({mx[now],sum[now]});
}

void d2(int now,int p,ll ot){
    // cout<<"in d2 now:"<<now<<" ,ot:"<<ot<<endl;
    if(ot!=-(1ll<<60))ans=max(ans,ot+sum[now]);

    vector<pair<ll,ll>> mn;
    for(int &i:G[now]){
        if(i==p)continue;
        mn.push_back({mx[i],i});
        if(mn.size()>2){
            sort(mn.rbegin(),mn.rend());
            // reverse(mn.begin(),mn.end());
            while(mn.size()>2)mn.pop_back();
        }
    }
    sort(mn.rbegin(),mn.rend());
    // reverse(mn.begin(),mn.end());
    mn.push_back({-(1ll<<60),-1});
    for(int &i:G[now]){
        if(i==p)continue;
        d2(i,now,max({ot,i==mn[0].second?mn[1].first:mn[0].first}));
    }
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i< n;++i){
        int s,t;cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    d1(1,1);
    // for(int i=1;i<=n;++i)cout<<mx[i]<<" ";cout<<endl;
    d2(1,1,-(1ll<<60));
    if(ans==-(1ll<<60))cout<<"Impossible\n";
    else cout<<ans<<endl;
}
