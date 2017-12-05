#include<bits/stdc++.h>
using namespace std;

int n,k;
long long r,d[100005],pre[100005],pp[100005];

long long getseg(int l,int r){
    return pp[r]-pp[l-1]-(pre[r]-pre[l-1])*(l-1);
}

int cp[22][100005];
long long dp[22][100005];
bool ok(int y){
    for(int i=0;i<22;++i)for(int j=0;j<1000005;++j)dp[i][j]=-500000000000000000ll;
    dp[0][0]=0;
    for(int i=1;i<=y;++i)dp[1][i]=getseg(1,i);
    for(int i=2;i<=k;++i){
        for(int j=i;j<=n;++j){
            
        }
    }
}

int main(){
    cin>>n>>k>>r;
    for(int i=1;i<=n;++i)cin>>d[i],pre[i]=pre[i-1]+1,pp[i]=d[i]*i+pp[i-1];
    int L=1,R=n+1;
    while(R>L){
        int m=(L+R)>>1;
        if(ok(m))R=m;
        else L=m+1;
    }
    if(L==n+1)cout<<-1<<endl;
    else{
        cout<<L<<endl;
        cout cut points;
    }
}
