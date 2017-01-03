#include<iostream>
using namespace std;

int main(){
    int t;cin>>t;while(t--){
        int x;cin>>x;
        if(x>1000){
            cout<<1000<<" "<<x-1000<<endl;
        }
        else{
            cout<<0<<" "<<x<<endl;
        }
    }
}
