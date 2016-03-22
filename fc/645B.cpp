#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;cin>>n>>t;


    int mvmx = min(t,n/2);


    int ans=0;n--;
    for(int i=0;i<mvmx;i++){
        ans+=n;
        n--;
        ans+=n;
        n--;
    }
    cout<<ans<<endl;
}
