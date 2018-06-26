#include<bits/stdc++.h>
using namespace std;

struct edge{
    int i,to,rev;
};
vector<edge> G[200005];

bitset<200005> v;
int s[200005],ans[200005];

int dfs(int now){
    // cout<<"dfs "<<now<<endl;
    v[now]=1;
    int rt=s[now];
    for(auto e:G[now]){
        if(v[e.to])continue;
        int r=dfs(e.to);
        if(!e.rev){
            ans[e.i]+=r;
            rt+=r;
        }
        else{
            ans[e.i]-=r;
            rt+=r;
        }
    }
    // cout<<now<<" return "<<rt<<endl;
    return rt;
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i];
    int m; cin>>m;
    for(int i=0;i<m;++i){
        int x,y; cin>>x>>y;
        G[x].push_back({i,y,0});
        G[y].push_back({i,x,1});
    }
    for(int i=1;i<=n;++i){
        if(!v[i]){
            if(dfs(i)){
                cout<<"Impossible"<<endl;
                exit(0);
            }
        }
    }
    cout<<"Possible"<<endl;
    for(int i=0;i<m;++i)cout<<ans[i]<<'\n';
}
