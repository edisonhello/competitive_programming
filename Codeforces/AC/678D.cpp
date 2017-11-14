#include<bits/stdc++.h>
using namespace std;
#define int long long

int pw(int b,int n,const int &m,int a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a%m;
}
signed main(){
    int a,b,n,x,m=1000000007; 
    cin>>a>>b>>n>>x;
    int pan=pw(a,n,m);
    if(a>1)cout<<(pan*x%m+b*(pan-1)%m*pw(a-1,m-2,m)%m)%m<<endl;
    else cout<<(x+n%m*b)%m;
}
