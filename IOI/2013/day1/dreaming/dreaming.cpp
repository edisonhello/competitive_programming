#include "grader.h"

#include<bits/stdc++.h>
using namespace std;


int djs[100005];
vector<pair<int,int>> G[100005];

bitset<100005> v;

int F(int x){ return x==djs[x]?x:djs[x]=F(djs[x]); }
void U(int x,int y){ djs[F(x)]=F(y); }
bool C(int x,int y){ return F(x)==F(y); }

vector<int> mem;
int d[100005],p[100005];

void dfs1(int now,int pa){
    mem.push_back(now);
    for(auto p:G[now]){
        if(p.first==pa)continue;
        d[p.first]=d[now]+p.second;
        dfs1(p.first,now);
    }
}
void dfs2(int now,int pa){
    p[now]=pa;
    for(auto p:G[now]){
        if(p.first==pa)continue;
        d[p.first]=d[now]+p.second;
        dfs2(p.first,now);
    }
}

int self_max;

int pro1(int x){
    mem.clear(); d[x]=0;
    dfs1(x,-1);
    int far=-1;
    for(int i:mem)far=max(far,d[i]);
    int fid=-1;
    for(int i:mem)if(d[i]==far)fid=i;
    d[fid]=0;
    dfs2(fid,-1);
    far=-1;
    for(int i:mem)far=max(far,d[i]);
    self_max=max(self_max,far);
    int fi2=-1;
    for(int i:mem)if(d[i]==far)fi2=i;
    int mn=1e9;
    while(fi2!=-1)mn=min(mn,max(d[fi2],far-d[fi2])),fi2=p[fi2];
    return mn;
}

int travelTime(int n,int m,int l,int a[],int b[],int t[]){
    for(int i=0;i<n;++i)djs[i]=i;
    for(int i=0;i<m;++i){
        G[a[i]].emplace_back(b[i],t[i]);
        G[b[i]].emplace_back(a[i],t[i]);
        U(a[i],b[i]);
    }
    vector<int> fs;
    for(int i=0;i<n;++i){
        if(v[F(i)])continue;
        v[F(i)]=1;
        fs.push_back(pro1(F(i)));
    }
    /* cout<<"fs cont: ";
    for(int i:fs)cout<<i<<" ";
    cout<<endl; */
    int mn=1e9;
    vector<int> mxd=fs;
    sort(mxd.begin(),mxd.end(),greater<int>());
    mxd.resize(3,-1e9);

    for(int i:fs){
        int mx=self_max;
        mx=max(mx,(i==mxd[0]?mxd[1]:mxd[0])+l+i);
        if(mxd.size()>2u){
            mx=max(mx,(i==mxd[0]?mxd[1]+mxd[2]:i==mxd[1]?mxd[0]+mxd[2]:mxd[0]+mxd[1])+l+l);
        }
        mn=min(mn,mx);
    }
    return mn;
}

