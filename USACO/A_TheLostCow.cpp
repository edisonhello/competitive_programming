#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    int a,b;cin>>a>>b;
    int ans=0;
    for(int x=1,i=1;;x<<=1,++i){
        ans+=(x>>1)+x;
        // cout<<ans<<endl;
        // cout<<i<<endl;
        if(i&1){
            if(b>=a && x>=b-a){
                ans-=a+x-b;
                break;
            }
        }
        else{
            if(b<=a && a-x<=b){
                ans-=b-a+x;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
