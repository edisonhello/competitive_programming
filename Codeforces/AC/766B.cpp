#include<iostream>
using namespace std;
#include<algorithm>
int a[100005];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    for(int i=0;i<n-2;++i){
        if(a[i+2]+a[i+1]>a[i]){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}
