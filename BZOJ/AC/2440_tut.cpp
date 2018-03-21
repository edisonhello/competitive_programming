#include<iostream>
using namespace std;

int u[45000];

long long clc(long long x){
    long long rt=0;
    for(int i=1;i*i<=x;++i){
        rt+=u[i]*1ll*(x/(i*i));
    }
    return rt;
}

long long get(int x){
    long long L=1,R=2000000000,a=-1;
    while(R>L){
        long long m=(L+R)>>1;
        if(clc(m)>=x)a=m,R=m;
        else L=m+1;
    }
    return a;
}

int main(){
    u[1]=1;
    for(int i=1;i<45000;++i){
        for(int j=i*2;j<45000;j+=i){
            u[j]-=u[i];
        }
    }

    int q; cin>>q; while(q--){
        int x; cin>>x;
        cout<<get(x)<<'\n';
    }
}
