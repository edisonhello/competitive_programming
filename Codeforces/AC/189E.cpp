#include<bits/stdc++.h>
using namespace std;

bitset<100005> vul,v;
vector<int> G[100005];
int dp[100005];
bool can(int Q,int s,int t){
    v.reset(); memset(dp,0x3f,sizeof(dp)); dp[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; q.emplace(0,s);
    while(q.size()){
        auto copy=q.top(); q.pop();
        // cout<<copy.first<<" "<<copy.second<<endl;
        if(dp[copy.second]>=Q && !vul[copy.second]);
        else{
            if(vul[copy.second])dp[copy.second]=0;
            if(dp[copy.second]>=Q);
            else for(int i:G[copy.second]){
                if(!v[i] && dp[copy.second]+1<dp[i])dp[i]=dp[copy.second]+1,q.emplace(dp[i],i);
            }
        }
    }
    // cout<<"Q: "<<Q<<" , "; for(int i=1;i<=6;++i)cout<<dp[i]<<" "; cout<<endl;
    return dp[t]!=0x3f3f3f3f;
}
int main(){
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    int t; while(k--)vul[scanf("%d",&t),t]=1;
    int u,v; while(m--)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
    scanf("%d%d",&u,&v);
    int L=0,R=n+1; while(R>L)if(can((L+R)>>1,u,v))R=(L+R)>>1;else L=((L+R)>>1)+1;
    printf("%d\n",L==n+1?-1:L);
}
