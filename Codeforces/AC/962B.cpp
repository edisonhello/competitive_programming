#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,a,b,ans=0; cin>>n>>a>>b;
    string s; cin>>s;
    for(int i=0;i<n;++i){
        if(s[i]=='*')continue;
        if(a>=b && a>0 && (!i || s[i-1]!='a')){
            s[i]='a';
            --a;
            ++ans;
        }
        else if(b>0 && (!i || s[i-1]!='b')){
            s[i]='b';
            --b;
            ++ans;
        }
        else if(a>0 && (!i || s[i-1]!='a')){
            s[i]='a';
            --a;
            ++ans;
        }
    }
    cout<<ans;
}
