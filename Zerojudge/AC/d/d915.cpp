#include<bits/stdc++.h>
using namespace std;

int deg[1505],d[1505][1505],w[1505][1505],dp[1<<15];
vector<int> odd;

int dfs(int x,int now){
    if(dp[x])return dp[x];
    if(x==0)return 0;
    while(!(x&(1<<now)))--now;
    int xx=x^(1<<now),a=now;
    dp[x]=19191919;
    for(int val;now>=0;--now){
        if((xx&(1<<now)) && (val=dfs(xx^(1<<now),a-1))+d[odd[a]][odd[now]]<dp[x]){
            dp[x]=(val=dfs(xx^(1<<now),a-1))+d[odd[a]][odd[now]];
        }
    }
    return dp[x];
}

void floyd(int s,const int n){
    int *dd=d[s];
    memset(dd,0x3f,sizeof(int)*1505);
    dd[s]=0;
    bitset<1505> v;
    for(int _=0;_<n;++_){
        int np=-1,dst=0x3f3f3f3f;
        for(int i=1;i<=n;++i){
            if(!v[i] && dd[i]<dst){
                np=i;
                dst=dd[i];
            }
        }
        // cout<<"np: "<<np<<endl;
        v[np]=1;
        for(int i=1;i<=n;++i){
            if(!v[i] && dd[i]>dd[np]+w[np][i]){
                dd[i]=dd[np]+w[np][i];
            }
        }
    }
    // cout<<"s: "<<s<<" ~ "; for(int i=1;i<=n;++i)cout<<d[s][i]<<" "; cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,s,tot=0; cin>>n>>m>>s;
    memset(w,0x3f,sizeof(w));
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        w[a][b]=w[b][a]=c;
        ++deg[a], ++deg[b];
        tot+=c;
    }
    for(int i=1;i<=n;++i)if(deg[i]&1)odd.push_back(i);
    for(int i:odd)floyd(i,n);
    tot+=dfs((1<<odd.size())-1,odd.size()-1);
    cout<<tot<<endl;
}
