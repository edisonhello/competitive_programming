#include<bits/stdc++.h>
#define ld long double
using namespace std;

ld meow(ld x,ld y,int n){
    if(n==1)return max(x/y,y/x);
    ld mn=9999999999999.0;
    for(int i=1;i<n;++i){
        mn=min(mn,min(
           max(meow(x/n*i,y,i),meow(x/n*(n-i),y,n-i)),
           max(meow(x,y/n*i,i),meow(x,y/n*(n-i),n-i))));
    }
    return mn;
}

int main(){
    ld x,y;int n;cin>>x>>y>>n;
    cout<<fixed<<setprecision(6);
    if(n==1){
        cout<<max(x/y,y/x)<<endl;
    }
    else cout<<meow(x,y,n)<<endl;
}
