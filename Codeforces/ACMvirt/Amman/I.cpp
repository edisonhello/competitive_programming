#include<bits/stdc++.h>
using namespace std;


int main(){
    int ts; cin>>ts; while(ts--){
        int x,n; cin>>x>>n;
        if(n>x)cout<<-1;
        else for(int i=n-1;i>=0;--i){
            cout<<x/n+int(i<x%n)<<" ";
        }
        cout<<endl;
    }
}
