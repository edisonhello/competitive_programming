#include<bits/stdc++.h>
using namespace std;
int main(){
    #define ll long long
    ll h,m,s;
    cin>>h>>m>>s;
    m+=s/60;s%=60;
    h+=m/60;m%=60;
    h%=24;
    printf("%02lld:%02lld:%02lld\n",h,m,s);
}
