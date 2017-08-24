#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    string ans = "";
    for(int i=0;i<s.length();i++){
        ans += s[i];
    }
    for(int i=s.length()-1;i>=0;i--){
        ans += s[i];
    }
    cout<<ans<<endl;
}
