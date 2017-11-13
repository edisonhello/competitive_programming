#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int h,n; cin>>h>>n; --n;
    int ans=0,dir=0;
    for(int i=0;i<h;++i){
        // cout<<i<<" "<<ans<<" "<<dir<<endl;
        ++ans;
        if(dir==0){
            // cout<<(n&(1ll<<(h-i)-1))<<" "<<((1ll<<(h-i-1))-1)<<endl;
            if((n&(1ll<<(h-i)-1))<=((1ll<<(h-i-1))-1)){
                dir=1;
            }
            else{
                ans+=(1ll<<(h-i))-1;
            }
        }
        else{
            if((n&(1ll<<(h-i)-1))<=((1ll<<(h-i-1))-1)){
                ans+=(1ll<<(h-i))-1;
            }
            else{
                dir=0;
            }
        }
    }
    cout<<ans<<endl;
}
