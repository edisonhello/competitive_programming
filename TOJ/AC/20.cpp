#include<bits/stdc++.h>
using namespace std;

int main(){
long long a,b,c,d; while(cin>>a>>b>>c>>d){
if(a!=c&&b!=d)cout<<abs(a-c)+abs(b-d)+__gcd(abs(a-c),abs(b-d))<<'\n';
else cout<<abs(a-c)+abs(b-d)<<'\n';
}
}
