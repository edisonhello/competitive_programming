#include<bits/stdc++.h>
using namespace std;
int main(){
    int y;cin>>y;

    int m=0;
    if(!(y%4==0 && (y%100!=0||y%400==0))){
        while(1){
            y++;
            if(y%4==0 && (y%100!=0||y%400==0)){
                m++;
            }
            m++;
            if(m%7==0 && !(y%4==0 && (y%100!=0||y%400==0))){
                cout<<y<<endl;
                return 0;
            }
        }
    }
    else{
        while(1){
            y++;
            if(y%4==0 && (y%100!=0||y%400==0)){
                m++;
            }
            m++;
            if(m%7==0 && y%4==0 && (y%100!=0||y%400==0)){
                cout<<y<<endl;
                return 0;
            }
        }
    }
}
