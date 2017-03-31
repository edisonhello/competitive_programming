#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> G[3000009];
int n,sn[300009],d[300009];

void dfs1(int now,int pa){
    for(int i=0;i<G[now].size();++i){
        if(G[now][i]==pa)continue;
        ++sn[now];
        dfs1(G[now][i],now);
    }
}
void dfs2(int now,int pa,int dep){
    int mxs=0,idx=-1;
    for(int i=0;i<G[now].size();++i){
        if(G[now][i]==pa)continue;
        if(sn[G[now][i]])
    }
    if(idx==-1)return;
}

main(){
    cin>>n; if(n==1)return cout<<"0\n",0;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
    }
    dfs1(1,1);
    dfs2(1,1,1);
//     for(int i=1;i<=n;++i)pd[i]=pd[i-1]+d[i];
// #ifdef WEAK
//     for(int i=1;i<=4;++i)cout<<d[i]<<" ";cout<<endl;
//     for(int i=1;i<=4;++i)cout<<pd[i]<<" ";cout<<endl;
// #endif
//     int L=1,R=n;
//     while(R>L){
//         int M=(L+R)>>1;
//         // cout<<M<<" "<<chk(M)<<endl;
//         if(chk(M))R=M;
//         else L=M+1;
//     }
//     cout<<L<<endl;
}
