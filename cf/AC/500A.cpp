#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s; cin>>n>>s; int now=1;
    for(int i=1;i<n;++i){
        int t; cin>>t;
        if(i==now){
            now+=t;
            if(now==s){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO";
}
