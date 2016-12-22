#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int n,k,a,b;
char c[100005];

int main(){
    cin>>n>>k>>a>>b;
    for(int i=0,ct=0;i<n;++i){
        if(a<0||b<0){cout<<"NO\n";return 0;}
        if(a>b){
            if(ct<k){
                c[i]='G';--a;
                if(!ct)++ct;
                else if(c[i-1]=='G')++ct;
                else if(c[i-1]=='B')ct=1;
            }
            else if(c[i-1]=='B'){
                c[i]='G';--a;ct=1;
            }
            else{
                c[i]='B';--b;ct=1;
            }
        }
        else if(a<b){
            if(ct<k){
                c[i]='B';--b;
                if(!ct)++ct;
                else if(c[i-1]=='B')++ct;
                else if(c[i-1]=='G')ct=1;
            }
            else if(c[i-1]=='B'){
                c[i]='G';--a;ct=1;
            }
            else{
                c[i]='B';--b;ct=1;
            }
        }
        else if(a==b){
            if(i==0){
                c[i]='B';--b;ct=1;
            }
            else if(c[i-1]=='B'){
                c[i]='G';--a;ct=1;
            }
            else{
                c[i]='B';--b;ct=1;
            }
        }
        // cout<<c[i]<<" "<<a<<" "<<b<<" "<<ct<<endl;
    }
    if(a<0||b<0){cout<<"NO\n";return 0;}
    for(int i=0;i<n;++i){
        cout<<c[i];
    }
    cout<<endl;
}
