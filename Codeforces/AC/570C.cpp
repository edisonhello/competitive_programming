#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    string s; cin>>s;
    int now=0;
    for(int i=0;i<n-1;++i)if(s[i]=='.' && s[i+1]=='.')++now;
    while(m--){
        int pos; char ch; cin>>pos>>ch; --pos;
        if(ch=='.'){
            if(s[pos]=='.'){cout<<now<<endl; continue;}
            if(pos<n-1 && s[pos+1]=='.')++now;
            if(pos && s[pos-1]=='.')++now;
            s[pos]=ch;
        }
        else{
            if(s[pos]!='.'){cout<<now<<endl; continue;}
            if(pos<n-1 && s[pos+1]=='.')--now;
            if(pos && s[pos-1]=='.')--now;
            s[pos]=ch;
        }
        cout<<now<<endl;
    }
}
