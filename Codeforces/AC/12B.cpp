#include<bits/stdc++.h>
using namespace std;

int cnt[14];
int main(){
    string s; cin>>s; for(char c:s)cnt[c-'0']++;
    string ans; for(int i=1;i<10;++i){
        if(cnt[i]){ans+=(char)(i+'0'),cnt[i]--;break;}
    }
    for(int i=0;i<10;++i){
        while(cnt[i]){
            ans+=(char)(i+'0');
            --cnt[i];
        }
    }
    cin>>s;
    cout<<(s==ans?"OK":"WRONG_ANSWER")<<endl;
}
