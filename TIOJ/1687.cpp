#include<bits/stdc++.h>
using namespace std;

vector<int> G[100008];
int d[100008],p[18][100008],in[100008],out[100008],timer;
void dfs(int now,int pa,int dep){
    in[now]=++timer;
    d[now]=dep;
    p[0][now]=pa;
    for(int i=1;(1<<i)<dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(int &i:G[now]){
        if(i==pa)continue;
        dfs(i,now,dep+1);
    }
    out[now]=++timer;
}
inline bool isanc(int anc,int p){
    return in[anc]<=in[p] && out[p]<=out[anc];
}
inline int getlca(int pa,int pb){
    int stp=16;
    while(stp>=0 && p[stp][pa]==0)--stp;
    while(stp>=0){
        if(!isanc(p[stp][pa],pb))pa=p[stp][pa];
        --stp;
    }
    if(!isanc(pa,pb))pa=p[0][pa];
    return pa;
}
inline int getpa(int pa,int stp){
    for(int i=0;(1<<i)<=stp;++i){
        if(stp&(1<<i)){
            pa=p[i][pa];
        }
    }
    return pa;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0,1);
    for(int i=0;i<=3;++i){
        for(int j=1;j<=n;++j){
            cout<<p[i][j]<<" ";
        } cout<<endl;
    }
    while(q--){
        int s,t,k; cin>>s>>t>>k;
        int ca=getlca(s,t);
        if(k>d[s]+d[t]-d[ca]*2)cout<<-1<<endl;
        else if(k<=d[s]-d[ca])cout<<getpa(s,k)<<endl;
        else cout<<getpa(t,d[s]+d[t]-d[ca]*2-k)<<endl;
    }
}
