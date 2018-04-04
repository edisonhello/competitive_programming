#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    bool diff=0;
    int l=0,r=0;
    while(n--){
        int ll,rr; cin>>ll>>rr;
        diff|=(ll^rr)&1;
        l+=ll,r+=rr;
    }
    if((l^r)&1 || (l&r)&1&!diff)cout<<-1<<endl;
    else if((l&r)&1)cout<<1<<endl;
    else cout<<0<<endl;
}
