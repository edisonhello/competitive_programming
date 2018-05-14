
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll tot;
vector<int> oG[100005],bel[100005],G[100005];

int n,sz[100005],cnt[100005],djs[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

void dfs(int now,int pa,int cnt){
    sz[now]=1;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,cnt);
        sz[now]+=sz[i];
    }
    for(int i:G[now]){
        if(i==pa)continue;
        tot+=1ll*sz[i]*(cnt-sz[i]-1);
    }
    tot+=1ll*(cnt-sz[now])*(sz[now]-1);
}

bool go(int s,int t,int z){
    if(z&(1<<s)); else return 0;
    if(z&(1<<t)); else return 0;
    z^=(1<<s);
    queue<int> q; q.push(s);
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i:G[now]){
            if(z&(1<<i)){
                q.push(i);
                z^=(1<<i);
            }
        }
    }
    return !(z&(1<<t));
}

int main(){
    int m; cin>>n>>m;
//    if(m!=n-1)exit(1);
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v; --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
        djs[F(u)]=F(v);
    }
    for(int i=0;i<n;++i){
        ++cnt[F(i)];
        bel[F(i)].push_back(i);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                if(i==j || i==k || j==k)continue;
                bool ok=0;
                for(int z=0;z<(1<<n);++z){
                    if(z&(1<<i))continue;
                    if(z&(1<<j))continue;
                    if(z&(1<<k))continue;
//                    cout<<i<<" "<<j<<" "<<k<<" "<<bitset<10>(z)<<" "<<bitset<10>(z|(1<<i)|(1<<j))<<" "<<bitset<10>(z^((1<<n)-1)^(1<<i))<<endl;
                    if(go(i,j,z|(1<<i)|(1<<j)) && go(j,k,z^((1<<n)-1)^(1<<i))){
//                        cout<<bitset<10>(z)<<endl;
                        ok=1;
                        break;
                    }
                }
                tot+=ok;
//                if(ok)cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
//    dfs(1);
    cout<<tot<<endl;
}
