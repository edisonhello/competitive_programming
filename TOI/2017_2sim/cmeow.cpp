#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
int a[5005];
ll dp[5005][5005];
bool v[6005][6005];
const ll mod=1e9+7;


void U(){
    for(int i=0;i<k;++i){int t;cin>>t;n-=t;}

    ll *chai=dp[0];
    for(int i=0;i<=n;++i){
        chai[i]=1;
    }

    for(int i=2;i<=n;++i){
        for(int j=i;j<=n;++j){
            chai[j]+=chai[j-i];
            chai[j]%=mod;
        }
        // cout<<i<<endl;
    }
    cout<<chai[n]<<endl;
}

ll dfs2(int n,int k){
    // cout<<n<<" "<<k<<endl;
    if(n==0)return 1;
    if(v[n][k])return dp[n][k];
    v[n][k]=1;

    return dp[n][k]=(k*dfs2(n-1,k)+dfs2(n-1,k+1))%mod;
}
void N(){
    int left=n-k,sts=k;
    cout<<dfs2(left,sts)<<endl;
}

int main(){
//    for(int i=1;i<=20;++i){
//        cout<<i<<" => "; n=i; U();
//    }

    char type; cin>>type>>n>>k; // assert(type=='N');
    if(type=='U')U();
    else N();
}
