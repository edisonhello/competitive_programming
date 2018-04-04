#include<bits/stdc++.h>
using namespace std;
#define ll long long

unsigned ll hh[10005],pp[100005],pre[10005];
unordered_map<unsigned ll,int> mp;
string sm[100005];
int id[10005];

unsigned ll grhh(string s){
    reverse(s.begin(),s.end());
    unsigned ll rt=0;
    for(char &c:s)if(c<='Z')c-='A'-'a';
    for(int i=0;i<s.size();++i)rt=rt+s[i]*pp[i+1];
    return rt*pp[100000-s.size()];
}

int main(){
    pp[0]=1;
    for(int i=1;i<100005;++i)pp[i]=pp[i-1]*131;

    int n; cin>>n;
    string s; cin>>s;
    s='/'+s;
    int m; cin>>m;
    for(int i=1;i<=m;++i){
        cin>>sm[i];
        mp[grhh(sm[i])]=i;
        // cout<<"hash of rev "<<sm[i]<<" is "<<grhh(sm[i])<<endl;
    }
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+s[i]*pp[i];
    }

    for(int i=1;i<=n;++i){
        for(int j=i-1;j>=0 && i-j<=1000;--j){
            unsigned ll v=(pre[i]-pre[j])*pp[100000-i];
            // cout<<"hh in range "<<j+1<<" to "<<i<<" is "<<v<<endl;
            if(mp.find(v)!=mp.end()){
                if(j==0 || id[j]){
                    id[i]=mp[v];
                    // cout<<"id["<<i<<"]:"<<id[i]<<endl;
                }
            }
        }
    }
    stack<int> ids;
    for(int ptr=n;ptr;ptr-=sm[id[ptr]].size()){
        // cout<<"ptr: "<<ptr<<endl;
        ids.push(id[ptr]);
    }
    while(ids.size()){
        cout<<sm[ids.top()]<<" ";
        ids.pop();
    }
    cout<<endl;
}
