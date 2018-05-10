#include<bits/stdc++.h>
using namespace std;

void spec(int n,int k){
    if(n==1)exit((cout<<k<<endl,0));
    if(n==2)exit((cout<<k+1<<endl,0));
}

bitset<100005> isdia,v;
vector<int> G[100005];
int dis[100005],p[100005],mxch[100005],pre[100005],suf[100005];

void dfs1(int now,int pa){
    p[now]=pa;
    for(int i:G[now]){
        if(i==pa)continue;
        dis[i]=dis[now]+1;
        dfs1(i,now);
    }
}

vector<int> mem,dias;
void dfs2(int now,int pa){
    v[now]=1;
    mem.push_back(now);
    for(int i:G[now]){
        if(i==pa || isdia[i])continue;
        dis[i]=dis[now]+1;
        dfs2(i,now);
    }
}
int dfs3(int now,int pa,int dep){
    int rt=dep;
    for(int i:G[now]){
        if(i==pa)continue;
        rt=max(rt,dfs3(i,now,dep+1));
    }
    return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    spec(n,k);
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    { int far=max_element(dis+1,dis+1+n)-dis; dis[far]=0; dfs1(far,0); }
    int d1=max_element(dis+1,dis+1+n)-dis,d2=d1; isdia[d1]=1; dias.push_back(d1);
    int dia=dis[d1];
    if(k==1){ cout<<n*2-dia-1<<endl; exit(0); }
    while(p[d2]){
        d2=p[d2];
        isdia[d2]=1;
        dias.push_back(d2);
    }
    int ans=n*2-dia;
    for(int i=1;i<=n;++i){
        if(isdia[i] || v[i])continue;
        mem.clear(); dis[i]=0;
        dfs2(i,0);
        { int far=-1,fd=-1; for(int i:mem)dis[i]>fd?fd=dis[i],far=i:0; dis[far]=0; mem.clear(); dfs2(far,0); }
        int mx=0;
        for(int i:mem)mx=max(mx,dis[i]);
        ans=min(ans,n*2-dia-mx);
    }
    for(int i=1;i<=n;++i){
        if(!isdia[i])continue;
        vector<int> ji;
        for(int j:G[i]){
            if(isdia[j])continue;
            int len=dfs3(j,i,1);
            ji.push_back(len);
        }
        while(ji.size()<2u)ji.push_back(0);
        sort(ji.begin(),ji.end(),greater<int>());
        ans=min(ans,n*2-dia-ji[0]-ji[1]);
        mxch[i]=ji[0];
    }
    for(int i=1;i<dias.size();++i){
        pre[dias[i]]=max(pre[dias[i-1]],i+mxch[dias[i]]);
    }
    for(int i=dias.size()-2;i>=0;--i){
        suf[dias[i]]=max(suf[dias[i+1]],(int)dias.size()-1-i+mxch[dias[i]]);
    }
    for(int i=1;i<dias.size();++i){
        ans=min(ans,n*2-pre[dias[i-1]]-suf[dias[i]]);
    }
    cout<<ans<<endl;
}
