#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    map<int,int> mp;
    int ans=0;
    while(n--){
        int h,m; cin>>h>>m;
        m+=h*100;
        ++mp[m];
        ans=max(ans,mp[m]);
    }
    cout<<ans<<endl;
}
