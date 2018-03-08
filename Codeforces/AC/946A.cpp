#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans=0;
    while(n--){
        int t; cin>>t;
        ans+=abs(t);
    }
    cout<<ans<<endl;
}
