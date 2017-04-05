#include<bits/stdc++.h>
using namespace std;
#define ld long double

int v[10][10],pp[10][10];
vector<ld> fgh;


ld get(){
    ld xb=0;
    for(ld i:fgh){
        xb+=i;
    }
    xb/=(ld)(int)fgh.size();
    // cout<<xb<<endl;
    ld u=0;
    for(ld i:fgh){
        u+=(i-xb)*(i-xb);
    }
    u/=(ld)(int)fgh.size();
    return sqrt(u);
}
ld V(int xl,int xr,int yl,int yr){
    return (ld)(pp[xr][yr]-pp[xl-1][yr]-pp[xr][yl-1]+pp[xl-1][yl-1]);
}

ld meow(int xl,int xr,int yl,int yr,int n){
    if(n==0)return get();
    ld mn=99987989779.0;
    for(int i=xl;i<xr;++i){
        fgh.push_back(V(xl,i,yl,yr));
        mn=min(mn,meow(i+1,xr,yl,yr,n-1));
        fgh.pop_back();
        fgh.push_back(V(i+1,xr,yl,yr));
        mn=min(mn,meow(xl,i,yl,yr,n-1));
        fgh.pop_back();
    }
    for(int i=yl;i<yr;++i){
        fgh.push_back(V(xl,xr,yl,i));
        mn=min(mn,meow(xl,xr,i+1,yr,n-1));
        fgh.pop_back();
        fgh.push_back(V(xl,xr,i+1,yr));
        mn=min(mn,meow(xl,xr,yl,i,n-1));
        fgh.pop_back();
    }
    return mn;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=8;++i){
        for(int j=1;j<=8;++j){
            cin>>v[i][j];
            pp[i][j]=pp[i-1][j]+pp[i][j-1]+v[i][j]-pp[i-1][j-1];
        }
    }
    cout<<fixed<<setprecision(3)<<meow(1,8,1,8,n)<<endl;
}
