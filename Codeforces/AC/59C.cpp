#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; string s; cin>>k>>s;
    int n=s.size();
    for(int i=0;i<n;++i){
        if(s[i]!=s[n-1-i] && s[i]!='?' && s[n-1-i]!='?'){
            exit((cout<<"IMPOSSIBLE"<<endl,0));
        }
    }
    for(int i=0;i<n;++i){
        if(s[i]=='?' && s[n-i-1]!='?')s[i]=s[n-i-1];
    }
    for(int i=0;i<n;++i){
        if(s[i]!='?' && s[i]-'a'+1>k){
            exit((cout<<"IMPOSSIBLE"<<endl,0));
        }
    }
    int empty=0;
    for(int i=0;i<(n+1)/2;++i){
        if(s[i]=='?')++empty;
    }
    bitset<26> aru;
    for(int i=0;i<n;++i){
        if(s[i]!='?')aru[s[i]-'a']=1;
    }
    int need=0;
    for(int i=0;i<k;++i)if(!aru[i])++need;
    if(empty<need)exit((cout<<"IMPOSSIBLE"<<endl,0));
    int ptr=k-1;
    for(int i=(n+1)/2-1;i>=0;--i){
        if(s[i]!='?')continue;
        while(ptr>=0 && aru[ptr])--ptr;
        if(ptr<0)s[i]='a';
        else{
            s[i]=ptr+'a';
            aru[ptr]=1;
        }
    }
    for(int i=0;i<n;++i){
        if(s[i]=='?' && s[n-i-1]!='?')s[i]=s[n-i-1];
    }
    cout<<s<<endl;
}
