#include<bits/stdc++.h>
using namespace std;
int pw(int b,int n,int a=1){
    while(n){
        if(n&1)a=a*b;
        else b=b*b; n>>=1;
    } return a;
}
int main(){
    int b,n,nn; cin>>b>>n; nn=n;
    int N=0;
    while(n){
        N+=pw(n%10,b);
        n/=10;
    }
    if(N=nn)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
void dfs(){
        
}
void dfsf(){

}
