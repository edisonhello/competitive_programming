#include<bits/stdc++.h>
using namespace std;

int cnts[26];
vector<int> ans;

void shift(string &s,int x){
    if(x==0)return;
    string a(s.substr(0,s.size()-x)),b(s.substr(s.size()-x,x));
    reverse(b.begin(),b.end());
    s=b+a;
    // cout<<x<<" "<<s<<endl;
    ans.push_back(x);
}

void reverse(string &s,int x){
    shift(s,s.size()-x);
    shift(s,s.size());
}

int main(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    for(char c:s)++cnts[c-'a'];
    for(char c:t)--cnts[c-'a'];
    for(int i=0;i<26;++i)if(cnts[i])return cout<<"-1"<<endl,0;
    for(int slen=0;slen<s.size();++slen){
        char req=t[slen];
        int pos;
        for(int i=0;i<n;++i)if(s[i]==req){pos=i; break;}
        shift(s,n-pos-1);
        shift(s,1);
        shift(s,n);
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
