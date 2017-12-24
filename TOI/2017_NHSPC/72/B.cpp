#include<bits/stdc++.h>
using namespace std;
int pw(int b,int n,int a=1){
    while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    } return a;
}
int meow(int N,int b){
    stack<int> st;
    while(N){
        st.push(N%b);
        N/=b;
    }
    int rt=0;
    while(st.size()){
        rt=rt*10+st.top();
        st.pop();
    }
    return rt;
}
int main(){
    int b,n,nn,d; cin>>b>>n; nn=n;
    int N=0; d=int(floor(log10(n))+1);
    cout<<"d= "<<d<<endl;
    while(n){
        N+=pw(n%10,d);
        n/=10;
    }
    cout<<"N "<<N<<endl;
    N=meow(N,b);
 //    cout<<
    if(N==nn)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
void dfs(){
        
}
void dfsf(){

}
