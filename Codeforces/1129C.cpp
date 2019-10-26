#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

string s;
int dp[3005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    s=" ";
    int n; cin>>n; 
    for(int i=0;i<n;++i){
        char c; cin>>c;
        s+=c;
    }
    // dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=max(1,i-3);j<=i;++j){
            string t=s.substr(j,j-i+1);
            if(t=="0011");
            else if(t=="0101");
            else if(t=="1110");
            else if(t=="1111");
            else{
                dp[i]+=dp[j-1]+1;
                if(dp[i]>=mod)dp[i]-=mod;
            }
        }
        cerr<<"dp["<<i<<"] = "<<dp[i]<<endl;
    }
    for(int i=2;i<=n;++i)dp[i]+=dp[i-1];
    for(int i=1;i<=n;++i)cout<<dp[i]<<'\n';
}

#ifdef CE

1 0 1 0 1

  0
 10
1 0

    1
  0 1
   01
  101
1  01
1 0 1
 10 1
#endif
