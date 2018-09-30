#include<bits/stdc++.h>
using namespace std;

string genlast(int n,char k){
    k+='a'; --k;
    string pa; pa+=k; pa+=k-1; pa+=k-2;
    string rt;
    for(int z=0;z<344;++z)rt+=pa;
    return rt.substr(0,n);
}

int main(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    if(k==1)exit((cout<<"NO"<<endl,0));
    if(k==2){
        if(n==1){
            if(s=="a")cout<<"b"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(n==2){
            if(s=="ab")cout<<"ba"<<endl;
            else cout<<"NO"<<endl;
        }
        exit(0);
    }
    if(genlast(n,k)==s)exit((cout<<"NO"<<endl,0));
    for(int i=n-1;i>=0;--i){
        ++s[i];
        bool end=0;
        if(s[i]>char(k+'a'-1)){ end=1; }
        // if(end)cout<<"first out at "<<i<<endl;
        while((i && s[i]==s[i-1]) || (i-1 && s[i]==s[i-2])){
            ++s[i];
            if(s[i]>char(k+'a'-1)){ end=1; break; }
        }
        if(end)continue;
        for(int j=i+1;j<n;++j){
            s[j]='a';
            while((j && s[j]==s[j-1]) || (j-1 && s[j]==s[j-2]))++s[j];
        }
        cout<<s<<endl;
        exit(0);
    }
}
