#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    string in;cin>>in;
    stringstream ss(in.substr(0,in.length()-1));
    long long n;ss>>n;char c=in[in.length()-1];
    long long co=(n-1)/4*16+(n&1?0:7);
    if(c=='f')co+=1;
    if(c=='e')co+=2;
    if(c=='d')co+=3;
    if(c=='c')co+=6;
    if(c=='b')co+=5;
    if(c=='a')co+=4;
    cout<<co<<endl;
}
