nclude<bits/stdc++.h>
using namespace std;

int meow(){
        string mp[8]; for(int i=0;i<8;++i)cin>>mp[i];
        int dp[8][8]={0},n=8; memset(dp,-1,sizeof(dp));
        for(int i=0,_dwj=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(mp[i][j]=='K' and !_dwj){
                // cout<<i<<" "<<j<<endl;
                    _dwj=1;
                    dp[i][j]=0;
                    queue<int> q; q.push(i); q.push(j);
                    while(q.size()){
                        int x=q.front(); q.pop();
                        int y=q.front(); q.pop();
                        // cout<<x<<" "<<y<<endl;
                        if(x>1){
                            if(y>1 and dp[x-2][y-2]==-1){
                                dp[x-2][y-2]=dp[x][y]+1;
                                q.push(x-2); q.push(y-2);
                            }
                            if(y<n-2 and dp[x-2][y+2]==-1){
                                dp[x-2][y+2]=dp[x][y]+1;
                                q.push(x-2); q.push(y+2);
                            }
                        }
                        if(x<n-2){
                            if(y>1 and dp[x+2][y-2]==-1){
                                dp[x+2][y-2]=dp[x][y]+1;
                                q.push(x+2); q.push(y-2);
                            }
                            if(y<n-2 and dp[x+2][y+2]==-1){
                                dp[x+2][y+2]=dp[x][y]+1;
                                q.push(x+2); q.push(y+2);
                            }
                        }
                    }
                }
            }
        }
        // cout<<mp[7][0]<<" "<<dp[7][0]<<endl;
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(mp[i][j]=='K' and dp[i][j]){
                    if(dp[i][j]==-1)return cout<<"NO"<<endl,0;
                    if(dp[i][j]&1)return cout<<"NO"<<endl,0;
                    return cout<<"YES"<<endl,0;
                }
            }
        }
    
}
int main(){
    int t; cin>>t; while(t--){
        meow();
    }
}
