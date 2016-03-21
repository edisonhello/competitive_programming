#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int _1=0;int _2=0;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(t==100) _1++;
        else _2++;


    }
    if(_1&1){
        cout<<"NO"<<endl;

    }
    else cout<<"YES"<<endl;
}
