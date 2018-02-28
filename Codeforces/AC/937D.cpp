#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005];
int v[100005][2],dp[100005][2],go[100005][2];
bitset<100005> indfs;
bool circle;

int dfs(int now,int clr){
    // cout<<now<<" "<<clr<<endl;
    if(v[now][clr] || dp[now][clr])return dp[now][clr];
    if(G[now].empty())return clr;
    // cout<<"keep dfs"<<endl;
    ++v[now][clr];
    indfs[now]=1;
    for(int i:G[now])if(!indfs[i]){
        int res=dfs(i,clr^1);
        if(res){go[now][clr]=i,dp[now][clr]=1; break;}
        if(indfs[i])circle=1;
    }
    if(!dp[now][clr])for(int i:G[now])if(indfs[i]){
        int res=dfs(i,clr^1);
        if(res){go[now][clr]=i,dp[now][clr]=1; break;}
        if(indfs[i])circle=1;
    }
    indfs[now]=0;
    return dp[now][clr];
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        int c; cin>>c; 
        G[i].resize(c);
        for(int j=0;j<c;++j)cin>>G[i][j];
    }
    int s; cin>>s;
    int res=dfs(s,0);
    if(res){
        cout<<"Win"<<endl;
        int clr=0;
        while(s){
            cout<<s<<" ";
            s=go[s][clr];
            clr^=1;
        }
    }
    else if(circle)cout<<"Draw"<<endl;
    else cout<<"Lose"<<endl;
}
