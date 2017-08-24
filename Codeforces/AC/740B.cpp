#include<iostream>
using namespace std;

int a[105],pr[105];

int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pr[i]=pr[i-1]+a[i];
    }
    int ans=0;
    while(m--){
        int l,r;cin>>l>>r;
        if(pr[r]-pr[l-1]>0)ans+=pr[r]-pr[l-1];
    }
    cout<<ans<<endl;
}
