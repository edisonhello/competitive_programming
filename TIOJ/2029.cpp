#define ll long long
#include<bits/stdc++.h>
using namespace std;

int n,k; ll r,c;
ll d[100005],dp[22][100005],C_d[100005],i_d[100005],pre[100005];

void initinitinit(){
    for(int i=1;i<=n;++i)C_d[i]=C_d[i-1]+d[i]*c,i_d[i]=i_d[i-1]+i*d[i],pre[i]=pre[i-1]+d[i];
}
ll get(int l,int r){
    return C_d[r]-C_d[l-1]-(i_d[r]-i_d[l-1]-(pre[r]-pre[l-1])*(l-1));
}

bool can(int y){
    memset(dp,0xa0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=k;++i){
        for(int j=i;j<=n;++j){
            for(int k=1;k<=y && j+k-1<=n;++k){
                dp[i][j+k-1]=max(dp[i][j+k-1],dp[i-1][j-1]+get(j,j+k-1));
            }
        }
    }
    // cout<<"when y="<<y<<" , dp: "<<dp[k][n]<<endl;
    return dp[k][n]>=r;
}
void spec(){
    if(k==1){
        if(get(1,n)>=r)cout<<n<<endl;
        else cout<<-1<<endl;
    }
    else{
        int ans=304003838;
        for(int i=1;i<n;++i){
            if(get(1,i)+get(i+1,n)>=r)ans=min(ans,max(i,n-i));
        }
        if(ans>n)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>r>>c;
    for(int i=1;i<=n;++i)cin>>d[i];
    initinitinit();
    if(k<=2)spec();
    int L=1,R=n+1;
    while(R>L && L<=n){
        if(can((L+R)>>1))R=(L+R)>>1;
        else L=((L+R)>>1)+1;
    }
    if(L==n+1)cout<<-1<<endl;
    else cout<<L<<endl;
}
