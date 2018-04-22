#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; while(cin>>n,n){ 
        map<vector<int>,int> mp;
        for(int i=0;i<n;++i){
            vector<int> v;
            for(int j=0;j<5;++j){
                int t; cin>>t; 
                v.push_back(t);
            }
            sort(v.begin(),v.end());
            ++mp[v];
        }
        int mx=0;
        for(auto p:mp)mx=max(mx,p.second);
        int pp=0;
        for(auto p:mp)if(mx==p.second)pp+=p.second;
        cout<<pp<<endl;
    }
}
