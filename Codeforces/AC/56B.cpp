#include<bits/stdc++.h>
using namespace std;

int a[1111];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int i=1;
    for(;i<=n;++i)if(a[i]!=i)break;
    if(i>n)return cout<<"0 0"<<endl,0;
    int l=i,r=a[i];
    for(int j=l,k=r;j<=k;++j,--k){
        swap(a[j],a[k]);
    }
    for(i=1;i<=n;++i)if(a[i]!=i)return cout<<"0 0"<<endl,0;
    cout<<l<<" "<<r<<endl;
}
