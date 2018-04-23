#include<bits/stdc++.h>
using namespace std;

struct info{
    int to,l,w;
    info(int a=0,int b=0,int c=0):to(a),l(b),w(c){}
};

int n,A,B,dp[10004][222];
vector<info> G[10004];

void dfs(int now,int pa){
    dp[now][0]=0;
    if(now!=pa && G[now].size()==1){
        return;
    }
    for(info &e:G[now]){
        if(e.to==pa)continue;
        dfs(e.to,now);
        for(int i=B;i>=e.l;--i){
            // update dp[now][i], all use L=i
            for(int j=0;j<=i;++j){
                if(j<e.l)continue;
                // if(now==4)cout<<i<<" "<<k<<endl;
                // cout<<"updating "<<now<<" "<<i<<" , orig: "<<dp[now][i];
                dp[now][i]=max(dp[now][i],dp[now][i-j]+dp[e.to][j-e.l]+e.w);
                // cout<<" , to "<<dp[now][i]<<" , use "<<dp[now][i-j]<<" + "<<dp[e.to][j-e.l]<<" + "<<e.w<<" , j = "<<j<<endl;
                // cout<<"dp["<<now<<"]["<<i<<"]="<<dp[now][i]<<endl;
            }
        }
    }
    /* cout<<"now: "<<now<<endl;
    for(int i=0;i<=B;++i){
        cout<<"dp["<<now<<"]["<<i<<"]="<<dp[now][i]<<endl;
    } */
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>A>>B;
    for(int i=0;i<=n;++i)for(int j=0;j<222;++j)dp[i][j]=-1e9;
    for(int i=1;i<n;++i){
        int s,t,l,w; cin>>s>>t>>l>>w;
        G[s].emplace_back(t,l,w);
        G[t].emplace_back(s,l,w);
    }
    dfs(0,0);
    double ans=-1e6;
    for(int i=0;i<n;++i){
        for(int j=A;j<=B;++j){
            ans=max(ans,(double)dp[i][j]/j);
        }
    }
    if(ans<0)cout<<-1<<endl;
    else cout<<fixed<<setprecision(12)<<ans<<endl;
}
