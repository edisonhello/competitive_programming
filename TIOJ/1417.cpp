#include<bits/stdc++.h>
#include"lib1417.h"
using namespace std;

void add(string &a,string b){
    string str; for(int i=0;i<max(a.size(),b.size());++i)str+='0';
    for(int i=0;i<a.size();++i)str[str.size()-1-i]+=a[a.size()-1-i]-'0';
    for(int i=0;i<b.size();++i)str[str.size()-1-i]+=b[b.size()-1-i]-'0';
    for(int i=str.size()-1;i>0;--i)if(str[i]>'9'){
        str[i-1]+=(str[i]-'0')/10;
        str[i]=(str[i]-'0')%10+'0';
    }
    while(str[0]>'9'){
        char newdig=(str[0]-'0')/10;
        str[0]=(str[0]-'0')%10+'0';
        str=newdig+str;
    } a=str;
}

int main(){
    int ts; cin>>ts; while(ts--){
        int n,s,t; cin>>n>>s>>t; vector<string> v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        sort(v.begin(),v.end(),[](const string &a,const string &b){
            if(a.length()!=b.length())return a.length()<b.length();
            for(int i=0;i<a.length();++i)if(a[i]!=b[i])return a[i]<b[i];
            return false;
        });
        string ans; for(int i=s-1;i<t;++i)add(ans,v[i]);
        // cout<<ans<<endl;
        output(ans.c_str());
    }
}
