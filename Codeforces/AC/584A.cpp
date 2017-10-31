#include<bits/stdc++.h>
using namespace std;

int main(){
    int now=0;
    int n,t; cin>>n>>t;
    if(t==10 && n==1)return cout<<-1<<endl,0;
    for(int i=1;i<n;++i){
        cout<<1;
        now=now*10+1;
        now%=t;
    }
    for(int i=9;i>=0;--i){
        if((now*10+i)%t==0){
            cout<<i<<endl;
            return 0;
        }
    }
}
