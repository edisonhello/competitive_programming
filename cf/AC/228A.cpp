#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    for(int i=0;i<4;++i){
        int t;cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());v.resize(unique(v.begin(),v.end())-v.begin());
    cout<<4-v.size()<<endl;
}
