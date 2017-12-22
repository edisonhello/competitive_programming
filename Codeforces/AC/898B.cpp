#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b; cin>>n>>a>>b;
    for(int i=0;a*i<=n;++i){
        if((n-a*i)%b);
        else return cout<<"YES\n"<<i<<" "<<(n-a*i)/b<<endl,0;
    } cout<<"NO"<<endl;
}
