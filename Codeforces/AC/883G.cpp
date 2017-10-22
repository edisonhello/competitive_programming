#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> G[300007];
bool gdr[300007];
int cnt=0;
bitset<300007> v;
void dfsmax(int now,int pa){
    if(v[now])return;
    v[now]=1; ++cnt;
    for(auto i:G[now]){
        if(i.X==pa)continue;
        if(i.Y==0)dfsmax(i.X,now);
        else{
            if(i.Y>0)gdr[i.Y]=1,dfsmax(i.X,now);
            else gdr[-i.Y]=0,dfsmax(i.X,now);
        }
    }
}
void dfsmin(int now,int pa){
    if(v[now])return;
    v[now]=1; ++cnt;
    for(auto i:G[now]){
        if(i.X==pa)continue;
        if(i.Y==0)dfsmin(i.X,now);
        else{
            if(i.Y>0)gdr[i.Y]=0;
            else gdr[-i.Y]=1;
        }
    }
}
int domax(int st){
    dfsmax(st,0);
    return cnt;
}
int domin(int st){
    dfsmin((v.reset(),st),cnt=0);
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,s; cin>>n>>m>>s;
    int unds=0;
    for(int i=1;i<=m;++i){
        int t,u,v; cin>>t>>u>>v;
        if(t==1){
            G[u].push_back(pair<int,int>(v,0));
        }
        else{
            unds++;
            G[u].push_back(pair<int,int>(v,unds));
            G[v].push_back(pair<int,int>(u,-unds));
        }
    }
    cout<<domax(s)<<endl;
    for(int i=1;i<=unds;++i)cout<<(gdr[i]?'+':'-'); cout<<endl;
    cout<<domin(s)<<endl;
    for(int i=1;i<=unds;++i)cout<<(gdr[i]?'+':'-'); cout<<endl;
}
