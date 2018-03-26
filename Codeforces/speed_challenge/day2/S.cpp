#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    int loop=s.size()*t.size();
    int ar=0,br=0;
    for(int ip=0,jp=0,c=0;c<loop;++c,++ip,++jp){
        if(ip>=s.size())ip=0;
        if(jp>=t.size())jp=0;
        if(s[ip]=='R' && t[jp]=='S')++br;
        if(s[ip]=='S' && t[jp]=='P')++br;
        if(s[ip]=='P' && t[jp]=='R')++br;
        if(t[jp]=='R' && s[ip]=='S')++ar;
        if(t[jp]=='S' && s[ip]=='P')++ar;
        if(t[jp]=='P' && s[ip]=='R')++ar;
    }
    int lc=n/loop;
    ar*=lc, br*=lc;
    for(int ip=0,jp=0,c=0;c<n%loop;++c,++ip,++jp){
        if(ip>=s.size())ip=0;
        if(jp>=t.size())jp=0;
        if(s[ip]=='R' && t[jp]=='S')++br;
        if(s[ip]=='S' && t[jp]=='P')++br;
        if(s[ip]=='P' && t[jp]=='R')++br;
        if(t[jp]=='R' && s[ip]=='S')++ar;
        if(t[jp]=='S' && s[ip]=='P')++ar;
        if(t[jp]=='P' && s[ip]=='R')++ar;
    }
    cout<<ar<<" "<<br<<endl;
}
