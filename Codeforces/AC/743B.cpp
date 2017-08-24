#include<iostream>
using namespace std;
int main(){
    long long n,k;cin>>n>>k;
    for(int i=0;i<=n;++i){
        if(k&(1ll<<i)){cout<<i+1<<endl;return 0;}
    }
}
