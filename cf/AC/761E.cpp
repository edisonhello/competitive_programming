#include<iostream>
using namespace std;
#include<vector>
#include<cmath>
#define ll long long
// #define xm ((xl+xr)>>1)
// #define ym ((yl+yr)>>1)

vector<int> G[35];
ll x[35],y[35];

void dfs(int n,int p,int dir,ll cx,ll cy,int dep){
    //cout<<"dfs n="<<n<<", p="<<p<<", dir="<<dir<<endl;
    if(dir==1)x[n]=cx+(1ll<<dep),y[n]=cy;
    if(dir==2)x[n]=cx,y[n]=cy+(1ll<<dep);
    if(dir==3)x[n]=cx-(1ll<<dep),y[n]=cy;
    if(dir==4)x[n]=cx,y[n]=cy-(1ll<<dep);

    int cnt=1;
    for(auto &i:G[n]){
        if(i==p)continue;
        if(abs(cnt-dir)==2){++cnt;}
        if(cnt==1)dfs(i,n,cnt,x[n],y[n],dep-1);
        else if(cnt==2)dfs(i,n,cnt,x[n],y[n],dep-1);
        else if(cnt==3)dfs(i,n,cnt,x[n],y[n],dep-1);
        else if(cnt==4)dfs(i,n,cnt,x[n],y[n],dep-1);
        ++cnt;
    }
}

int main(){
    int n;cin>>n;
    for(int i=1,s,t;i<n;++i){
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    for(int i=1;i<=n;++i){
        if(G[i].size()>4u){
            cout<<"NO\n";
            return 0;
        }
    }
    int cnt=1;
    for(auto &i:G[1]){
        if(cnt==1)dfs(i,1,cnt,0ll,0ll,58);
        else if(cnt==2)dfs(i,1,cnt,0ll,0ll,58);
        else if(cnt==3)dfs(i,1,cnt,0ll,0ll,58);
        else if(cnt==4)dfs(i,1,cnt,0ll,0ll,58);
        ++cnt;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;++i){
        cout<<x[i]<<" "<<y[i]<<endl;
    }
}
