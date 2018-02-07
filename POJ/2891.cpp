#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct CRT{
    ll a,m;
} *info;

CRT merge(CRT x,CRT y){
    // new a = x.a + x.m * t =- y.a (mod y.m)
    // let g = gcd(x.m, y.m)
    // (y.a - x.a) / g =- x.m / g * t (mod y.m)
    // so calc x.m * t + y.m * k = g by extgcd
    // (x.m / g) * t + (y.m / g) * k = 1
}

int main(){
    int k; while(cin>>k){
        info=new CRT[k];
        memset(info,0,sizeof(info));
        for(int i=0;i<k;++i)cin>>info[i].a>>info[i].m;
        for(int i=1;i<k;++i)info[1]=merge(info[0],info[1]);
        if(info[k-1].m==-1)cout<<"-1"<<endl;
        else cout<<info[k-1].a%info[k-1].m<<endl;
    }
}
