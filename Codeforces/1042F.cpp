#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000006],lfs;
int p[1000006],d[1000006],in[1000006],out[1000006],dt;

void dfs(int now,int pa,int dep){
    p[now]=pa;
    d[now]=dep;
    in[now]=++dt;
    for(int i:G[now]){
        if(i!=pa)dfs(i,now,dep+1);
    }
    out[now]=dt;
    if(dt==in[now]){
        lfs.push_back(now);
    }
}

bool isanc(int u,int v){
    return in[u]<=in[v] && out[v]<=out[u];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int rt=-1;
    for(int i=n;i>=1;--i)if(G[i].size()!=1u)rt=i;
    dfs(rt,0,0);
    int ans=0,ll=-1,ppa=-1;
    for(int i:lfs){
        if(ll==-1){
            ll=i; ppa=i; ++ans;
        }
        else{
            while(!isanc(ppa,i))ppa=p[ppa];
            if(d[ll]+d[i]-2*d[ppa]>k){
                ll=i; ppa=i; ++ans;
            }
        }
    }
    cout<<ans<<endl;
}
