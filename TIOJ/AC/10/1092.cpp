#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> G[10005];
int dp[10005];

int gV(int now){
    if(dp[now]!=-1)return dp[now];
    dp[now]=0;
    for(auto &i:G[now]){
        if(!gV(i))dp[now]=1;
    }
    return dp[now];
}

int main(){
    int n,e;while(cin>>n>>e,(n||e)){
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<=e;++i){
            int a,b;cin>>a>>b;
            G[a].push_back(b);
        }
        string s;cin>>s;
        if(gV(1)){
            if(s=="Mimi")cout<<"Moumou"<<endl;
            else cout<<"Mimi"<<endl;
        }
        else{
            cout<<s<<endl;
        }
    }
}
