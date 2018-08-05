#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        vector<int> l(1,a[1]);
        for(int i=2;i<=n;++i){
            if(l.size() && a[i]>=l.back())l.push_back(a[i]);
            else *upper_bound(l.begin(),l.end(),a[i])=a[i];
        }
        if(l.size()>=n-1)cout<<"._./"<<endl;
        else cout<<"\\._."<<endl;
    }
}
