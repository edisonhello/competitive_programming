#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

int main(){
    long long ans=0,w=0,h=0;
    int n; cin>>n;
    while(n--){
        int a; cin>>a;
        ++mp[a];
    }
    for(auto it=mp.rbegin();it!=mp.rend();++it){
        while(it->second>1){
            it->second-=2;
            if(w){
                cout<<w*it->first<<endl;
                exit(0);
            }
            w=it->first;
        }
    }
    cout<<ans<<endl;
}
