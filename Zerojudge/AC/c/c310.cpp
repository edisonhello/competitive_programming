#include<bits/stdc++.h>
using namespace std;

int bit[100008],in[50008],out[50008],timer;
bitset<100008> apl;
vector<int> G[50008];

void dfs(int now,int pa){
    in[now]=++timer;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
    }
    out[now]=++timer;
}
#define lb(x) ((x)&-(x))
void add(int x,int v){
    for(;x<100008;x+=lb(x)){
        bit[x]+=v;
    }
}
int qry(int x,int rt=0){
    for(;x;x-=lb(x)){
        rt+=bit[x];
    } return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    apl.set();
    for(int i=1;i<=n;++i)add(in[i],1);
    int q; cin>>q; while(q--){
        int c,x; cin>>c>>x;
        if(c==1){
            if(apl[x]){
                apl[x]=0;
                add(in[x],-1);
            }
            else{
                apl[x]=1;
                add(in[x],1);
            }
        }
        else{
            cout<<qry(out[x])-qry(in[x]-1)<<endl;
        }
    }
}
