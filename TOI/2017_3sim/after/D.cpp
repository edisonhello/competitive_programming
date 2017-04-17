#include<bits/stdc++.h>

using namespace std;

vector<int> G[88];
bool vis[88];
int mx,n;

void dfs(int now,int ch){
    if(now==n){
        mx=max(mx,ch);
        return;
    }
    if(n-now<=mx-ch)return;
    bool al=1;
    for(int i:G[now])if(vis[i])al=0;
    int nmx=0;
    if(al){
        vis[now]=1;
        dfs(now+1,ch+1);
        vis[now]=0;
    }
    dfs(now+1,ch);
}
void jizz(){
    printf("%d\n",(dfs(0,0),mx));
    exit(0);
}


int __match[88];


bool __dfs(int now){
    for(int &i:G[now]){
        if(vis[i])continue;
        vis[i]=1;
        if(__match[i]==-1 || __dfs(__match[i])){
            __match[i]=now;
            __match[now]=i;
            return 1;
        }
    }
    return 0;
}

int main(){
    int m,u,v;scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&u,&v);
        G[u].push_back(v), G[v].push_back(u);
    }
    if(n<=40)jizz();
    memset(__match,-1,sizeof(__match));
    int ans=0;
    for(int i=0;i<n;++i){
        if(__match[i]==-1){
            memset(vis,0,sizeof(vis));
            if(__dfs(i))++ans;
            // for(int ii=0;ii<n;++ii)cout<<match[ii]<<" ";cout<<endl;
        }
    }
    printf("%d\n",max(n-ans,ans));
}
