#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1234],pre[1234];
ll dp[1234][1234],tp[1234][1234];

void sol(vector<int> &A){
    int n=int(A.size());
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)a[i]=A[i-1];
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    for(int len=2;len<=n;++len){
        for(int i=1;i<=n;++i){
            int j=i+len-1;
            if(j>n)break;
            if(len==2){
                dp[i][j]=pre[j]-pre[i-1];
                tp[i][j]=j;
            }
            else{
                ll mn=LLONG_MAX;
                int p=-1;
                for(int z=tp[i][j-1];z<=tp[i+1][j];++z){
                    ll v=pre[j]-pre[i-1]+dp[i][z-1]+dp[z][j];
                    if(v<mn){
                        mn=v;
                        p=z;
                    }
                }
                dp[i][j]=mn;
                tp[i][j]=p;
            }
        }
    }
    cout<<dp[1][n]<<'\n';
}

int main(){
    int n,m; while(cin>>n>>m){
        vector<int> len(m+1);
        int prv=0;
        for(int i=0;i<m;++i){
            int t; cin>>t;
            len[i]=t-prv;
            prv=t;
        }
        len.back()=n-prv;
        sol(len);
    }
}
