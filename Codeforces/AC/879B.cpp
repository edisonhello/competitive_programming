#include<bits/stdc++.h>
using namespace std;

int a[1111];
int main(){
    int n; long long k; cin>>n>>k;
    k=min(k,1000ll);
    for(int i=0;i<n;++i)cin>>a[i];
    int wpower=a[0],cntwin=0;
    for(int i=1;;i=(i+1)%n){
        if(wpower>=a[i])++cntwin;
        else wpower=a[i],cntwin=1;
        if(cntwin>=k)return cout<<wpower<<endl,0;
    } return cout<<wpower<<endl,0;
}
