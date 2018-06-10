// = Codeforces 321E
#include<bits/stdc++.h>
using namespace std;

int a[4004][4004],pre[4004][4004];
int dp[4004][4004];

inline int cost(int l,int r){
    return pre[r][r]-pre[r][l-1]-pre[l-1][r]+pre[l-1][l-1];
}

void go(int layer,int l,int r,int tl,int tr){
    if(l>r)return;
    int x=(l+r)>>1;
    int mn=INT_MAX;
    int p=-1;
    for(int i=tl,val;i<=min(tr,x);++i){
        val=dp[layer-1][i-1]+cost(i,x);
        if(val<mn){
            mn=val;
            p=i;
        }
    }
    dp[layer][x]=mn;
    // cout<<"dp "<<layer<<" "<<x<<" is "<<mn<<" from "<<p<<endl;
    go(layer,l,x-1,tl,p);
    go(layer,x+1,r,p,tr);
}

char str[10000];

int main(){
    int n,k; scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            getchar();
            a[i][j]=getchar()-'0';
            pre[i][j]=a[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    for(int i=1;i<=n;++i)dp[0][i]=0x3f3f3f3f;
    for(int i=1;i<=k;++i){
        go(i,i,n,i,n);
    }
    printf("%d\n",dp[k][n]>>1);
}
