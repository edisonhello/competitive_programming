#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);

    int m;cin>>m;
    string s="";
    for(int i=0;i<99995;i++){
        s+='a';
    }
    cout<<s<<'\n';
    long long mm=pow(2l,(long long)m);
    long long i=0;
    int pos=99994;
    while(i<mm){
        if(s[pos]=='z')pos--;
        s[pos]++;
        i++;
    }
    cout<<s<<'\n';
}
