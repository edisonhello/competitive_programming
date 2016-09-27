#include<bits/stdc++.h>
using namespace std;
unsigned int a[3];
int main(){
    while(cin>>a[0]>>a[1]>>a[2]){
        sort(a,a+3);
        if(a[0]+a[1]>a[2]){
            cout<<"SAFE\n";
        }
        else{
            cout<<"BYE\n";
        }
    }
}
