#include<bits/stdc++.h>
using namespace std;
int c[10004];
vector<int> G[10004];
int dfs(int now,int pa,int clr){
    int rt=(clr!=c[now]);
    for(int i:G[now]){
        if(i==pa)continue;
        rt+=dfs(i,now,c[now]);
    }
    return rt;
}
int main(){
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int p; cin>>p; --p;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    for(int i=0;i<n;++i)cin>>c[i];
    cout<<dfs(0,0,0)<<endl;
}
