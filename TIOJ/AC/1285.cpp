#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        int cnt=0;
        if(m>n)swap(m,n);
        while(m){
            cnt+=n/m;
            n%=m;
            swap(n,m);
        }
        cout<<cnt<<'\n';
    }
}
