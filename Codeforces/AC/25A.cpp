#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;
int a[111];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    int odd=0,even=0,on,en;
    for(int i=0;i<n;++i){
        if(a[i]&1)++odd,on=i+1;
        else ++even,en=i+1;
    }
    if(odd==1)cout<<on<<endl;
    else cout<<en<<endl;
}
