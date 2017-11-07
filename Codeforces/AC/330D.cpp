#include<bits/stdc++.h>
using namespace std;

int n,m; 
string mp[1004];
bitset<1004> v[1004];
int dp[1004][1004];
int bfs1(){
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(mp[i][j]=='S'){q.emplace(i,j); break;}
    v[q.front().first][q.front().second]=1;
    while(q.size()){
        if(mp[q.front().first][q.front().second]=='E')break;
        if(mp[q.front().first][q.front().second]=='T'){q.pop(); continue;}
        if(q.front().first>0 && !v[q.front().first-1][q.front().second])v[q.front().first-1][q.front().second]=1,q.emplace(q.front().first-1,q.front().second),dp[q.front().first-1][q.front().second]=dp[q.front().first][q.front().second]+1;
        if(q.front().first<n-1 && !v[q.front().first+1][q.front().second])v[q.front().first+1][q.front().second]=1,q.emplace(q.front().first+1,q.front().second),dp[q.front().first+1][q.front().second]=dp[q.front().first][q.front().second]+1;
        if(q.front().second>0 && !v[q.front().first][q.front().second-1])v[q.front().first][q.front().second-1]=1,q.emplace(q.front().first,q.front().second-1),dp[q.front().first][q.front().second-1]=dp[q.front().first][q.front().second]+1;
        if(q.front().second<m-1 && !v[q.front().first][q.front().second+1])v[q.front().first][q.front().second+1]=1,q.emplace(q.front().first,q.front().second+1),dp[q.front().first][q.front().second+1]=dp[q.front().first][q.front().second]+1;
        q.pop();
    }
    return dp[q.front().first][q.front().second];
}
int bfs2(int step){
    memset(v,0,sizeof(v));
    memset(dp,0,sizeof(dp));
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(mp[i][j]=='E'){q.emplace(i,j); break;}
    v[q.front().first][q.front().second]=1;
    int ans=0;
    while(q.size()){
        if(mp[q.front().first][q.front().second]>='0' && mp[q.front().first][q.front().second]<='9')ans+=mp[q.front().first][q.front().second]-'0';
        if(dp[q.front().first][q.front().second]>=step){q.pop(); continue;}
        if(mp[q.front().first][q.front().second]=='T'){q.pop(); continue;}
        if(q.front().first>0 && !v[q.front().first-1][q.front().second])v[q.front().first-1][q.front().second]=1,q.emplace(q.front().first-1,q.front().second),dp[q.front().first-1][q.front().second]=dp[q.front().first][q.front().second]+1;
        if(q.front().first<n-1 && !v[q.front().first+1][q.front().second])v[q.front().first+1][q.front().second]=1,q.emplace(q.front().first+1,q.front().second),dp[q.front().first+1][q.front().second]=dp[q.front().first][q.front().second]+1;
        if(q.front().second>0 && !v[q.front().first][q.front().second-1])v[q.front().first][q.front().second-1]=1,q.emplace(q.front().first,q.front().second-1),dp[q.front().first][q.front().second-1]=dp[q.front().first][q.front().second]+1;
        if(q.front().second<m-1 && !v[q.front().first][q.front().second+1])v[q.front().first][q.front().second+1]=1,q.emplace(q.front().first,q.front().second+1),dp[q.front().first][q.front().second+1]=dp[q.front().first][q.front().second]+1;
        q.pop();
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    int dd=bfs1();
    cout<<bfs2(dd)<<endl;
}
