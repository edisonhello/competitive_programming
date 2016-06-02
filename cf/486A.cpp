#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main(){
    ull n;cin>>n;
    if(n%2==0){
        cout<<n/2<<endl;
    }
    else{
        cout<<"-"<<n/2+1<<endl;
    }
}
