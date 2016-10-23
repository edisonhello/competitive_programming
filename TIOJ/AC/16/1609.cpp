#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[0];
    for(int i=1;i<n;++i){
        cout<<" "<<a[i];
    }
    cout<<'\n';
}
