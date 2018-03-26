#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    long long a=n;
    for(long long i=1;i*i<=n;++i){
        --a;
    }
    cout<<a<<endl;
}
