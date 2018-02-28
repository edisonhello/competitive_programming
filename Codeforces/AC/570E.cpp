#include<bits/stdc++.h>
using namespace std;

#define upd(a,b) a=a+b, a>=mod?a-=mod:0
#define mul(a,b) 1ll*a*b%mod

const int mod=1000000007;
string mp[555];
int _dp[2][555][555];

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    auto dp=_dp[0];
    auto prv=_dp[1];
    if(mp[0][0]==mp[n-1][m-1])prv[0][n-1]=1;
    for(int step=1;step<=(n+m-2)/2;++step){
        memset(dp,0,sizeof(int)*555*555);
        for(int ai=0;ai<n;++ai){
            for(int bi=0;bi<n;++bi){
                int aj=step-ai,bj=m-step-1+(n-bi-1);
                // printf("(%d,%d),(%d,%d)\n",ai,aj,bi,bj);
                if(!(bj>=0 && aj>=0 && aj<m && bj<m))continue;
                if(mp[ai][aj]!=mp[bi][bj])continue;
                // cout<<"meo"<<endl;
                if(ai && bi<n-1)upd(dp[ai][bi],prv[ai-1][bi+1]);
                if(aj && bi<n-1)upd(dp[ai][bi],prv[ai][bi+1]);
                if(ai && bj<m-1)upd(dp[ai][bi],prv[ai-1][bi]);
                if(aj && bj<m-1)upd(dp[ai][bi],prv[ai][bi]);
                // cout<<ai<<" "<<bi<<" is "<<dp[ai][bi]<<endl;
            }
        }
        swap(dp,prv);
        /* cout<<"step: "<<step<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<prv[i][j]<<" ";
            } 
            cout<<endl;
        } */
    }
    int ans=0;
    if((n+m)%2==0){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i+j!=(n+m-2)/2)continue;
                upd(ans,prv[i][i]);
            }
        }
    }
    else{
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i+j!=(n+m-2)/2)continue;
                upd(ans,prv[i][i]);
                if(i<n-1)upd(ans,prv[i][i+1]);
            }
        }
    }
    cout<<ans<<endl;
}
