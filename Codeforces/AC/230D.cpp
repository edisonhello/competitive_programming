#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[100005];
set<int> blk[100005];

bitset<100005> v;
int in[100005],out[100005];

int gettime(int i,int t){
    auto it=blk[i].lower_bound(t);
    while(it!=blk[i].end() && *it==t && t<in[i])++t,++it;
    return t>=in[i]?out[i]:t;
}
int gettime_(){
    auto it=blk[1].lower_bound(0); int t=0;
    while(it!=blk[1].end() && *it==t)++it,++t;
    return t;
}

int meow(int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(in,0x3f,sizeof(in)); memset(out,0x3f,sizeof(out));
    in[1]=0; out[1]=gettime_(); pq.emplace(out[1],1);
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        v[pq.top().second]=1;
        for(auto &i:G[pq.top().second]){
            if(!v[i.first] && out[pq.top().second]+i.second<in[i.first]){
                int ot=gettime(i.first,out[pq.top().second]+i.second);
                if(ot<out[i.first]){
                    out[i.first]=ot;
                    in[i.first]=out[pq.top().second]+i.second;
                    pq.emplace(ot,i.first);
                }
            }
        }
    }
    return in[n]==0x3f3f3f3f?-1:in[n];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        G[u].emplace_back(v,c);
        G[v].emplace_back(u,c);
    }
    for(int i=1,k,t;i<=n;++i){
        cin>>k; while(k--){
            cin>>t; blk[i].insert(t);
        }
    }
    cout<<meow(n)<<endl;
}
