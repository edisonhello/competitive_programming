#include<bits/stdc++.h>
using namespace std;

int a[1111];
int main(){
    int n,g=0,mn=1e7; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],g=__gcd(g,a[i]),mn=min(mn,a[i]);
    if(mn!=g)return cout<<-1<<endl,0; cout<<2*n<<endl;
    for(int i=1;i<=n;++i)cout<<a[i]<<" "<<mn<<" "; cout<<endl;
}
