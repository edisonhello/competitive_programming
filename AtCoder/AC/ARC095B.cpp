#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    cout<<a[n]<<" "<<*max_element(a+1,a+n,[&](const int &x,const int &y){ return min(x,a[n]+1-x)<min(y,a[n]+1-y); })<<endl;
}
