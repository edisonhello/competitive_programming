#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s; int n=s.size(),ans=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                if(s[i]=='Q' and s[j]=='A' and s[k]=='Q')++ans;
            }
        }
    } cout<<ans<<endl;
}
