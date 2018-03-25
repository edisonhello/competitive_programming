#include<bits/stdc++.h>
using namespace std;

vector<int> v[5];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        v[t].push_back(i);
    }
    vector<pair<int,pair<int,int>>> ans;
    while(v[1].size() && v[2].size() && v[3].size()){
        ans.push_back({v[1].back(),make_pair(v[2].back(),v[3].back())});
        v[1].pop_back(); v[2].pop_back(); v[3].pop_back();
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
    }
}
