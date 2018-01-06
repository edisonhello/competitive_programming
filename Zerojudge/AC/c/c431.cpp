#include<bits/stdc++.h>
using namespace std;

int cnt[111];
int main(){
    int n; cin>>n; 
    while(n--){
        int t; cin>>t;
        ++cnt[t];
    }
    for(int i=1;i<=100;++i){
        while(cnt[i])cout<<i<<" ",--cnt[i];
    }
    cout<<endl;
}
