#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1000006];
ll dp[1000006];
vector<int> aa;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        if(aa.size()>3u){
            if(aa[aa.size()-4]<aa[aa.size()-3] && aa[aa.size()-3]<aa[aa.size()-2] && aa[aa.size()-2]<aa[aa.size()-1] && aa[aa.size()-1]<a[i]){
                int t=aa.back(); aa.pop_back(); aa.pop_back();
                aa.push_back(t);
            }
            if(aa[aa.size()-4]>aa[aa.size()-3] && aa[aa.size()-3]>aa[aa.size()-2] && aa[aa.size()-2]>aa[aa.size()-1] && aa[aa.size()-1]>a[i]){
                int t=aa.back(); aa.pop_back(); aa.pop_back();
                aa.push_back(t);
            }
        }
        aa.push_back(a[i]);
    }
    for(int i=0;i<aa.size();++i){
        a[i+1]=aa[i];
    }
    n=aa.size();
    for(int i=1;i<=n;++i){
        int mx=a[i],mn=a[i];
        for(int j=i;j>=i-10 && j>=1;--j){
            mx=max(mx,a[j]);
            mn=min(mn,a[j]);
            dp[i]=max(dp[i],dp[j-1]+mx-mn);
        }
    }
    cout<<dp[n]<<endl;
}
