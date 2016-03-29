#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n;cin>>n;
    int c[26];
    int cmx=-98989;
    for(int i=0;i<26;i++){
        cin>>c[i];
        cmx=max(cmx,c[i]);
    }
    int ans=0;
    int i;
    for(i=0;i<s.length();i++){
        ans+=c[s[i]-97]*(i+1);     //   cout<<c[s[i]-97]<<endl;
    }
    for(int j=1;j<=n;i++,j++){
        ans+=(i+1)*cmx;
    }
    cout<<ans<<endl;

}
