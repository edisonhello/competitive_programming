#include<bits/stdc++.h>
using namespace std;

bool ok(int h,int m){
    if(h%10==7 || m%10==7)return 1;
    return 0;
}

int main(){
    int x,h,m; cin>>x>>h>>m;
    int cnt=0;
    while(!ok(h,m)){
        ++cnt;
        m-=x;
        if(m<0)m+=60,--h;
        if(h<0)h+=24;
    }
    cout<<cnt<<endl;
}
