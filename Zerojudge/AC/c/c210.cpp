#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m; cin>>n>>m;
    int add=n-1;
    int back=n;
    int backpos=-1;
    while(add<=m && back>1){
        cout<<back<<" ";
        --back;
        m-=add;
        --add;
    }
    for(int i=1;i<back;++i){
        if(back-i==m)cout<<back<<" ";
        cout<<i<<" ";
    }
    if(!m)cout<<back<<" ";
    cout<<endl;
}
