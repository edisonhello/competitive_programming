#include<bits/stdc++.h>
using namespace std;
#define int long long


struct Z{
    int a,b;
};

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(cin>>n,n){
        vector<Z> ans;
        for(int i=0;i<n;++i){
            int a,b; cin>>a>>b;
            ans.push_back({a+b,(a==b?0:(a>b?1:-1))});
        }
        sort(ans.begin(),ans.end(),[](const Z &a,const Z &b){return a.a==b.a?a.b>b.b:a.a>b.a;});
        for(auto i:ans){
            cout<<(i.b==1?">":i.b==0?"=":"<")<<i.a<<" ";
        }
        cout<<endl;
    }
}
