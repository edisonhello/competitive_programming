#include<bits/stdc++.h>
using namespace std;

bitset<133333> jizz;
vector<int> G[133333];
int dep[133333],cf[133333];

void dfs1(int now,int pa,int d){
    dep[now]=d;
    cf[now]=pa;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs1(i,now,d+1);
    }
}

int dfs2(int now,int pa){
    int rt=0;
    for(int i:G[now]){
        if(i==pa)continue;
        int r=dfs2(i,now);
        if(r>=0)rt+=r+1;
    }
    if(!rt && !jizz[now])return -1;
    else return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while(m--){
        int t; cin>>t;
        jizz[t]=1;
    }
    dfs1(1,1,1);
    int mx=-1,mxp;
    for(int i=1;i<=n;++i)if(jizz[i] && dep[i]>mx)mx=dep[i],mxp=i;
    dfs1(mxp,mxp,1);
    mx=-1;
    int pt1=mxp;
    for(int i=1;i<=n;++i)if(jizz[i] && dep[i]>mx)mx=dep[i],mxp=i;
    int pt2=mxp;
    if(pt1==pt2)return cout<<pt1<<"\n0\n",0;
    cout<<min(pt1,pt2)<<endl;
    vector<int> jing;
    jing.push_back(pt2);
    while(pt2!=pt1){
        pt2=cf[pt2];
        jing.push_back(pt2);
    }
    int ans=jing.size()-1;
    for(int i=0;i<jing.size();++i){
        set<int> fbd;
        if(i)fbd.insert(jing[i-1]);
        if(i<jing.size()-1)fbd.insert(jing[i+1]);
        for(int ii:G[jing[i]]){
            if(fbd.find(ii)!=fbd.end())continue;
            int r=dfs2(ii,jing[i]);
            if(r>=0)ans+=2*(r+1);
        }
    } 
    cout<<ans<<endl;
}
