#include<bits/stdc++.h>
using namespace std;
string gl[105];
int G[1005][1005];
long long t[105];
bool gone[1005];

int n,v,e;

void dfs(int now,long long len){
    gone[now]=1;
    if(now && now<=n){
        t[now]+=len;
    }
    for(int i=1;i<v;i++){
        if(G[now][i] && !gone[i]){
            dfs(i,len+G[now][i]);
        }
    }
    gone[now]=0;
}

int main(){
    int games;
    cin>>games;
    for(int game=1;game<=games;game++){
        memset(t,0,sizeof(t));
        memset(G,0,sizeof(G));
        memset(gone,0,sizeof(gone));
        cout<<"Game #"<<game<<'\n';
        cin>>n>>v>>e;
        for(int i=1;i<=n;i++){
            cin>>gl[i];
        }
        while(e--){
            int x,y,z;
            cin>>x>>y>>z;
            G[x][y]=G[y][x]=z;
        }
        dfs(0,0);
        for(int i=1;i<=n;i++){
            cout<<gl[i]<<": "<<t[i]<<'\n';
        }
    }
}
