#include<bits/stdc++.h>
using namespace std;

set<int> st[1003];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;++i){
        int t; cin>>t; while(t--){
            int tt; cin>>tt;
            st[i].insert(tt);
        }
    }
    while(q--){
        int u,v; cin>>u>>v;
        int c1=0,c2=0;
        for(int i:st[u]){
            if(st[v].find(i)==st[v].end())++c1;
        }
        for(int i:st[v]){
            if(st[u].find(i)==st[u].end())++c2;
        }
        cout<<c1*c2<<'\n';
    }
}
