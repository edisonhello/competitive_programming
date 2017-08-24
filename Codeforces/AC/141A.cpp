#include<bits/stdc++.h>
using namespace std;

int cnt[222];
int main(){
    string s;
    cin>>s;
    for(char c:s)++cnt[c];
    cin>>s;
    for(char c:s)++cnt[c];
    cin>>s;
    for(char c:s)--cnt[c];
    for(int i=0;i<128;++i){
        if(cnt[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES";
}
