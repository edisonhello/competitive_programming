#include<bits/stdc++.h>
#define ld long double
using namespace std;
struct atk{int m,d;};
int w,b,n,m,dp[10005],i,ts,j,_a,d;
atk a[1005];
int main(){
    cin>>ts;
    while(ts--){
        cin>>w>>b>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++){
            cin>>_a>>d;
            a[i]={_a,d};
        }
        cin>>m;
        for(i=0;i<n;i++){
            a[i].m+=m;
            // cout<<"atk: "<<i+1<<":, atk:"<<a[i].d<<", cost:"<<a[i].m<<endl;
        }

        for(i=0;i<n;i++){
            for(j=a[i].m;j<=w-1;j++){
                dp[j]=max(dp[j],dp[j-a[i].m]+a[i].d);
            }
        }
        // cout<<"dp:";for(int i=0;i<=w;i++)cout<<i<<":"<<dp[i]<<", ";cout<<endl;
        if(dp[w-1]>=b){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}
