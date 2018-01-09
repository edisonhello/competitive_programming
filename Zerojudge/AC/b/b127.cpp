#include<bits/stdc++.h>
using namespace std;

long long f[55];

int main(){
    f[0]=f[1]=1;
    for(int i=2;i<=45;++i)f[i]=f[i-1]+f[i-2];
    int n; while(cin>>n){
        cout<<f[n]<<endl;
    }
}
