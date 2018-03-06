#include<bits/stdc++.h>
using namespace std;

short m[1000005],allmin=6666;
int at[1000005],want[1000005],pos[1000005];
vector<int> w[6666];
bitset<1000005> v;
int csize;

long long dfs(int now,long long tot,int mn){
    if(v[now]){
        return min(tot-mn+mn*(csize-1),allmin*(csize+1)+tot+mn);
    }
    v[now]=1;
    ++csize;
    return dfs(pos[want[now]],tot+m[now],min(mn,(int)m[now]));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>m[i],allmin=min(allmin,m[i]);
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        at[t]=i;
        pos[i]=t;
    }
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        want[t]=i;
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        if(want[i]==at[i])continue;
        if(v[i])continue;
        csize=0;
        ans+=dfs(i,0,6666);
    }
    cout<<ans<<endl;
}
