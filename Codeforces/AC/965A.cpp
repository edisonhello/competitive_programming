#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n,s,p; cin>>k>>n>>s>>p;
    cout<<(((n-1)/s+1)*k-1)/p+1<<endl;
}
