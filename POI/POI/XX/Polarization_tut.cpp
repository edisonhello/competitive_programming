#include<bits/stdc++.h>
using namespace std;

vector<int> G[250004];
int n,sz[250004],p[250004];
bitset<250004> icen;

void dfs1(int now,int pa){
    p[now]=pa;
    int mx=0;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs1(i,now);
        sz[now]+=sz[i];
        mx=max(mx,sz[i]);
    }
    ++sz[now];
    if(max(mx,n-sz[now])<=n/2)icen[now]=1;
}

long long dfs2(int now,int pa,int ups){
    long long rt=ups;
    for(int i:G[now]){
        if(i!=pa)rt+=dfs2(i,now,ups+1);
    }
    return rt;
}

int cnt[250004];
long long sol(int x){
    // cout<<"sol: "<<x<<endl;
    vector<int> chs;
    for(int i:G[x]){
        if(i==p[x])chs.push_back(n-sz[x]);
        else chs.push_back(sz[i]);
    }
    memset(cnt,0,sizeof(cnt));
    for(int i:chs)++cnt[i];
    bitset<250004> go;
    go[0]=1;
    for(int i=1;i<=n;++i){
        if(!cnt[i])continue;
        // cout<<i<<" "<<cnt[i]<<endl;
        int x=i,u=1,le=cnt[i];
        while(u<=le){
            go|=(go<<x);
            le-=u;
            x<<=1;
            u<<=1;
        }
        if(le)go|=(go<<(le*i));
    }
    int z=n/2;
    while(!go[z])--z;
    int y=n-1-z;
    // cout<<"yz: "<<y<<" "<<z<<endl;
    long long base=1ll*(y+1)*(z+1)-1;
    for(int i:G[x])base+=dfs2(i,x,0);
    return base;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    long long mx=0;
    for(int i=1;i<=n;++i)if(icen[i]){ mx=max(mx,sol(i)); break; }
    cout<<n-1<<" ";
    cout<<mx<<endl;
}
