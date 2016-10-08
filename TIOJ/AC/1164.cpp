#include "lib1164.h"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define X first
#define Y second
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// typedef struct { int m, k; int *x, *y, *len; } MAP;

int n;
int ctz[1000006];
MAP mnm,mxm;
vector<pair<int,int>> G[1000006];

int longestrd,longestn;
bool gone[1000006];
void dfs(int now,int len){
    // cout<<"dfs:"<<now<<" "<<len<<endl;
    if(len>longestrd){
        longestrd=len;
        longestn=now;
        // cout<<"update longest n:"<<longestn<<" ,length="<<longestrd<<endl;
    }
    for(int i=0;i<G[now].size();i++){
        if(!gone[G[now][i].X]){
            gone[G[now][i].X]=1;
            dfs(G[now][i].X,len+G[now][i].Y);
        }
    }
}
int findL(int st){
    memset(gone,0,sizeof(gone));
    gone[st]=1;
    longestrd=-99;
    longestn=-1;
    dfs(st,0);
    // cout<<"found farest1:"<<longestn<<endl;
    memset(gone,0,sizeof(gone));
    gone[longestn]=1;
    longestrd=-99;
    dfs(longestn,0);
    // cout<<"found longestrd:"<<longestrd<<endl;
    return longestrd;
}

int main(){
    // ios_base::sync_with_stdio(0);
    n=init();
    for(int i=0;i<n;i++){ctz[i]=i;}
    auto mm=minmax_element(ctz,ctz+n,query);
    // cout<<"minele"<<*mm.first<<" maxele"<<*mm.second<<endl;
    mnm=getct(*mm.first);
    for(int i=0;i<mnm.k;i++){
        G[mnm.x[i]].push_back({mnm.y[i],mnm.len[i]});
        G[mnm.y[i]].push_back({mnm.x[i],mnm.len[i]});
    }
    int mx=findL(0);
    for(int i=0;i<1000006;i++)G[i].clear();
    mxm=getct(*mm.second);
    for(int i=0;i<mxm.k;i++){
        G[mxm.x[i]].push_back({mxm.y[i],mxm.len[i]});
        G[mxm.y[i]].push_back({mxm.x[i],mxm.len[i]});
    }
    // for(int i=0;i<mxm.m;i++){cout<<G[i].size()<<" ";}
    int mn=findL(0);
    answer(mx,mn);
}
