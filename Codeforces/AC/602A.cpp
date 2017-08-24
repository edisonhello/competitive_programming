#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;

int main(){
    ll na,ba;cin>>na>>ba;
    ll a[100];
    for(ll i=0;i<na;i++)cin>>a[i];
    ll nb,bb;cin>>nb>>bb;
    ll b[100];
    for(ll i=0;i<nb;i++)cin>>b[i];

    ll ans=0;
    for(ll i=na-1,f=1;i>=0;i--,f*=ba){
        ans+=(ll)f*(ll)a[i];  //cout<<ans<<endl;
    }//cout<<endl;
    for(ll i=nb-1,f=1;i>=0;i--,f*=bb){
        ans-=(ll)f*(ll)b[i];  //cout<<ans<<endl;
    }//cout<<endl;

    if(ans>0)cout<<">"<<endl;
    if(ans==0)cout<<"="<<endl;
    if(ans<0)cout<<"<"<<endl;
}
