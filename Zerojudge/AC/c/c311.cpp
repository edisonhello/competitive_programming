#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; while(cin>>s){
        int ans=0;
        for(char c:s){
            ans=ans*10+c-'0';
            ans%=91;
        }
        cout<<ans<<endl;
    }
}
