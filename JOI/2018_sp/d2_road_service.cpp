#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<1002> bG[1002];
vector<int> G[1002];
vector<pair<int,int>> add;

int n,d[1002];
bitset<1002> v;

int get(int s){
    memset(d,0x3f,sizeof(d)); d[s]=0;
    v.reset();
    queue<int> q; q.push(s); v[s]=1;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i:G[now]){
            if(v[i])continue;
            v[i]=1;
            q.push(i);
            d[i]=d[now]+1;
        }
    }
    int rt=0;
    for(int i=1;i<=n;++i)rt+=d[i];
    return rt;
}

int get(){
    int rt=0;
    for(int i=1;i<=n;++i)rt+=get(i);
    return rt/2;
}


int main(){
    auto start_c=clock();
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,w0; cin>>n>>k>>w0;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        bG[u][v]=bG[v][u]=1;
    }
    add.resize(k);
    // ll tot=(1ll<<61);
    vector<pair<int,int>> ans;
    while(k--){
        int u,v,mxd=-10;
        for(int i=1;i<=n;++i){
            get(i);
            for(int j=1;j<=n;++j){
                if(d[j]>mxd){
                    mxd=d[j];
                    u=i;
                    v=j;
                }
            }
        }
        ans.emplace_back(u,v);
        bG[u][v]=bG[v][u]=1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
    cout<<get()<<endl;
}
/* 11 pts only QQ */
