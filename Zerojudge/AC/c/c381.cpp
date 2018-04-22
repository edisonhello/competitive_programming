#include<bits/stdc++.h>
using namespace std


;int main(){
    
    int n,m; while(cin>>n>>m,n){
        string ss;
        string s; while(n--){
            cin>>s; ss+=s;
        }
        while(m--){
            int t; cin>>t; --t;
            cout<<ss[t];
        }
        cout<<endl;
    }
}
