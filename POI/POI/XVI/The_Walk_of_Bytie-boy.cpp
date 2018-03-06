#include<bits/stdc++.h>
using namespace std;

int n;
bitset<26> G[402][402],iG[402][402];

struct status{
    int ss,tt;
    string ans;
};

void solve(int s,int t){
    bitset<402> vis;
    vis[s]=vis[t]=1;
    bool ok=1,half=0;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m; cin>>n>>m;
    while(m--){
        int u,v; char c;
        cin>>u>>v>>c;
        G[u][v][c]=1;
        iG[v][u][c]=1;
    }
    int d; cin>>d;
    int prv; cin>>prv; --d;
    while(d--){
        int now; cin>>now;
        solve(prv,now);
        prv=now;
    }
}
