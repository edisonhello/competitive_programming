#include<vector>
#include<iostream>
#define ll long long
#include<algorithm>
using namespace std;
#include<sstream>

vector<ll> cj;

void init(){
    stringstream ss;
    ll t;
    for(int i=1;i<=9;++i){
        for(int j=1;j<=18;++j){
            ss.clear();
            for(int k=0;k<j;++k){
                ss<<i;
            }
            ss>>t;
            cj.push_back(t);
        }
    }
    sort(cj.begin(),cj.end());
    // for(int i=0;i<(int)cj.size();++i)cout<<cj[i]<<" ";cout<<endl;
}

int main(){
    init();
    int ts;cin>>ts;while(ts--){
        ll l,r;
        cin>>l>>r;
        cout<<upper_bound(cj.begin(),cj.end(),r)-
              lower_bound(cj.begin(),cj.end(),l)<<endl;
    }
}
