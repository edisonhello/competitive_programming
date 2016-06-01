#include<bits/stdc++.h>
using namespace std;
#define unsigned long long ull
int main(){
    ull n;cin>>n;
    if(n%2==0){
        cout<<n/2<<endl;
    }
    else{
        cout<<"-"<<n/2+1<<endl;
    }
}
