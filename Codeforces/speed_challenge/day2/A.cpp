#include<bits/stdc++.h>
using namespace std;


bool isp(int n){
    for(int i=2;i<n;++i){
        if(n%i==0)return 0;
    }
    return 1;
}

int main(){
    int n; cin>>n;
    int m; cin>>m;
    for(int i=n+1;;++i){
        if(isp(i)){
            if(i==m)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            exit(0);
        }
    }
}
