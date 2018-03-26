#include<bits/stdc++.h>
using namespace std;

int cnt[124];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int t; cin>>t; ++cnt[t];
    }
    bool fl=0;
    if(!cnt[0])return cout<<-1<<endl,0;
    while(cnt[5]>=9){
        cnt[5]-=9;
        cout<<"555555555";
        fl=1;
    }
    while(fl && cnt[0])cout<<0,--cnt[0];
    if(!fl){
        if(cnt[0])cout<<0<<endl;
        else cout<<-1<<endl;
    }
}
