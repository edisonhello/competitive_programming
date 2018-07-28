#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k; cin>>n>>k;
    int g=k;
    while(n--){
        int t; cin>>t;
        g=__gcd(g,t);
    }
    cout<<k/g<<endl;
    for(int i=0;i<k;i+=g)cout<<i<<" "; cout<<endl;
}
