#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1234],b[1234];
ll dp[1234][1234],cf[1234][1234];
bitset<1234> v[1234];

int main(){
    int n,m; while(cin>>n>>m){
        for(int i=0;i<m;++i)cin>>a[i]; a[m]=n;
        for(int i=m;i>0;--i)b[i]=a[i]-a[i-1]; ++m; b[0]=a[0];
        for(int l=0;l<m;++l){
            for(int i=0;i<m;++i){
                int j=i+l; if(j>=m)break;
                if(i==j){dp[i][j]=0,cf[i][j]=i-1; continue;}
                dp[i][j]=1000000000000000000ll;
                for(int k=cf[i][j-1];k<=cf[i+1][j];++k){
                    if(dp[i][k]+dp[k+1][j]<dp[i][j]){
                        dp[i][j]=dp[i][k]+dp[k+1][j];
                        cf[i][j]=k;
                    }
                }
                dp[i][j]+=a[j]-(i?a[i-1]:0ll);
            }
        }
        cout<<dp[0][m-1]<<endl;
    }
}
