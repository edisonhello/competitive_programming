#include<bits/stdc++.h>
using namespace std;
#define int long long

main(){
    int w,h; cin>>w>>h;
    int ans=0;
    for(int i=2;i<=w;i+=2){
        for(int j=2;j<=h;j+=2){
            ans+=(w-i+1)*(h-j+1);
        }
    }
    cout<<ans<<endl;
}
