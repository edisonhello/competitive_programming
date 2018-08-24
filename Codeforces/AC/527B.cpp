#include<bits/stdc++.h>
using namespace std;

int to[26][26];

int main(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    for(char &c:s)c-='a';
    for(char &c:t)c-='a';
    int diff=0;
    for(int i=0;i<n;++i)if(s[i]!=t[i])++to[s[i]][t[i]],++diff;
    for(int i=0;i<26;++i)for(int j=0;j<26;++j){
        if(to[i][j] && to[j][i]){
            cout<<diff-2<<endl;
            for(int x=0;;++x)if(s[x]==i && t[x]==j){ cout<<x+1<<" "; break; }
            for(int x=0;;++x)if(s[x]==j && t[x]==i){ cout<<x+1<<" "; break; }
            exit(0);
        }
    }
    for(int i=0;i<26;++i)for(int j=0;j<26;++j)for(int k=0;k<26;++k){
        if(to[i][j] && to[j][k]){
            cout<<diff-1<<endl;
            for(int x=0;;++x)if(s[x]==i && t[x]==j){ cout<<x+1<<" "; break; }
            for(int x=0;;++x)if(s[x]==j && t[x]==k){ cout<<x+1<<" "; break; }
            exit(0);
        }
    }
    cout<<diff<<endl;
    cout<<"-1 -1 "<<endl;
}
