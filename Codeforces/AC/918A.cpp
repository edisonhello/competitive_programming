#include<bits/stdc++.h>
using namespace std;

bool f[10005];

int main(){
    int n; cin>>n;
    int p=1,x=2;
    f[p]=f[x]=1;
    while(x<n){
        tie(p,x)=make_pair(x,p+x);
        f[x]=1;
    }
    for(int i=1;i<=n;++i)if(f[i])cout<<"O"; else cout<<"o";
}
