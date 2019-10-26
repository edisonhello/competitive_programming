#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b; cin>>n>>a>>b;
    cout<<min(a,b)<<" ";
    if(a+b<=n)cout<<0<<endl;
    else cout<<a+b-n<<endl;
}
