#include "lib1338.h"
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
#define ld long double
#define vint vector<int>
#define pii pair<int,int>
#define MS0(x) memset((x),0,sizeof(x))


int n;
ll *c;
ll mnv[20][1000006];
ll gcd[20][1000006];

ll _gcd(ll a,ll b){
    if(b>a)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

void init(int N, long long C[]){
    n=N;c=C;

    for(int i=0;i<n;++i){
        mnv[0][i]=gcd[0][i]=c[i];
    }
    for(int i=1,k=1;i<n;i<<=1,++k){
        for(int j=0;i+j<=n-i;j++){
            // if(i==2)cout<<i<<" "<<j<<" "<<mnv[k-1][j]<<" "<<mnv[k-1][j+i]<<endl;
            mnv[k][j]=min(mnv[k-1][j],mnv[k-1][j+i]);
            gcd[k][j]=_gcd(gcd[k-1][j],gcd[k-1][j+i]);
            // cout<<mnv[k][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<endl;
}
int query(int l, int r){
    --r;
    int m=r-l+1;
    // cout<<"m="<<m<<endl;
    ll mn=(1ll<<63)-1;
    ll g=0;
    for(int i=1,j=1;i<=m;i<<=1,++j){
        if(i&m){
            // cout<<j-1<<" "<<r-i+1<<" ";
            mn=min(mn,mnv[j-1][r-i+1]);
            if(!g)g=gcd[j-1][r-i+1];
            else g=_gcd(g,gcd[j-1][r-i+1]);
            // cout<<mnv[j-1][r-i+1]<<endl;
            r-=i;
        }
    }
    return g==mn;
}
