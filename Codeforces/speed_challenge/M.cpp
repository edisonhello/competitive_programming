#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        ++mp[t];
    }
    int mx=0;
    for(auto i:mp)mx=max(mx,i.second);
    cout<<mx<<" "<<mp.size()<<endl;
}
