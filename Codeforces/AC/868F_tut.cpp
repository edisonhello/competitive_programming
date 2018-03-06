#include<bits/stdc++.h>
using namespace std;

long long dp[22][100005],ans;
int cf[22][100005],a[100005],L=1,R,cnt[100005];

void add(int v){
    ans+=cnt[v];
    ++cnt[v];
}
void sub(int v){
    --cnt[v];
    ans-=cnt[v];
}

long long get(int l,int r){
    while(r>R)add(a[++R]);
    while(l<L)add(a[--L]);
    while(r<R)sub(a[R--]);
    while(l>L)sub(a[L++]);
    return ans;
}

#define mid ((l+r)>>1)
void go(int d,int l,int r,int cl,int cr){
    if(l>r)return;
    dp[d][mid]=123123234343424234ll;
    for(int i=cl;i<=min(mid,cr);++i){
        long long val=dp[d-1][i-1]+get(i,mid);
        if(val<dp[d][mid]){
            dp[d][mid]=val;
            cf[d][mid]=i;
        }
    }
    go(d,l,mid-1,cl,cf[d][mid]);
    go(d,mid+1,r,cf[d][mid],cr);
    // cout<<d<<" "<<mid<<" "<<dp[d][mid]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)dp[0][i]=123123231234524542ll;
    for(int i=1;i<=k;++i)go(i,1,n,1,n);
    cout<<dp[k][n]<<endl;
}
