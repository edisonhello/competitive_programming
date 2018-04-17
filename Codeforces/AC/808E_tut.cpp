#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[300005],pre[100005];

vector<int> w[5];

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        int wz,c; cin>>wz>>c;
        w[wz].push_back(c);
    }
    sort(w[1].begin(),w[1].end(),greater<int>());
    sort(w[2].begin(),w[2].end(),greater<int>());
    sort(w[3].begin(),w[3].end(),greater<int>());
    vector<int> all;
    for(int i:w[2])all.push_back(i);
    for(int i=1;i<w[1].size();i+=2)all.push_back(w[1][i]+w[1][i-1]);
    sort(all.begin(),all.end(),greater<int>());
    ll now=0;
    for(int i=0;i<all.size();++i){
        now+=all[i];
        dp[i*2+2]=now;
    }
    if(w[1].size()){
        all.clear();
        for(int i:w[2])all.push_back(i);
        for(int i=2;i<w[1].size();i+=2)all.push_back(w[1][i]+w[1][i-1]);
        sort(all.begin(),all.end(),greater<int>());
        ll now=dp[1]=w[1][0];
        for(int i=0;i<all.size();++i){
            now+=all[i];
            dp[i*2+3]=now;
        }
    }
    for(int i=1;i<=m;++i)dp[i]=max(dp[i],dp[i-1]);
    // for(int i=1;i<=m;++i)cout<<"dp["<<i<<"]="<<dp[i]<<endl;
    sort(w[3].begin(),w[3].end(),greater<int>());
    for(int i=1;i<=w[3].size();++i)pre[i]=pre[i-1]+w[3][i-1];
    ll ans=0;
    for(int i=0;i<=w[3].size();++i){
        ll na=pre[i];
        int le=m-i*3;
        if(le<0)break;
        na+=dp[le];
        ans=max(na,ans);
    }
    cout<<ans<<endl;
}
