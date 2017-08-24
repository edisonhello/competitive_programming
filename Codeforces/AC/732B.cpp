#include<iostream>
using namespace std;

int n,k,a[505],ans;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=1;i<n;++i){
        if(a[i]+a[i-1]<k){
            ans+=k-a[i]-a[i-1];
            a[i]=k-a[i-1];
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;++i){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}
