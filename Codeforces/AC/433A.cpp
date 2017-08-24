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

    // cout<<_1<<" "<<_2<<endl;

    if((_1%2==0 && _2%2==0) || ((_1+_2*2)%2==0 && _1)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
