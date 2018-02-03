#include<bits/stdc++.h>
using namespace std;

map<int,int,greater<int>> mp;

int main(){
    int n; cin>>n; while(n--){
        int t; cin>>t; ++mp[t];
    }
    bool ans=1;
    for(auto i:mp){
        if(i.second&1){
            ans=0;
            break;
        }
    }
    if(ans)cout<<"Agasa"<<endl;
    else cout<<"Conan"<<endl;
}
