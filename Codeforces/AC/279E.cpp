#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int ans=0;
    for(char &c:s)c-='0';
    for(int i=s.size()-1;i>=0;){
        if(!s[i]){
            --i;
            continue;
        }
        if(i && s[i-1]){
            s[i]=0; --i;
            while(i && s[i])s[i]=0,--i;
            if(i<0){++ans; break;}
            s[i]=1;
            ++ans;
        }
        else{
            s[i]=0; ++ans; --i;
        }
    }
    cout<<ans<<endl;
}
