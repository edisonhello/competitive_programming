#include<bits/stdc++.h>
using namespace std;

int com[1000006];
int main(){
    int k; cin>>k;
    for(int i=1;i<=k;++i){
        int t; cin>>t;
        com[t]=1;
    }
    for(int i=1;k<25;++i){
        if(!com[i]){
            com[i]=1;
            ++k;
        }
    }
    int cnt=0,onc=0;
    for(int i=1000000;i>=1;--i){
        if(com[i])onc=1;
        cnt+=(!com[i])*onc;
    }
    cout<<cnt<<endl;
}
