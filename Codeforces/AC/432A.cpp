#include<bits/stdc++.h>
using namespace std;

int n,k,y[2222];

int main(){
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>y[i];
    sort(y,y+n);
    int c=0;
    for(int i=0;i+2<n;i+=3){
        if(y[i+2]+k<=5)++c;
        else break;
    }
    cout<<c<<endl;
}
