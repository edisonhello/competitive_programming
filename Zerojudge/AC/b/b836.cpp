#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double

int main(){
    ld n,m; while(cin>>n>>m){
        ld sq=sqrt(m*m-m*4+4+n*m*8);
        ld x=((m-2)+sq)/(m*2);
        if(abs(x-round(x))>1e-9)cout<<"No Stop!!"<<endl;
        else cout<<"Go Kevin!!"<<endl;
    }
}
