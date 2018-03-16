#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

unsigned int hhs[5005][5005],hht[5005][5005];

int main(){
    string s,t; cin>>s>>t;
    // string s,t;
    // for(int i=0;i<5000;++i)s+=rand()%26+'a',t+=rand()%26+'a';
    // gp_hash_table<unsigned int,int> mp,mp2;
    for(int i=0;i<s.size();++i){
        unsigned int hh=0;
        for(int j=i;j<s.size();++j){
            hh^=7122;
            hh=(hh*313)+s[j];
            hhs[i][j]=hh;
        }
    }
    int len=999999;
    for(int i=0;i<t.size();++i){
        unsigned int hh=0;
        for(int j=i;j<t.size() && j-i+1<len;++j){
            hh^=7122;
            hh=(hh*313)+t[j];
            hht[i][j]=hh;
        }
    }
    for(int len=1;;++len){
        gp_hash_table<unsigned int,int> mp,mp2;
        for(int i=0;i+len-1<s.size();++i)++mp[hhs[i][i+len-1]];
        for(int i=0;i+len-1<t.size();++i)++mp2[hht[i][i+len-1]];
        bool no=1,ok=0;
        for(auto i:mp){
            auto it=mp2.find(i.first);
            if(it!=mp2.end()){
                no=0;
                if(i.second==1 && it->second==1)ok=1;
            }
        }
        if(no)break;
        if(ok)exit((cout<<len<<endl,0));
    }
    cout<<-1<<endl;
}
