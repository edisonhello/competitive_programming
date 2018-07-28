#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        map<int,int> c;
        while(n--){ int t; cin>>t; ++c[t]; }
        int k=0;
        for(auto p:c)k+=(p.second>>1);
        int z=0;
        for(auto &p:c)++z,--p.second;
        vector<int> v;
        for(auto p:c){
            while(p.second>1)v.push_back(2),p.second-=2;
            if(p.second)v.push_back(1);
        }
        sort(v.begin(),v.end(),greater<int>());
        assert(v.size()==k);
        cout<<k<<endl;
        for(int i:v)++z,cout<<z<<" ",z+=!(i&1); cout<<endl;
    }
}
