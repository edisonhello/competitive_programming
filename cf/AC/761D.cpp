#include<algorithm>
#include<iostream>
using namespace std;

int n,l,r,a[100005],c[100005],b[100005],mx=0,mn=1e9+5;

int main(){
    cin>>n>>l>>r;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>c[i];
    for(int i=0;i<n;++i){
        b[i]=a[i]+c[i];
        mn=min(mn,b[i]);
    }
    for(int i=0;i<n;++i){
        b[i]=b[i]-mn+l;
        if(b[i]>r){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;++i)cout<<b[i]<<" ";cout<<endl;
}
