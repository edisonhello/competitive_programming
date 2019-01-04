// Source: 2017 ACM ICPC Asia Ho Chi Minh(Vietnam) Regional

#include<bits/stdc++.h>
using namespace std;

string mp[100005];
vector<vector<pair<int,int>>> pass;
int n,m,ext[400005];

int getside(int x){
    if(x<=m)return 0; // up
    if(x<=n+m)return 1; // right
    if(x<=m+n+m)return 2; // down
    return 3; // left
}



int main(){
    ios_Base::sync_with_stdio(0); cin.tie(0);
    int q; cin>>n>>m>>q;
    for(int i=1;i<=n;++i)cin>>mp[i],mp[i]=" "+mp[i];
    pass=vector<vector<pair<int,int>>>(n+2,vector<pair<int,int>>(m+2,make_pair(-1,-1)));
    for(int i=1;i<=m;++i){
        int z=i;
        if(ext[z])continue;
        int o=fdfs(1,i,0);
        ext[z]=o; ext[o]=z;
        sdfs(1,i,0,z,o);
    }
    for(int i=1;i<=n;++i){
        int z=i+m;
        if(ext[z])continue;
        int o=fdfs(i,m,1);
        ext[z]=o; ext[o]=z;
        sdfs(i,m,1,z,o);
    }
    for(int i=m;i>=1;--i){
        int z=m+n+(m+1-i);
        if(ext[z])continue;
        int o=fdfs(n,i,2);
        ext[z]=o; ext[o]=z;
        sdfs(n,i,2,z,o);
    }
    for(int i=n;i>=1;--i){
        int z=m+n+m+(n+1-i);
        if(ext[z])continue;
        int o=fdfs(i,1,3);
        ext[z]=o; ext[o]=z;
        sdfs(i,1,3,z,o);
    }
    while(q--){
        int c; cin>>c;
        if(c==1){
            
        }
        else{
            int y; cin>>y;
            if(getside(ext[y])!=2){ cout<<-1<<'\n'; }
            else{ cout<<m+1-(ext[y]-n-m)<<'\n'; }
        }
    }
}   
