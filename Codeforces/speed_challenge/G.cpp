
#include<bits/stdc++.h>
using namespace std;

int a[100005],p[100005],buywhen[100005],eed[100005];

int main(){
    int n; cin>>n;    
    for(int i=0;i<n;++i){
        cin>>a[i]>>p[i];
    }
    for(int i=1;i<n;++i){
        if(p[buywhen[i-1]]<p[i]){
            buywhen[i]=buywhen[i-1];
        }
        else buywhen[i]=i;
    }
    for(int i=0;i<n;++i){
        eed[buywhen[i]]+=a[i];
       //  cout<<buywhen[i]<<" ";
    }
    int ans=0;
    for(int i=0;i<n;++i){
        ans+=eed[i]*p[i];
    }
    cout<<ans<<endl;
}
