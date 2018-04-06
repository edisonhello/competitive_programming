#include<bits/stdc++.h>
using namespace std;

inline int next(string &s,int p){
    ++s[s.size()-1];
    int i=s.size()-1;
    while(1){
        for(;i>0;--i){
            if(s[i]>p){
                s[i]='a';
                ++s[i-1];
            }
            else break;
        }
        // cout<<s<<endl;
        if(s[i]==s[i-1] || (i>1&&s[i]==s[i-2])){++s[i]; continue;}
        if(s[0]>p)return 0;
        else break;
    }
    return 1;
}

int main(){
    int n,p; cin>>n>>p; p=p+'a'-1;
    string s; cin>>s;
    while(next(s,p)){
        bool ok=1;
        for(int i=1;i<n;++i){
            if(s[i]==s[i-1] || (i>1&&s[i]==s[i-2])){ok=0; break;}
        }
        if(ok)return cout<<s<<endl,0;
    }
    cout<<"NO"<<endl;
}
