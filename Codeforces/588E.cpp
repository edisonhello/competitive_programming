#include<bits/stdc++.h>
using namespace std;

vector<int> liv[100005];
vector<int> G[100005];
vector<int> mn[17][100005];
int pa[17][100005],dep[100005];

void merge(vector<int> &a,vector<int> &b,vector<int> &r){
    auto it1=a.begin(),it2=b.begin();
    while(int(r.size())<10){
        if(it1==a.end() && it2==b.end())break;
        if(it1==a.end()){
            r.push_back(*it2);
            ++it2;
        }
        else if(it2==b.end()){
            r.push_back(*it1);
            ++it1;
        }
        else if(*it1==*it2){
            r.push_back(*it1);
            ++it1; ++it2;
        }
        else if(*it1<*it2){
            r.push_back(*it1);
            ++it1;
        }
        else{
            r.push_back(*it2);
            ++it2;
        }
    }
}
vector<int> merge(vector<int> &a,vector<int> &b){
    vector<int> r;
    auto it1=a.begin(),it2=b.begin();
    while(int(r.size())<10){
        if(it1==a.end() && it2==b.end())break;
        if(it1==a.end()){
            r.push_back(*it2);
            ++it2;
        }
        else if(it2==b.end()){
            r.push_back(*it1);
            ++it1;
        }
        else if(*it1==*it2){
            r.push_back(*it1);
            ++it1; ++it2;
        }
        else if(*it1<*it2){
            r.push_back(*it1);
            ++it1;
        }
        else{
            r.push_back(*it2);
            ++it2;
        }
    }
    return r;
}
vector<int> merget(vector<int> &a,vector<int> b){
    vector<int> r;
    auto it1=a.begin(),it2=b.begin();
    while(int(r.size())<10){
        if(it1==a.end() && it2==b.end())break;
        else if(it1==a.end()){
            r.push_back(*it2);
            ++it2;
        }
        else if(it2==b.end()){
            r.push_back(*it1);
            ++it1;
        }
        else if(*it1==*it2){
            r.push_back(*it1);
            ++it1; ++it2;
        }
        else if(*it1<*it2){
            r.push_back(*it1);
            ++it1;
        }
        else{
            r.push_back(*it2);
            ++it2;
        }
    }
    return r;
}

void dfs(int now,int p,int d){
    cout<<"dfs "<<now<<" from "<<p<<endl;
    pa[0][now]=p;
    dep[now]=d;
    mn[0][now]=liv[now];
    for(int z=1;(1<<z)<=d;++z){
        pa[z][now]=pa[z-1][pa[z-1][now]];
        merge(mn[z-1][now],mn[z-1][pa[z-1][now]],mn[z][now]);
    }
    for(int i:G[now]){
        if(i==p)continue;
        dfs(i,now,d+1);
    }
}

void getans(int u,int v,vector<int> &rt){
    if(dep[u]>dep[v])return;
    for(int i=0;i<17;++i)if((dep[v]-dep[u])&(1<<i)){
        rt=merge(rt,mn[i][v]);
        v=pa[i][v];
    }
    if(v==u)return;
    for(int i=16;i>=0;--i)if(pa[i][u]!=pa[i][v]){
        rt=merget(rt,merge(mn[i][u],mn[i][v]));
        u=pa[i][u];
        v=pa[i][v];
    }
    rt=merget(rt,merge(mn[0][u],mn[0][v]));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=m;++i){
        int t; cin>>t; if(liv[t].size()<10u)liv[t].push_back(i);
    }
    dfs(1,1,1);
    while(q--){
        int u,v,a; cin>>u>>v>>a;
        vector<int> ans;
        getans(u,v,ans);
        if(int(ans.size())>a)ans.resize(a);
        cout<<a; for(int i:ans)cout<<" "<<i; cout<<'\n';
    }
}
