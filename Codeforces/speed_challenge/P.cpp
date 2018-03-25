#include<bits/stdc++.h>
using namespace std;

int a[1004];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    if(a[0]==1)cout<<-1<<endl;
    else cout<<1<<endl;
}
