#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int N,M,a,b,c,d,dp[111][222][222];
inline int calc(int i,int x,int y){
    return (a*i+b*x+c*y)%d;
}
int main(){
    scanf("%d%d%d%d%d%d",&M,&N,&a,&b,&c,&d);
    for(int i=1,x,y;i<=N;++i){
        for(x=1;x<=M-N+i;++x){
            for(y=1;y<=M-N+i;++y){
                dp[i][x][y]=max(max(dp[i][x-1][y],dp[i][x][y-1]),dp[i-1][x-1][y-1]+calc(i-1,x-1,y-1));
            }
        }
    }
    printf("%d\n",dp[N][M][M]);
}
