#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;

vector<int> G[5005];
int n,m;
bool v[5005];
set<int> nice,bad;

int longestLength=-1,longestPoint,longestPoint2,midPoint;
int dfs1(int now,int dep){
    v[now]=1;
    if(dep>longestLength){
        longestLength=dep;
        longestPoint=now;
    }
    for(int i=0;i<(int)G[now].size();++i){
        if(!v[G[now][i]])dfs1(G[now][i],dep+1);
    }
}
int dfs2(int now,int dep){
    v[now]=1;bool rt=0;
    if(dep==longestLength){
        bad.insert(now);
        rt=1;
    }
    for(int i=0;i<(int)G[now].size();++i){
        if(!v[G[now][i]]){
            if(dfs2(G[now][i],dep+1)){
                rt=1;
            }
        }
    }
    if(rt && dep==longestLength/2)midPoint=now;
    return rt;
}
int dfs3(int now,int dep){
    v[now]=1;
    bool rt=0;
    if(dep==longestLength/2)rt=1;
    if(dep>longestLength/2)return 0;
    for(int i=0;i<(int)G[now].size();++i){
        if(!v[G[now][i]]){
            if(!dfs3(G[now][i],dep+1)){
                return 0;
            }
        }
    }
    return 1;
}
void solve(){
    dfs1(1,0);memset(v,0,sizeof(v));
    longestPoint2=longestPoint;
    dfs1(longestPoint,0);memset(v,0,sizeof(v));
    bad.insert(longestPoint);
    // cout<<longestPoint<<" "<<longestPoint2<<endl;
    dfs2(longestPoint,0);memset(v,0,sizeof(v));
    dfs2(longestPoint2,0);memset(v,0,sizeof(v));
    // cout<<longestPoint<<" "<<longestLength<<" "<<midPoint<<endl;
    if(dfs3(midPoint,0))nice.insert(midPoint);
    memset(v,0,sizeof(v));
    for(int i=0;i<(int)G[midPoint].size();++i){
        if(dfs3(G[midPoint][i],0)){
            nice.insert(G[midPoint][i]);
        }
        memset(v,0,sizeof(v));
    }
    for(int i:nice)cout<<i<<" ";
    cout<<endl;
    for(int i:bad)cout<<i<<" ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    {int a,b;while(m--){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }}
    solve();
}
