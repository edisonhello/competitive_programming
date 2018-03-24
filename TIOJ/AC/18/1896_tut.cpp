#include<bits/stdc++.h>
using namespace std;
#ifndef WEAK
#include "lib1896.h"
#endif
int n;
int cnt[1555],edged,at,tot;
void initialize(int _n){
    edged=at=0;
    memset(cnt,0,sizeof(cnt));
    n=_n;
    tot=n*(n-1)/2;
}
int hasEdge(int u,int v){
    if(u>v)swap(u,v);
    ++cnt[v]; ++at;
    return cnt[v]==v;
}

#ifdef WEAK
int main(){
    int n; while(cin>>n){
        initialize(n);
        for(int i=0;i<n*(n-1)/2;++i){
            int u,v; cin>>u>>v;
            cout<<hasEdge(u,v)<<endl;
        }
    }
}
#endif
