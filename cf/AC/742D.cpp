#include<algorithm>
#include<iostream>
#include<utility>
#include<vector>
#define X first
#define Y second
using namespace std;

int djs[1005];// bool v[1005];
vector<pair<int,int>> fs[1005];
int F(int x){if(djs[x]==x)return x;return djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);if(x==y)return;djs[x]=y;}

int w[1005],b[1005],dp[1005][1005];

int main(){
    int n,m,wx;cin>>n>>m>>wx;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<=n;++i)djs[i]=i;;
    {int x,y;while(m--){
        cin>>x>>y;U(x,y);
    }}
    for(int i=1;i<=n;++i)fs[F(i)].push_back({w[i],b[i]});
    for(int i=1;i<=n;++i)if(fs[i].size()>1u){
        int tw=0,tb=0;
        for(auto &j:fs[i])tw+=j.X,tb+=j.Y;
        fs[i].push_back({tw,tb});
    }
    int step=0;
    for(int i=1;i<=n;++i){
        if(fs[i].size())++step;
        for(auto &j:fs[i]){
            for(int k=0;k<=wx;++k){
                if(k<j.X)dp[step][k]=max({dp[step][k],dp[step-1][k]});
                else dp[step][k]=max({dp[step][k],dp[step-1][k],dp[step-1][k-j.X]+j.Y});
            }
        }
    }
    // cout<<"step: "<<step<<endl;
    cout<<dp[step][wx]<<endl;
}
