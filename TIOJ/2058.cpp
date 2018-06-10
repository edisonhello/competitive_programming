#include<bits/stdc++.h>
using namespace std;

struct ${
    long long a, b;
    int update(long long x){
        if(x>=b || x==a)return 0;
        if(x>a)return b=x,2;
        if(x<a)return b=a,a=x,1;
    }
} d[100005];

vector<pair<int,int>> G[100005];
int v[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
        int n,m,a,b; cin>>n>>m>>a>>b;
        memset(d,0x3f,sizeof(d));
        for(int i=0;i<=n;++i)G[i].clear();
        memset(v,0,sizeof(v));
        while(m--){
            int u,v,c;
            cin>>u>>v>>c;
            G[u].emplace_back(v,c);
        }
        d[a].update(0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.emplace(0,a);
        while(pq.size()){
            while(pq.size() && v[pq.top().second]>=2)pq.pop();
            if(pq.empty())break;
            int now=pq.top().second; 
            pq.pop();
            // cout<<"now: "<<now<<endl;
            ++v[now];
            for(auto &p:G[now]){
                int up=d[p.first].update(d[now].a+p.second);
                if(!up)continue;
                if(up==1)pq.emplace(p.first,d[p.first].a);
                else pq.emplace(d[p.first].b,p.first);
            }
            for(auto &p:G[now]){
                int up=d[p.first].update(d[now].b+p.second);
                if(!up)continue;
                if(up==1)pq.emplace(p.first,d[p.first].a);
                else pq.emplace(d[p.first].b,p.first);
            }
        }
        cout<<d[b].b-d[b].a<<endl;
    }
}
