#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll a[100005];
int main(){
    int T;cin>>T;
    while(T--){
        int n,s,t;cin>>n>>s>>t;
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        sort(a,a+n);
        ll ans=0;
        for(int i=s-1;i<t;i++){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
}
