#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; while(cin>>n){
    bool yes=1;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){yes=0; break;}
    }
    cout<<(yes?"YES":"NO")<<"\n";}
}
