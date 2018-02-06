#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[20005];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    for(int i=2;i<n;++i){
        if(a[i-2]+a[i-1]>a[i])return cout<<"possible"<<endl,0;
    }
    cout<<"impossible"<<endl;
}
