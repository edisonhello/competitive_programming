#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b; cin>>a>>b;
    ll p=b-a;
    if(p>=5)cout<<0;
    else{
        ll pos=a%10+1,pos2=b%10,c=1;
        if(pos==10)pos=0;
        if(pos2>=pos)while(pos2>=pos)c*=pos,pos++;
        else if(pos2<pos){while(pos<=9)c*=pos,pos++;while(pos2>0)c*=pos2,pos2--;}
        cout<<c%10;
    }
}
