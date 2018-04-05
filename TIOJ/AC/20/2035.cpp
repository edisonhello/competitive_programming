#include<bits/stdc++.h>
using namespace std;

int val(int b,string n){
    reverse(n.begin(),n.end());
    int rt=0,nb=1;
    for(char c:n){
        rt+=nb*(c-'0');
        nb*=b;
    }
    return rt;
}
int evl(int l,string n){
    int rt=0;
    for(char c:n){
        c-='0';
        int add=1;
        for(int i=0;i<l;++i)add*=c;
        rt+=add;
    }
    return rt;
}

int main(){
    int b; string n; cin>>b>>n;
    int l=n.size();
    cout<<(val(b,n)==evl(l,n)?"YES":"NO")<<endl;
}
