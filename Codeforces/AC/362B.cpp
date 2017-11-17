#include<bits/stdc++.h>
using namespace std;

int a[3333];
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i)cin>>a[i];
    sort(a,a+m);
    for(int i=0;i<m-2;++i){
        if(a[i]==a[i+1]-1 and a[i+1]+1==a[i+2])return cout<<"NO"<<endl,0;
    }
    if(a[m-1]!=n and a[0]!=1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
