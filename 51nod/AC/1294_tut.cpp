#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> lis;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        if(t<i)continue;
        t-=i;
        if(lis.empty() || t>=lis.back())lis.push_back(t);
        else *upper_bound(lis.begin(),lis.end(),t)=t;
    }
    cout<<n-lis.size()<<endl;
}
