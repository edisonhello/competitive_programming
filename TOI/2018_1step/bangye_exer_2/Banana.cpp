#include<bits/stdc++.h>
using namespace std;

bitset<100005> incircle,circlev;
int w[100005],deg[100005],a[200005],dp[2][100005],mxsuf[100005],mxpre[100005];
vector<int> G[100005];

void dpdfs(int now,int pa){
    dp[1][now]+=w[now];
    for(int i:G[now]){
        if(!incircle[i] && i!=pa){
            dpdfs(i,now);
            dp[1][now]+=max(0,dp[1][i]);
            dp[0][now]=max(dp[0][now],max(dp[0][i],dp[1][i]));
        }
    }
    // cout<<"dpdfs "<<now<<" "<<dp[0][now]<<" "<<dp[1][now]<<endl;
}

int dfs(int now,int ptr){
    // cout<<"dfs "<<now<<" "<<ptr<<endl;
    circlev[now]=1;
    a[ptr]=w[now];
    int nx=-1;
    for(int i:G[now]){
        if(incircle[i] && !circlev[i])nx=i;
        else if(!incircle[i]){
            dpdfs(i,i);
            a[ptr]+=max(0,dp[1][i]);
        }
    }
    ++ptr;
    if(nx==-1)return ptr;
    return dfs(nx,ptr);
}

void go(int n){
    incircle.set();
    circlev.reset();
    memset(a,0,sizeof(a));
    memset(deg,0,sizeof(deg));
    memset(dp,0,sizeof(dp));
    memset(mxsuf,0,sizeof(mxsuf));
    memset(mxpre,0,sizeof(mxpre));
    for(int i=0;i<n;++i){
        cin>>w[i];
        G[i].clear();
    }
    for(int i=0;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    for(int i=0;i<n;++i){
        if(deg[i]==1){
            int now=i;
            while(deg[now]==1){
                --deg[now];
                incircle[now]=0;
                for(int ii:G[now])if(incircle[ii]){
                    --deg[ii];
                    if(deg[ii]==1){
                        now=ii;
                        break;
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;++i)cout<<i<<" "<<incircle[i]<<endl;
    int loophead=-1;
    for(int i=0;i<n;++i)if(incircle[i]){loophead=i; break;}
    int sz=dfs(loophead,0);
    // cout<<sz<<endl;
    int mx=0,now=0;
    for(int i=0;i<sz;++i){
        now+=a[i];
        now=max(now,0);
        mx=max(mx,now);
        // cout<<i<<" "<<a[i]<<endl;
    }
    int prenow=0;
    for(int i=0;i<sz;++i){
        prenow+=a[i];
        mxpre[i]=max(i?mxpre[i-1]:-(1<<30),prenow);
    }
    int sufnow=0;
    for(int i=sz-1;i>=0;--i){
        sufnow+=a[i];
        mxsuf[i]=max(i==sz-1?-(1<<30):mxsuf[i+1],sufnow);
    }
    for(int i=1;i<sz;++i)mx=max(mx,mxpre[i-1]+mxsuf[i]);
    cout<<max(0,mx)<<endl;
}   

int main(){ios_base::sync_with_stdio(0);cin.tie(0);int n;while(cin>>n,n){go(n);}}
