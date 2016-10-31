#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int ts;cin>>ts;
    while(ts--){
        float r;cin>>r;
        cout<<fixed<<setprecision(2)<<r*r*acos(-1)*3/4;
        if(ts)cout<<endl;
    }
}
