#include<bits/stdc++.h>
using namespace std;

string mp[1006];
int dp[1006][1006];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<n;++i)cin>>mp[i];
    queue<pair<int,int>> q;
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2; --x1,--x2,--y2,--y1;
    dp[x1][y1]=1; q.emplace(x1,y1);
    while(q.size()){
        for(int d=0;d<4;++d){
            for(int s=1;s<=k;++s){
                if(q.front().first+dx[d]*s>=0 && q.front().first+dx[d]*s<n);else break;
                if(q.front().second+dy[d]*s>=0 && q.front().second+dy[d]*s<m);else break;
                if(mp[q.front().first+dx[d]*s][q.front().second+dy[d]*s]=='#')break;
                if(!dp[q.front().first+dx[d]*s][q.front().second+dy[d]*s]){
                    dp[q.front().first+dx[d]*s][q.front().second+dy[d]*s]=dp[q.front().first][q.front().second]+1;
                    q.emplace(q.front().first+dx[d]*s,q.front().second+dy[d]*s);
                    if(dp[x2][y2])return cout<<dp[x2][y2]-1<<endl,0;
                }
            }
        }
        q.pop();
    }
    if(dp[x2][y2])return cout<<dp[x2][y2]-1<<endl,0;
    cout<<-1<<endl;
}
