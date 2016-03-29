#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
    int n;cin>>n;
    ull a[60];
    a[1]=2;
    a[2]=6;
    for(int i=3;i<=n;i++){
        a[i] = a[i-1]+2*(a[i-1]-a[i-2]);
    }
    cout<<a[n]<<endl;
}
