#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

int R[300007],G[300007],B[300007];
int r,g,b;
int connect[300007];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int p; char type; cin>>p>>type;
        if(type=='R')R[r++]=p;
        else if(type=='G')G[g++]=p;
        else B[b++]=p;
    }
    if(!g){
        ll ans=0;
        for(int i=1;i<r;++i)ans+=R[i]-R[i-1];
        for(int j=1;j<b;++j)ans+=B[j]-B[j-1];
        cout<<ans<<endl;
        exit(0);
    }
    ll ans=0;
    for(int i=1;i<g;++i)ans+=G[i]-G[i-1];
    // cout<<"conG "<<ans<<endl;
    auto meow=[&](int *a,int sz){
        memset(connect,0,sizeof(connect));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<sz;++i){
            int gpos=lower_bound(G,G+g,a[i])-G;
            int ctg=1000000000;
            if(gpos!=g)ctg=min(ctg,G[gpos]-a[i]);
            if(gpos)ctg=min(ctg,a[i]-G[gpos-1]);
            if(i)pq.push({ctg-(a[i]-a[i-1]),mp(i-1,i)});
            if(i<sz-1)pq.push({ctg-(a[i+1]-a[i]),mp(i+1,i)});
            ans+=ctg;
        }
        int destroy=0;
        while(destroy<sz-1 && pq.size() && pq.top().first>0){
            if(connect[pq.top().second.first]==pq.top().second.second){pq.pop(); continue;}
            ans-=pq.top().first;
            connect[pq.top().second.second]=pq.top().second.first;
            pq.pop();
        }
    };
    meow(R,r);
    meow(B,b);
    cout<<ans<<endl;
}
