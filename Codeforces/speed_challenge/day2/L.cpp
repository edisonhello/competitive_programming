#include<bits/stdc++.h>
using  namespace std;

int main(){
    int n,x; cin>>n>>x;
    int cnt=0;
    while(n--){
        int t; cin>>t; cnt+=t;
    }
    cout<<abs(cnt/x)+(!!(cnt%x));
}
