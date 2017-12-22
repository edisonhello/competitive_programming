#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int now=0,cnt=0;
    while(now<n-1){
        ++cnt;
        int jump=0;
        for(int i=k;i>=1;--i){
            if(s[i+now]=='1'){
                jump=i;
                break;
            }
        }
        if(!jump)return cout<<-1<<endl,0;
        now+=jump;
    } cout<<cnt<<endl;
}
