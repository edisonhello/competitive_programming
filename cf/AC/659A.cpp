#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int res=(a+b)%n;
    if(res==0)res=n;
    while(res<1){
        res+=n;
    }
    cout<<res<<endl;
}
