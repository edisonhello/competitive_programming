#include<bits/stdc++.h>
using namespace std;

int SG[1000006];
int go[1000006];
bitset<1000006> v;

#ifndef WEAK
#include "lib1820.h"
/*
int _total=0;
int initial(){
    int t; cin>>t; 
    _total=t;
    return t;
}
int first(bool is_first){
    cout<<"is_first: "<<is_first<<endl;
    if(is_first==0){
        int t; cin>>t; 
        _total-=t;
        return t;
    }
    return 0;
}
int play_with_loli(int now){
    cout<<"play_with_loli "<<now<<endl;
    _total-=now;
    cout<<"left "<<_total<<endl;
    int t; cin>>t; _total-=t;
    return t;
}
*/
#else
#endif

int sg(int n){
#ifdef WEAK
    if(v[n])return SG[n];
    v[n]=1;
    SG[n]=0;
    for(int i=2;i<n;++i){
        if(n%i)continue;
        if(sg(n-i));
        else{
            SG[n]=1;
            go[n]=i;
            break;
        }
    }
    return SG[n];
#else
    if(n&1)return 0;
    if(!((n&-n)==n))return 1;
    int cnt=0;
    while(n%2==0)n>>=1,++cnt;
    if(cnt&1)return 0;
    return 1;
#endif
}

int main(){
#ifdef WEAK
    int n; cin>>n;
    // cout<<sg(n)<<endl;
    for(int i=1;i<=n;++i){
        cout<<sg(i)<<" ";
        if(i%10==0)cout<<endl;
        // sg(i);
        // if(i%2==0 && go[i] && go[i]%2==0)cout<<i<<" "<<sg(i)<<" "<<go[i]<<endl;
    }
#else
    int n=initial();
    if(sg(n))first(true);
    else{
        int v=first(false);
        n-=v;
    }
    while(1){
        if((n&-n)==n){
            int g=n>>1;
            n-=g;
            n-=play_with_loli(g);
        }
        else{
            int nn=n;
            while(nn%2==0)nn/=2;
            n-=nn;
            n-=play_with_loli(nn);
        }
    }
#endif
}
/*
4 1 2
10 1 2
16 1 8
34 1 2
64 1 32
130 1 2
136 1 8
256 1 128
514 1 2
1024 1 512
2050 1 2
2056 1 8
4096 1 2048
8194 1 2
8224 1 32
16384 1 8192
32770 1 2
32776 1 8
32896 1 128
65536 1 32768
131074 1 2
262144 1 131072
524290 1 2
524296 1 8
*/
