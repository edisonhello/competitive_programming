#include<bits/stdc++.h>
using namespace std;
int cnt[11];
void u(int n){
    while(n){
        cnt[n%10]++;
        n/=10;
    }
}
int main(){
    int n,x;cin>>n>>x;
    for(int i=1;i<=n;++i)u(i);
    cout<<cnt[x]<<endl;
}
