#include<bits/stdc++.h>
using namespace std;

int c[1232];
unordered_map<long long,int> dp;

int dfs(int ptr,int now){
    if(ptr<=0)return 0;
    auto it=dp.find(1ll*now*1200+ptr);
    if(it!=dp.end())return it->second;

    int &rt=dp[1ll*now*1200+ptr];
    rt=max(rt,dfs(ptr-1,min(now,c[ptr]-1)));
    // if(now>=c[ptr])rt=max(rt,1+dfs(ptr-1,c[ptr+1]-1-(c[ptr+1]-1)/c[ptr]*c[ptr]));
    if(now>=c[ptr])rt=max(rt,1+dfs(ptr-1,min(c[ptr]-1,now-c[ptr])));
    // cout<<ptr<<" "<<now<<" is "<<rt<<endl;
    return rt;
}

int main(){
    int t; cin>>t; while(t--){
        dp.clear();
        int n; cin>>n;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;++i)cin>>c[i];
        c[n+1]=c[n]*2;
        cout<<dfs(n,2100000000)<<endl;
    }
}
