#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

vector<pair<int,int>> G[10005];
int n,m;

bitset<10005> v;
ll d[10005];

ll dij(ll mx){
    memset(d,0x3f,sizeof(d));
    v.reset();
    d[1]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,1});
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        int np=pq.top().second;
        v[np]=1;
        for(auto i:G[np]){
            if(i.second>mx)continue;
            if(d[i.first]>d[np]+i.second){
                d[i.first]=d[np]+i.second;
                pq.push({d[i.first],i.first});
            }
        }
    }
    return d[n];
}

int main(){
    int l;
    cin>>n>>m>>l;
    while(m--){
        int u,v,l; cin>>u>>v>>l;
        G[u].emplace_back(v,l);
        G[v].emplace_back(u,l);
    }
    ll mn=dij(1e9+87),L=1,R=1000000000;
    mn=floor(mn*(ld)(1.0+(ld)l/100));
    while(R>L){
        ll M=(L+R)>>1;
        if(dij(M)<=mn)R=M;
        else L=M+1;
    }
    cout<<L<<endl;
}
