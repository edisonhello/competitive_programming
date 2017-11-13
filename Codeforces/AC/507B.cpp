#include<bits/stdc++.h>
using namespace std;

int main(){
    long long r,x,y,xx,yy; cin>>r>>x>>y>>xx>>yy;
    long double d=sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y)),rr=r*2;
    // cout<<d<<" "<<r<<endl;
    cout<<int(ceil(d/rr))<<endl;
}
