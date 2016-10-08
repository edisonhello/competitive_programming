#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        long double tot=0,mn=99.0,mx=-9.0,t;
        for(int i=0;i<n;i++){
            cin>>t;
            mn=min(mn,t);
            mx=max(mx,t);
            tot+=t;
        }
        printf("%.2llf\n",(tot-mn-mx)/(n-2));
    }
}
