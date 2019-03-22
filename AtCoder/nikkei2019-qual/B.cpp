#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string a,b,c; cin>>a>>b>>c;
    int ans=0;
    for(int i=0;i<n;++i){
        map<int,int> mp;
        ++mp[a[i]];
        ++mp[b[i]];
        ++mp[c[i]];
        int mx=0;
        for(auto &p:mp)mx=max(mx,p.second);
        ans+=3-mx;
    }
    cout<<ans<<endl;
}
