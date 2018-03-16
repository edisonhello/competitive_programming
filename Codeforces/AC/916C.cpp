#include<bits/stdc++.h>
using namespace std;

struct e{
    int u,v,w;
};
vector<e> ans;

int main(){
    int n,m; cin>>n>>m;
    for(int i=2;i<n;++i){
        ans.push_back({i,i+1,1});
    }
    ans.push_back({1,2,510007-(n-2)});
    cout<<"510007 510007\n";
    m-=(n-1);
    for(int i=1;i<=n;++i){
        for(int j=i+2;j<=n;++j){
            if(m<=0)break;
            --m;
            ans.push_back({i,j,12345678});
        }
    }
    for(auto i:ans){
        cout<<i.u<<" "<<i.v<<" "<<i.w<<'\n';
    }
}
