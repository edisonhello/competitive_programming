#include<bits/stdc++.h>
using namespace std;

int main(){
    int i; cin>>i;
    bool first=1;
    while(i or first){
        first=0;
        int n=i%10; i/=10;
        if(n>=5)cout<<"-O|";
        else cout<<"O-|";
        n%=5;
        if(n==0)cout<<"-OOOO\n";
        if(n==1)cout<<"O-OOO\n";
        if(n==2)cout<<"OO-OO\n";
        if(n==3)cout<<"OOO-O\n";
        if(n==4)cout<<"OOOO-\n";
    }
}
