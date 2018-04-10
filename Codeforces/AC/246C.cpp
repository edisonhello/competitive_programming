#include<bits/stdc++.h>
using namespace std;

struct item{
    int v,i;
} a[55];

int main(){
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i].v,a[i].i=i+1;
    sort(a,a+n,[](const auto &a,const auto &b){return a.v<b.v;});
    vector<int> bin;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<=i;++j){
            if(k==0)exit(0);
            --k;
            cout<<bin.size()+1;
            for(int i:bin)cout<<" "<<i;
            cout<<" "<<a[j].v<<endl;
        }
        bin.push_back(a[i].v);
    }
}
