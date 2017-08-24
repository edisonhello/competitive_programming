#include<bits/stdc++.h>
using namespace std;
int a[1242];
int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    if(a[n-1]==0)cout<<"UP"<<endl;
    else if(a[n-1]==15)cout<<"DOWN"<<endl;
    else if(n==1)cout<<"-1"<<endl;
    else if(a[n-2]>a[n-1])cout<<"DOWN"<<endl;
    else cout<<"UP"<<endl;
}
