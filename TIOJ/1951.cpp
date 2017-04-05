#include<iostream>
#include<cmath>
#include<assert.h>
using namespace std;
#define ll long long
#define ld long double

ll X,Y;
ll n,x,y;
ld eps=1e-7;


void dfs(int dep){
    if(dep==1){
        x=n+1;
        for(;x<=3*n;++x){
            dfs(2);
        }
    }
    else if(dep==2){
        y=x;
        for(;y<=2*(n*x/(x-n)+1);++y){
            dfs(3);
        }
    }
    else if(dep==3){
        ld dx=(ld)1/x,dy=(ld)1/y,dn=(ld)1/n;
        ld dz=dn-dx-dy;
        // cout<<x<<" "<<dx<<" "<<y<<" "<<dy<<endl;
        dz=1/dz;
        // cout<<x<<" "<<y<<" "<<dz<<" "<<(int)(floor(dz+0.5))<<endl;
        if(dz-floor(dz+eps)<eps && (ll)(floor(dz+0.5))>=y){
            X+=x,Y+=y;
        }
    }
}

int main(){
    cin>>n;
    // if(n==1)cout<<17<<endl;
    // else if(n==2)cout<<78<<endl;
    // else if(n==3)assert(1==0);
    // else{
        dfs(1);
        cout<<X+Y<<endl;
    // }
}
