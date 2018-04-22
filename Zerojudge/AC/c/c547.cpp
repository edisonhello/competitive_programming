#include<bits/stdc++.h>
using namespace std;


int fib[10005];
int main(){
    fib[0]=fib[1]=1;
    for(int i=2;i<=10000;++i)fib[i]=(fib[i-1]+fib[i-2])%1000000007;
    int n; while(cin>>n){
        cout<<fib[n]<<'\n';
    }
}
