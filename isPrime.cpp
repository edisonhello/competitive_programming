#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0)cout<<"YES\n",exit(0);
    }
    cout<<"NO\n";
}
