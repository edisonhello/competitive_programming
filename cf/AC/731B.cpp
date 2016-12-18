#include<iostream>
using namespace std;
int a[200005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<=n;++i){
        if(a[i]<0){
            cout<<"NO\n";
            return 0;
        }
        a[i]=a[i]&1;
        if(a[i])--a[i+1];
    }
    cout<<"YES\n";
}
