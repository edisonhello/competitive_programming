#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int c=0,a=0;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        if(t<0){
            if(c){
                --c;
            }
            else ++a;
        }
        else c+=t;
    }
    cout<<a<<endl;
}
