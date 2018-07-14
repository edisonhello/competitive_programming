#include<bits/stdc++.h>
using namespace std;

int main(){
    long long q,w,e,r,t,y,u; cin>>q>>w>>e>>r>>t>>y>>u;
    long long ans=0;
    for(long long g3=0;g3<=1;++g3){
        if(q<g3 || r<g3 || t<g3)break;
        ans=max(ans,g3*3+((q-g3)^((q-g3)&1))+((r-g3)^((r-g3)&1))+((t-g3)^((t-g3)&1))+w);
    }
    cout<<ans<<endl;
}
