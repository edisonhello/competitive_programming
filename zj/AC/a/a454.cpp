#include<bits/stdc++.h>
using namespace std;
int cst[1005],t[1005],dg[1005],mxt;
vector<int> G[1005];
void dfs(int now,int nt){
    // cout<<"dfs: "<<now<<" "<<nt<<endl;
    if(nt<=t[now])return;
    t[now]=nt;
    mxt=max({mxt,t[now]});
    for(int i=0;i<(int)G[now].size();++i){
        dfs(G[now][i],nt+cst[G[now][i]]);
    }
}
int main(){
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        mxt=0;
        memset(t,0,sizeof(t));
        memset(dg,0,sizeof(dg));
        memset(cst,0,sizeof(cst));
        for(int i=1;i<=n;++i){
            G[i].clear();
        }
        for(int i=1;i<=n;++i){
            cin>>cst[i];
            int cons;cin>>cons;
            while(cons--){
                int conn;cin>>conn;
                dg[conn]++;
                G[i].push_back(conn);
            }
        }
        for(int i=1;i<=n;++i){
            if(dg[i]==0){
                dfs(i,cst[i]);
            }
        }
        cout<<mxt<<endl;
    }
}
