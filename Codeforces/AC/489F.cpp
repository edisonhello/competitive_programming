#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("O3,unroll-loops")
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int dp[5][505][505],hap[505];
int Ctable[505][505];

char str[505];
int main(){
    int n,m,mod; scanf("%d%d%d",&n,&m,&mod);
    Ctable[0][0]=1;
    for(int i=1;i<505;++i){
        for(int j=0;j<=3;++j){
            Ctable[i][j]=(Ctable[i-1][j]+(j?Ctable[i-1][j-1]:0));
            if(Ctable[i][j]>=mod)Ctable[i][j]-=mod;
        }
    }
    // printf("ctable: %d\n",Ctable
    for(int i=1;i<=m;++i){
        scanf("%s",str);
        for(int i=0;i<n;++i)if(str[i]=='1')++hap[i];
    }
    for(int i=0;i<n;++i)if(hap[i]>2)exit((puts("0"),0));
    int c2=0,c1=0,c0=0;
    for(int i=0;i<n;++i)if(hap[i]==2)++c2; else if(hap[i]==1)++c1; else ++c0;
    dp[(m-1)&1][c0][c1]=1;
    // printf("%d %d %d\n",(m-1)&1,c0,c1);
    for(int i=m,j,k;i<n;++i){
        bool at=i&1;
        memset(dp[at],0,(505*505)<<2);
        for(j=0;j<=500;++j)for(k=0;k<=500;++k){
            if(j+k>(n-1-i)*2)break;
            // if(j+k<2)continue;
            dp[at][j][k]=((k>1?(1ll*dp[at^1][j+2][k-2]*Ctable[j+2][2]):0)+(1ll*dp[at^1][j+1][k]*k*(j+1))+(1ll*dp[at^1][j][k+2]*Ctable[k+2][2]))%mod;
        }
        // if(i==1)printf("%d\n",dp[1][0][2]);
    }
    printf("%d\n",dp[(n-1)&1][0][0]);
}
