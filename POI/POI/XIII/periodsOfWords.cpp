#include<bits/stdc++.h>
using namespace std;
#define ll long long

int fail[1000006];

int main(){
    int n; cin>>n;
    string s; cin>>s;
    fail[0]=-1;
    ll ans=0;
    for(int i=1;i<s.size();++i){
        int t=fail[i-1];
        while(t>0 && s[t+1]!=s[i])t=fail[t];
        if(s[t+1]==s[i])++t;
        else t=-1;
        fail[i]=t;
        if(fail[i]>=0)ans+=max(max(i-fail[i],fail[i]+1),i-i%(i-fail[i]));
        // if(fail[i]>=0)cout<<i<<" "<<fail[i]<<" : ";
        // if(fail[i]>=0)cout<<i-fail[i]<<" "<<fail[i]+1<<" "<<i-i%(i-fail[i])<<endl;
    }
    cout<<ans<<endl;
}
