#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S0(x) memset((x),0,sizeof(x))
#define SB(x) memset((x),0x7f,sizeof(x))
ll d[1005],dp[1005];
int main(){
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;
    do{
        int n;
        cin>>n;
        SB(dp);
        dp[0]=0;
        for(int i=0;i<n;++i){
            cin>>d[i];
            if(i==1){
                dp[i]=abs(d[i]-d[i-1]);
            }
            else if(i){
                dp[i]=min(dp[i-1]+abs(d[i]-d[i-1]),dp[i-2]+abs(d[i]-d[i-2]));
            }
        }
        cout<<dp[n-1]<<'\n';
    }while(--t);
}
