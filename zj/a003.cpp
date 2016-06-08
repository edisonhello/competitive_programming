#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,d;
    while(cin>>m>>d){
        int s=m*2+d;
        s%=3;
        if(s==0){
            cout<<"普通"<<endl;
        }
        else if(s==1){
            cout<<"吉"<<endl;
        }
        else{
            cout<<"大吉"<<endl;
        }
    }
}
