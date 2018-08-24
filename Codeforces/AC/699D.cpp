#include<bits/stdc++.h>

using namespace std;

int pa[200005],djs[200005],vis[200005];

int F(int x){ return x==djs[x]?x:djs[x]=F(djs[x]); }

int main(){
    int n; cin>>n;
    int same=0;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=n;++i)cin>>pa[i];
    for(int i=1;i<=n;++i)djs[F(i)]=F(pa[i]);
    int root=-1;
    for(int i=1;i<=n;++i)if(i==pa[i])root=i;
    int diff=0,ses=0;
    if(root==-1){
        int now=1;
        for(int cnt=n+5;--cnt;)now=pa[now];
        diff=1;
        pa[now]=now;
        root=now;
        for(int i=1;i<=n;++i)djs[i]=i;
        for(int i=1;i<=n;++i)djs[F(i)]=F(pa[i]);
    }
    for(int i=1;i<=n;++i){
        if(F(i)==F(root))continue;
        int now=i;
        ++ses;
        while(!vis[now]){
            vis[now]=ses;
            now=pa[now];
        }
        if(vis[now]==ses)pa[now]=root,djs[F(now)]=F(root),++diff;
    }
    cout<<diff<<endl;
    for(int i=1;i<=n;++i)cout<<pa[i]<<" ";
}
