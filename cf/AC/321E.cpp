#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;

int N,K,jz[4005][4005],dp[4005][805],pre[4005][4005],comfrm[4005][805];

inline int guf(int s,int t){
    return (pre[t][t]-pre[s-1][t]-pre[t][s-1]+pre[s-1][s-1])/2;
}

int main(){
    scanf("%d%d%*c",&N,&K);
    char _buf[10000];
    for(int i=1;i<=N;++i){
        gets(_buf);
        for(int j=1;j<=N;++j){
            jz[i][j]=_buf[(j-1)<<1]-'0';
            pre[i][j]=jz[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    for(int i=1;i<=800;++i)comfrm[i][i+1]=i;
    /*for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cout<<setw(2)<<pre[i][j]<<" ";
        }
        cout<<endl;
    }*/
    memset(dp,0x77,sizeof(dp));
    dp[0][0]=0; int cnt=0;
    for(int i=1;i<=N;++i){
        for(int k=K;k>0;--k){
            if(k==K)comfrm[i][k+1]=i-1;
            for(int j=comfrm[i-1][k];j<=comfrm[i][k+1];++j){
                if(dp[j][k-1]+guf(j+1,i) < dp[i][k]){
                    dp[i][k]=dp[j][k-1]+guf(j+1,i);
                    comfrm[i][k]=j;
                }
                /*cout<<"dp at "<<i<<" "<<j<<" "<<k<<", table:\n";
                for(int i=1;i<=N;++i){
                    for(int j=1;j<=K;++j){
                        cout<<setw(10)<<dp[i][j]<<"("<<comfrm[i][j]<<")";
                    }
                    cout<<endl;
                // }*/
            }
        }
    }
    printf("%d\n",dp[N][K]);
    // cout<<"in for "<<cnt<<" times"<<endl;
    /*cout<<"dp table: \n";
    for(int i=1;i<=N;++i){
        for(int j=1;j<=K;++j){
            cout<<setw(10)<<dp[i][j]<<"("<<comfrm[i][j]<<")";
        }
        cout<<endl;
    }*/
}
