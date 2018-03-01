#include<bits/stdc++.h>
using namespace std;

string s;
bitset<26> ans[500005],bit[500005];
vector<int> G[500005],deppnt[500005];
int in[500005],out[500005],dep[500005],dfst;
struct Q{
    int in,out,i;
};
vector<Q> qs[500005];

#define lb(x) ((x)&-(x))

void add(int x,int pos){
    // cout<<"pos: "<<pos<<endl;
    for(;x<500005;x+=lb(x))bit[x].flip(pos);
}
bitset<26> query(int x){
    bitset<26> rt;
    for(;x;x-=lb(x))rt^=bit[x];
    return rt;
}

void dfs(int now,int d){
    dep[now]=d;
    in[now]=++dfst;
    for(int i:G[now]){
        dfs(i,d+1);
    }
    out[now]=dfst;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=2;i<=n;++i){
        int p; cin>>p;
        G[p].push_back(i);
    }
    cin>>s;
    s="-"+s;
    dfs(1,1);
    for(int i=0;i<m;++i){
        int v,h; cin>>v>>h;
        // h=h-1+dep[v];
        qs[h-1].push_back({in[v],out[v],i});
        qs[h].push_back({in[v],out[v],i});
    }
    for(int i=1;i<=n;++i){
        deppnt[dep[i]].push_back(i);
    }
    for(int i=0;i<500005;++i){
        for(int ii:deppnt[i]){
            add(in[ii],s[ii]-'a');
        }
        for(Q q:qs[i]){
            ans[q.i]^=query(q.in-1)^query(q.out);
        }
    }
    for(int i=0;i<m;++i){
        // cout<<ans[i]<<endl;
        cout<<(ans[i].count()<=1u?"Yes":"No")<<'\n';
    }
}
