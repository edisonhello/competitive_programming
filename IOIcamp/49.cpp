#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int a[3008];
struct {
    int v,prv;
} dp[2][3008];

int main(){
    int ts;cin>>ts;while(ts--){
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            if(dp[0][i-1].v+abs(dp[0][i-1].prv-a[i])<dp[1][i-1].v+abs(dp[1][i-1].prv-a[i])){
                dp[0][i].v=dp[0][i-1].v+abs(dp[0][i-1].prv-a[i]);
                dp[1][i].prv=a[i];
            }
            else{
                dp[0][i]
            }
        }
    }
}
