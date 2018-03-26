#include<bits/stdc++.h>
using namespace std;


int cnt[12443];
int main(){
    int k; cin>>k;
    string s; cin>>s;
    for(char c:s)++cnt[c];
    for(int i='a';i<='z';++i){
        if(cnt[i]%k){
            cout<<"-1"<<endl;
            exit(0);
        }
    }
    for(int i=0;i<k;++i){
        for(int i='a';i<='z';++i){
            for(int c=0;c<cnt[i]/k;++c)cout<<char(i);
        }
    }
}
