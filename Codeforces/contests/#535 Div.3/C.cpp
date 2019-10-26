#include<bits/stdc++.h>
using namespace std;



int main(){
    int n; cin>>n;
    string s; cin>>s;
    int mn=1e9;
    string ans;
    string p="RGB";
    sort(p.begin(),p.end());
    do{
        string t=p;
        while(t.size()<s.size())t+=t;
        t.resize(s.size());
        int c=0;
        for(int i=0;i<n;++i)if(s[i]!=t[i])++c;
        if(c<mn){
            mn=c;
            ans=t;
        }
    }while(next_permutation(p.begin(),p.end()));
    cout<<mn<<endl<<ans<<endl;
}
