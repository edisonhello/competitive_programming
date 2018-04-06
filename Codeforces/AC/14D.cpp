#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> G[202];
bitset<222> ok,v;


int dfs1(int now,int pa,int dis,int dep){
    if(now==dis){
        ok[now]=0;
        return dep;
    }
    for(int i:G[now]){
        if(i==pa)continue;
        int r=dfs1(i,now,dis,dep+1);
        if(r){
            ok[now]=0;
            return r;
        }
    }
    return 0;
}

int getdis(int s,int t){
    return dfs1(s,s,t,0);
}

int d[222];
bitset<222> ths;
vector<int> re;

void dfs2(int now,int pa){
    ths[now]=1;
    re.push_back(now);
    for(int i:G[now]){
        if(i==pa || !ok[i])continue;
        d[i]=d[now]+1;
        dfs2(i,now);
    }
}

int getdia(int p1){
    d[p1]=0;
    dfs2(p1,p1);
    int mx=0,p;
    for(int i:re)mx=max(mx,d[i]);
    for(int i:re)if(mx==d[i])p=i;
    d[p]=0;
    dfs2(p,p);
    mx=0;
    for(int i:re)mx=max(mx,d[i]);
    for(int i:re)ths[i]=0,v[i]=1;
    re.clear();
    return mx;
}

int main(){
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ok.set();
            int l1=getdis(i,j);
            v.reset();
            // cout<<"dis of "<<i<<" "<<j<<" : "<<l1<<endl;
            for(int k=1;k<=n;++k){
                if(ok[k] && !v[k]){
                    int dia=getdia(k);
                    // cout<<"belong "<<k<<" dia: "<<dia<<endl;
                    ans=max(ans,l1*dia);
                }
            }
        }
    }
    cout<<ans<<endl;
}
