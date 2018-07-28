#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<char,int>> a;

int main(){
    cin>>n;
    a.resize(n*2);
    for(auto &i:a)cin>>i.first>>i.second;
    int wptr=1,bptr=1,ans=0;
    for(int i=0;i<2*n;++i){
        // cout<<"i: "<<i<<endl;
        if(a[i].first=='W'){
            if(a[i].second==wptr){ ++wptr; continue; }
        }
        if(a[i].first=='B'){
            if(a[i].second==bptr){ ++bptr; continue; }
        }
        for(int j=i+1;;++j){
            // cout<<"j: "<<j<<endl;
            if((a[j].first=='W' && a[j].second==wptr) || (a[j].first=='B' && a[j].second==bptr)){
                for(;j>i;--j)swap(a[j],a[j-1]),++ans;
                break;
            }
        }
        if(a[i].first=='W'){
            if(a[i].second==wptr){ ++wptr; continue; }
        }
        if(a[i].first=='B'){
            if(a[i].second==bptr){ ++bptr; continue; }
        }
        assert(0);
    }
    cout<<ans<<endl;
}
