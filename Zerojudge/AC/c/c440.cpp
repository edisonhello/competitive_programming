#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int ans=0,A=0,Q=0;
    for(char c:s){
        if(c=='Q')++Q,ans+=A;
        else if(c=='A')A+=Q;
    }
    cout<<ans<<endl;
}
