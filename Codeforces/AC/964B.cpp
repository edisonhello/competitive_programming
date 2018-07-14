#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,a,b,c,t; cin>>n>>a>>b>>c>>t;
    if(c>=b){
        long long ans=0;
        for(int i=1,z;i<=n;++i)cin>>z,ans=(ans+a-b*(t-z)+c*(t-z));
        cout<<ans<<endl;
    }
    else{
        long long ans=0;
        for(int i=1,z;i<=n;++i)cin>>z,ans=(ans+a);
        cout<<ans<<endl;
    }
}
