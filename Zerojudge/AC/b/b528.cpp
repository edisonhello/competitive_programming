#include<bits/stdc++.h>
using namespace std;
#define ld long double


int main(){
    ld y; while(cin>>y){
        if(abs(y)>1){
            cout<<"FAIL!"<<endl;
            continue;
        }
        y=asin(y);
        if(abs(y)>1){
            cout<<"FAIL!"<<endl;
            continue;
        }
        y=acos(y);
        cout<<fixed<<setprecision(2)<<y*180/acos(-1)<<endl;
    }
}
