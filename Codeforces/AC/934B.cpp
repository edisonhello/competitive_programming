#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    if(k>36)return cout<<-1<<endl,0;
    while(k){
        if(k>1)cout<<8,k-=2;
        else cout<<6,--k;
    }
}
