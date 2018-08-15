#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,k,arr[312345],sum[312345],dp[312345];
ll cnt(int l,int r){
    int md=(l+r)>>1;
return (sum[r]-sum[md])-(r-md)*arr[md]-
(sum[md]-sum[l-1])+(md-l+1)*arr[md];
}
const int L = 500;
int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
cin>>n>>k;
for(int i=1;i<=n;i++){
cin>>arr[i];
}
sort(arr+1,arr+n+1);
for(int i=1;i<=n;i++){
sum[i]=arr[i]+sum[i-1];
dp[i]=INF;
}
ll p=0;
for(int i=1;i<=n;i++){
for(int j=p;j<=min(i-k,p+L);j++){
if(dp[j]+cnt(j+1,i)<dp[i]){
dp[i]=dp[j]+cnt(j+1,i);
p=j;
}
}
for(int j=max(p,i-k-L);j<=i-k;j++){
if(dp[j]+cnt(j+1,i)<dp[i]){
dp[i]=dp[j]+cnt(j+1,i);
p=j;
}
}
}
cout<<dp[n]<< '\n';
}
