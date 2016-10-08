#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    while(n--){
        long long a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2] && a[0]>0 && a[1]>0 && a[2]>0){
            cout<<"yes\n";
        }
        else cout<<"no\n";
    }
}
