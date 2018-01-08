#include<bits/stdc++.h>
using namespace std;

bool lead[222];
long long w[222];

int main(){
    int n; cin>>n;
    while(n--){
        string s; cin>>s;
        int base=1;
        for(int i=s.size()-1;i>=0;--i){
            w[s[i]]+=base;
            base*=10;
        }
        lead[s[0]]=1;
    }
    vector<pair<long long,char>> ww;
    for(int i='a';i<='j';++i){
        ww.emplace_back(w[i],i);
    }
    sort(ww.begin(),ww.end()); reverse(ww.begin(),ww.end());
    int zero;
    for(auto ii:ww){
        if(!lead[ii.second]){
            zero=ii.second;
            break;
        }
    }
    long long ans=0; int dig=1;
    for(auto ii:ww){
        if(ii.second==zero)continue;
        ans+=ii.first*dig;
        ++dig;
    }
    cout<<ans<<endl;
}
