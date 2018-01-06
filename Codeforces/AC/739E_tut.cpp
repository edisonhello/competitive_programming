#include<bits/stdc++.h>
using namespace std;
#define ld long double

int n,a,b;
ld p[2003],u[2003];

ld dp[2003][2003];
int cf[2003][2003];
int use(ld cost){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int aa=0;aa<=a;++aa){
            dp[i][aa]=dp[i-1][aa];
            cf[i][aa]=0;
            if(aa && dp[i][aa]<dp[i-1][aa-1]+p[i]){
                dp[i][aa]=dp[i-1][aa-1]+p[i];
                cf[i][aa]=1;
            }
            if(dp[i][aa]<dp[i-1][aa]+u[i]-cost){
                dp[i][aa]=dp[i-1][aa]+u[i]-cost;
                cf[i][aa]=2;
            }
            if(aa && dp[i][aa]<dp[i-1][aa-1]+p[i]+u[i]-p[i]*u[i]-cost){
                dp[i][aa]=dp[i-1][aa-1]+p[i]+u[i]-p[i]*u[i]-cost;
                cf[i][aa]=3;
            }
        }
    }
    int aa=a,i=n,use=0;
    while(i){
        if(cf[i][aa]>1)++use;
        if(cf[i][aa]&1)--aa;
        --i;
    }
    return use;
}

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i)cin>>p[i];
    for(int i=1;i<=n;++i)cin>>u[i];
    ld L=0,R=1;
    while(R-L>1e-10){
        ld M=(L+R)/2;
        if(use(M)>b)L=M;
        else R=M;
    }
    cout<<fixed<<setprecision(20)<<dp[n][a]+L*b<<endl;
}
