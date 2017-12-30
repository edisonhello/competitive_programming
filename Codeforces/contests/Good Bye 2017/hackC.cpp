#include<bits/stdc++.h>
using namespace std;

int x[1008],n,r;
double y[1008];
int main(){
    cin>>n>>r;
    for(int i=1;i<=n;++i)cin>>x[i];
    cout<<r<<" ";
    y[1]=r;
    for(int i=2;i<=n;++i){
        for(int j=1;j<i;++j)if(x[i]+r>x[j]-r || x[i]-r<x[j]+r)y[i]=max(y[i],y[j]+sqrt(1ll*r*r*4-1ll*abs(x[i]-x[j])*abs(x[i]-x[j])));
        printf("%0.6f ",y[i]);
    }
}
