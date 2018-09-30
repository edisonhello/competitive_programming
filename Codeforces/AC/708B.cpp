#include<bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef JIZZ
n*(n-1)/2=a
n*n-n-a*2=0
n=(1+sqrt(1+8*a))/2;
#endif

void no(){
    cout<<"Impossible"<<endl;
    exit(0);
}

int main(){
    ll a,b,c,d; cin>>a>>b>>c>>d;
    // if(a==0){ if(b|c)no(); }
    // if(d==0){ if(b|c)no(); }
    if(abs(round(sqrt(1+8*a))-sqrt(1+8*a))>1e-8)no();
    if(abs(round(sqrt(1+8*d))-sqrt(1+8*d))>1e-8)no();
    ll c0=round(sqrt(1+8*a)),c1=round(sqrt(1+8*d));
    if(c0%2==0 || c1%2==0)no();
    ++c0; c0>>=1; ++c1; c1>>=1;
    // cout<<c0<<" "<<c1<<endl;
    if(a==0){ 
        if(b|c){
            if(b+c!=c1)no();
            while(c--)cout<<1;
            cout<<0;
            while(b--)cout<<1;
            cout<<endl;
            exit(0);
        }
        else{
            while(c1--)cout<<1; cout<<endl; exit(0); 
        }
    }
    if(d==0){ 
        if(b|c){
            if(b+c!=c0)no();
            while(b--)cout<<0;
            cout<<1;
            while(c--)cout<<0;
            cout<<endl;
            exit(0);
        }
        else{
            while(c0--)cout<<0; cout<<endl; exit(0); 
        }
    }
    ll oal=c0*c1;
    if(b+c!=oal)no();
    ll front=c/c0,pos=c0-c%c0;
    for(int z=0;z<front;++z)cout<<1;
    for(int z=0;z<pos;++z)cout<<0;
    if(front!=c1)cout<<1;
    for(int z=pos;z<c0;++z)cout<<0;
    for(int z=front+1;z<c1;++z)cout<<1;
    cout<<endl;
}
