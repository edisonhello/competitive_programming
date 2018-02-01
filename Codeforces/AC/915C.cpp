#include<bits/stdc++.h>
using namespace std;
int cnt[242];
string s,t;
char ns[222];

bool dfs(int pos,bool lock=1){
    if(pos==s.length()){
        for(int i=0;i<s.length();++i){
            cout<<ns[i];
        } cout<<endl;
        exit(0);
    }
    if(lock){
        for(int i=t[t.size()-s.size()+pos];i>='0';--i){
            if(cnt[i]){
                --cnt[i];
                ns[pos]=i;
                dfs(pos+1,i==t[t.size()-s.size()+pos]);
                ++cnt[i];
            }
        }
    }
    else{
        for(int i='9';i>='0';--i){
            if(cnt[i]){
                --cnt[i];
                ns[pos]=i;
                dfs(pos+1,0);
                ++cnt[i];
            }
        }
    }
}

int main(){
    cin>>s>>t;
    for(char c:s)++cnt[c];
    dfs(0,t.size()==s.size());
}
