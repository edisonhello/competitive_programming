#include<bits/stdc++.h>
using namespace std;

int SG[1000006];
int go[1000006];
bitset<1000006> v;

#ifndef WEAK
#include "lib1820.h"
#else
int initial(){
    int t; cin>>t; return t;
}
#endif

int sg(int n){
    if(v[n])return SG[n];
    v[n]=1;
    SG[n]=0;
    for(int i=n-1;i>1;--i){
        if(n%i)continue;
        if(sg(n-i));
        else{
            SG[n]=1;
            go[n]=i;
            break;
        }
    }
    return SG[n];
}

int main(){
    int n=initial();
    if(sg(n)){
        first(true);
    }
    else{
        int v=first(false);
        n-=v;
    }
    while(1){
        int m=go[n];
        n-=m;
        n-=play_with_loli(m);
    }
}
