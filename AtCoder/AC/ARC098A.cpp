#include<bits/stdc++.h>
using namespace std;

int le[300005],ri[300005];

int main(){
    int n; cin>>n; 
    string s; cin>>s; 
    int ans=INT_MAX;
    for(int i=2;i<=n;++i)le[i]=le[i-1]+(s[i-2]=='W');
    for(int i=n-1;i>=1;--i)ri[i]=ri[i+1]+(s[i]=='E');
    for(int i=1;i<=n;++i)ans=min(ans,le[i]+ri[i]);
    cout<<ans<<endl;
}
