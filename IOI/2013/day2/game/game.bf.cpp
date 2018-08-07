#include "grader.h"
#include<bits/stdc++.h>

#define ll int_fast64_t

using namespace std;

ll a[111][111];

void init(int r,int c){}

void update(int p, int q, long long v){
    a[p][q]=v;
}

long long calculate(int x1, int y1, int x2, int y2){
    ll v=0;
    for(int i=x1;i<=x2;++i)for(int j=y1;j<=y2;++j)v=__gcd(v,a[i][j]);
    cout<<"member in this query: "<<x1<<" "<<y1<<" to "<<x2<<" "<<y2<<endl;
    for(int i=x1;i<=x2;++i){
        for(int j=y1;j<=y2;++j)cout<<setw(3)<<a[i][j];
        cout<<endl;
    }
    return v;
}
