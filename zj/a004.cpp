#include<bits/stdc++.h>
using namespace std;
int main(){
    int y;
    while(cin>>y){
        if(y%400==0){
            cout<<"閏年"<<endl;
            continue;
        }
        if(y%100==0){
            cout<<"平年"<<endl;
            continue;
        }
        if(y%4==0){
            cout<<"閏年"<<endl;
            continue;
        }
        cout<<"平年"<<endl;
    }
}
