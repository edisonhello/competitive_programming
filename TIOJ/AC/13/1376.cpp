#include<iostream>
#include<cstring>
using namespace std;

int n,m,mx[10],my[10];
bool G[10][10],v[10];

bool dfs(int now){
    for(int i=0;i<n;++i){
        if(G[now][i] && !v[i]){
            v[i]=1;
            if(my[i]==-1 || dfs(my[i])){
                mx[now]=i;
                my[i]=now;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin>>n>>m;
    {int x,y;while(m--){
        cin>>x>>y;
        G[x][y]=1;
    }}
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    int mch=0;
    for(int i=0;i<n;++i){
        memset(v,0,sizeof(v));
        if(dfs(i))++mch;
    }
    cout<<mch<<endl;
}
