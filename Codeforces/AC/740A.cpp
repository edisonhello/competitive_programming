#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    ll n,a,b,c;cin>>n>>a>>b>>c;
    if(n%4==0)cout<<0;
    else if(n%4==1){
        cout<<min({a*3,c,a+b});
    }
    else if(n%4==2){
        cout<<min({a*2,b,c*2});
    }

    else if(n%4==3){
        cout<<min({a,b+c,3*c});
    }
    cout<<endl;
}
