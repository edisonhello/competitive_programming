#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,ans=0;cin>>n;


    int _1=0,_2=0,_3=0;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(t==4)ans++;
        else if(t==3)_3++;
        else if(t==2)_2++;
        else if(t==1)_1++;
    }
    int jizz = min (_3,_1);
    ans += jizz;
    _3  -= jizz;
    _1  -= jizz;
    if(_3!=0)ans += _3;
    _3   =    0;
    ans += _2/2;
    _2  %=    2;
    if(_2){
    _2  --     ;
    _1  -=    2;
    ans ++     ;}
    if(_1>0){
    ans +=(_1+3)/4;
    }


    cout<<ans<<endl;
}
