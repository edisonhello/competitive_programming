#include<bits/stdc++.h>
using namespace std;

int main(){
    /* int c1=1,c2=1,c3=1,c4=1;
    for(int i=0;i<=100;++i){
        cout<<i<<" ";
        cout<<(c1+c2+c3+c4)%5<<endl;
        c2=c2*2%5;
        c3=c3*3%5;
        c4=c4*4%5;
    }*/
    string s; cin>>s;
    if(s.size()>3)s=s.substr(s.size()-3,3);
    stringstream ss(s);
    int n; ss>>n;
    if(n%4==0)cout<<4<<endl;
    else cout<<0<<endl;
}
