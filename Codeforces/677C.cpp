#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    vector<int> cod;
    vector<int> pos;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cod.push_back(s[i]-'0');
        }
        if(s[i]>='A'&&s[i]<='Z'){
            cod.push_back(s[i]-'A'+10);
        }
        if(s[i]>='a'&&s[i]<='z'){
            cod.push_back(s[i]-'a'+36);
        }
        if(s[i]=='-'){
            cod.push_back(62);
        }
        if(s[i]=='_'){
            cod.push_back(63);
        }

        // cout<<cod[i]<<" ";

        int cnt=1;
        for(int bit=1;bit<64;bit*=2){
            if(!(bit&cod[i])){
                cnt*=2;
            }
        }
        pos.push_back(cnt);
        // cout<<cnt<<endl;
    }

    unsigned long long res=1;
    for(int i=0;i<pos.size();i++){
        res*=pos[i];
        res%=(unsigned long long)10e9+7;
    }
    cout<<res*2-1<<endl;
}
