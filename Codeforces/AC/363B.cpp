#include<bits/stdc++.h>
using namespace std;

int p[150005];
int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>p[i],p[i]+=p[i-1];
    int mn=1e9,j=-1;
    for(int i=1;i+k-1<=n;++i){
        if(p[i+k-1]-p[i-1]<mn){
            mn=p[i+k-1]-p[i-1];
            j=i;
        }
    } cout<<j<<endl;
}
