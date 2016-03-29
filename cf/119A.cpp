#include<bits/stdc++.h>
using namespace std;;

int gcd(int a,int b){
    int mx=max(a,b);
    int mn=min(a,b);
    while(1){    //   cout<<"jizz"<<endl;
        mx -= (mx/mn)*mn;

        if(mx==0){return mn;}

        int t=mx;mx=mn;mn=t;

    }
}

int main(){
    int a,b,n;cin>>a>>b>>n;

    while(1){
        n -= gcd(a,n);
        if(n==0){cout<<0<<endl;return 0;}
        n -= gcd(b,n);
        if(n==0){cout<<1<<endl;return 0;}

    }
}
