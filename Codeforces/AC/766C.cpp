#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

const ll Z=1000000007;
int lim[30],cnt[30],cts[1005];
ll dp[1005];

int main(){
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<26;++i)cin>>lim[i];
    int mxln=1;

    dp[0]=1;cts[0]=1;
    for(int i=1;i<n;++i){
        memset(cnt,0,sizeof(cnt));
        int mnlm=9999;cts[i]=99999;
        for(int j=i;j>=0;--j){
            ++cnt[s[j]-'a'];
            mnlm=min(mnlm,lim[s[j]-'a']);
            if((i-j+1)>mnlm)break;
            // cout<<i<<" "<<j<<endl;
            dp[i]+=(j-1>=0?dp[j-1]:1);
            mxln=max(mxln,i-j+1);
            cts[i]=min(cts[i],(j-1>=0?cts[j-1]:0)+1);
        }
        dp[i]%=Z;
        // cout<<"dp "<<i<<" = "<<dp[i]<<endl;
    }
    cout<<dp[n-1]<<endl<<mxln<<endl<<cts[n-1]<<endl;
}
