#include<bits/stdc++.h>
using namespace std;
#define ll long long

string ans;
ll d,mxi;

void walk(){
    // cout<<d<<endl;
    if(d>0){
        ans='+'+ans;
        d-=mxi;
    }
    else{
        ans='-'+ans;
        d+=mxi;
    }
    mxi>>=1;
}

int main(){
    cin>>d;
    {
        mxi=1;
        for(;mxi<=d;mxi<<=1){}
        mxi>>=1;
    }
    while(d){
        walk();
    }
    cout<<ans.length()<<'\n'<<ans<<'\n';
}
