#include<bits/stdc++.h>
using namespace std;
struct item{
    int a,b,c;
} it[103];
int **dp;
int main(){
    clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    int x,y,n; cin>>x>>y>>n;

    dp=new int*[x+5];
    for(int i=0;i<x+5;++i)dp[i]=new int[y+5];
    for(int i=0;i<x+5;++i)for(int j=0;j<y+5;++j)dp[i][j]=0;

    int tota=0,totb=0,totc=0;
    for(int i=0;i<n;++i){
        cin>>it[i].a>>it[i].b>>it[i].c;
        tota+=it[i].a; totb+=it[i].b; totc+=it[i].c;
    }

    if(tota>x && totb>y){
        for(int i=0;i<n;++i){
            for(int j=x;j>=it[i].a;--j){
                for(int k=y;k>=it[i].b;--k){
                    dp[j][k]=max(dp[j][k],dp[j-it[i].a][k-it[i].b]+it[i].c);
                }
            }
        }
        cout<<dp[x][y]<<endl;
    }
    else if(totb>y){
        int *dpp=dp[0];
        for(int i=0;i<n;++i){
            for(int j=y;j>=it[i].b;--j){
                dpp[j]=max(dpp[j],dpp[j-it[i].b]+it[i].c);
            }
        }
        cout<<dpp[y]<<endl;
    }
    else if(tota>x){
        int *dpp=dp[0];
        for(int i=0;i<n;++i){
            for(int j=x;j>=it[i].a;--j){
                dpp[j]=max(dpp[j],dpp[j-it[i].a]+it[i].c);
            }
        }
        cout<<dpp[x]<<endl;
    }
    else cout<<totc<<endl;
}
