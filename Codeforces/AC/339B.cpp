#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int ptr=1;
    ll t=1;
    while(m--){
        int tmp;cin>>tmp;
        if(tmp<ptr){
            t+=n-ptr+tmp;
            ptr=tmp;
        }
        else{
            t+=tmp-ptr;
            ptr=tmp;
        }
    }
    cout<<t<<endl;
}
