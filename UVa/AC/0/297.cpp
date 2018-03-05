#include<bits/stdc++.h>
using namespace std;

bool v[1234];

void go(string &s,int &ptr,int now,int len){
    if(s[ptr]=='p'){
        ++ptr;
        go(s,ptr,now,len/4);
        go(s,ptr,now+len/4,len/4);
        go(s,ptr,now+len/2,len/4);
        go(s,ptr,now+len/4*3,len/4);
    }
    else if(s[ptr]=='f'){
        ++ptr;
        for(int i=now;i<now+len;++i)v[i]=1;
    }
    else ++ptr;
}

int main(){
    int ts; cin>>ts; while(ts--){
        memset(v,0,sizeof(v));
        string s,t; cin>>s>>t;
        int ptr=0;
        go(s,ptr,0,1024);
        go(t,ptr=0,0,1024);
        int cnt=0;
        for(int i=0;i<1024;++i)cnt+=v[i];
        printf("There are %d black pixels.\n",cnt);
    }
}
