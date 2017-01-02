#include<cstdio>
using namespace std;
#define ll long long

int n,m;
ll dp[60][60];

ll C(int n,int m){
    if(dp[n][m])return dp[n][m];
    if(m==1 || m==n)return 1;
    return dp[n][m]=C(n-1,m)+C(n-1,m-1);
}

int main(){
    while(scanf("%d%d",&n,&m),n){
        if(m==0)printf("1\n");
        else printf("%lld\n",C(m+n,n));
    }
}
