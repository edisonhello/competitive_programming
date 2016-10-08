#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    for(int i=s.length()-2;i>=0;i--){
        s+=s[i];
    }
    cout<<s<<'\n';
}
