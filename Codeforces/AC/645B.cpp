#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
    ull n,t;cin>>n>>t;


    ull mvmx = min(t,n/2);


    ull ans=0;n--;
    for(int i=0;i<mvmx;i++){
        ans+=n;
        n--;
        ans+=n;
        n--;
    }
    cout<<ans<<endl;
}
