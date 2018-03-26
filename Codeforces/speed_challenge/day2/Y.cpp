#include<bits/stdc++.h>
using namespace std;

int main(){
    double x,y; cin>>x>>y;
    double d=sqrt(x*x+y*y);
    int dd=int(floor(d));
    if(dd*dd==x*x+y*y){
        cout<<"black";
    }
    else if((dd&1) ^ (x*y>=0) == 0){
        cout<<"white"<<endl;
    }
    else cout<<"black";
}
