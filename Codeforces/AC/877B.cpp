#include<bits/stdc++.h>
using namespace std;
int sufa[5555];
int main(){
    string s; cin>>s;
    for(int i=s.size()-1;i>=0;--i)sufa[i]=sufa[i+1]+(s[i]=='a');
    int mx=0,prea=0;
    for(int i=0;i<s.size();++i){
        int nowb=0;
        for(int j=i;j<s.size();++j){
            mx=max(prea+nowb+sufa[j],mx);
            nowb+=(s[j]=='b');
        }
        mx=max(mx,prea+nowb);
        prea+=(s[i]=='a');
    }
    cout<<mx<<endl;
}
