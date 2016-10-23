#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    string s;cin>>s;
    int cnt=0;
    for(int i=0;i<n;++i){
        if(s[i]=='<')cnt++;
        else break;
    }
    for(int i=n-1;i>=0;--i){
        if(s[i]=='>')cnt++;
        else break;
    }
    cout<<cnt<<endl;
}
