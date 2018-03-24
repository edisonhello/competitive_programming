
#include<bits/stdc++.h>
using namespace std;

int c[45];

int main(){
    srand(time(0));
    freopen("in.txt","w",stdout);
    int n=20;
    cout<<"20 20 10000"<<endl;
    for(int i=1;i<=n;++i)c[i]=10000;
    for(int i=n*n;i>=0;--i){
        int del=rand()%1000;
        int u=rand()%n+1,v=rand()%n+1;
        del=min(c[u],del);
        c[u]-=del;
        c[v]+=del;
    }
    for(int i=1;i<=n;++i)cout<<c[i]<<" "; cout<<endl;
}


