#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    int ts;cin>>ts;while(ts--){
        ll n;cin>>n;
        if(n==1)cout<<1<<endl;
        else if(n==2)cout<<2<<endl;
        else if(n&1){
            cout<<(n*(n-1)*(n-2))<<endl;
        }
        else{
            cout<<(n*(n-1)*(n-3))<<endl;
        }
    }
}
