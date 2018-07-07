#include<bits/stdc++.h>
using namespace std;


int a[1004],id[1004];
vector<int> ans[1004];
double val;

int main(){
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)id[i]=i;
    sort(id+1,id+1+n,[&](const int &z,const int &b){ return a[z]>a[b]; });
    int ptr=0;
    for(int i=1;i<=n;++i){
        for(int z=0;z<a[id[i]];++z){
            ans[id[i]].push_back(++ptr);
        }
    }
    for(int i=1;i<=n;++i){
        double t=0;
        for(int z:ans[i])t+=z;
        t/=ans[i].size();
        val+=t;
    }
    cout<<fixed<<setprecision(5)<<val<<endl;
    for(int i=1;i<=n;++i){
        for(int z:ans[i])cout<<z<<" ";
        cout<<endl;
    }
}
