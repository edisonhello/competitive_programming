#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        if(i&1){
            for(int ii=0;ii<m;++ii)cout<<"#";
            cout<<endl;
        }
        if(i%4==2){
            for(int ii=1;ii<m;++ii)cout<<".";
            cout<<"#\n";
        }
        if(i%4==0){
            cout<<"#";
            for(int ii=1;ii<m;++ii)cout<<".";
            cout<<endl;
        }
    }
}
