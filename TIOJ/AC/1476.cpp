#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int t,a[50],n,i;
char c;
inline int rit(){
    do{
        c=getchar_unlocked();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t;
}
int main(){
    n=rit();
    a[1]=1;
    a[2]=2;
    for(i=3;i<=n;++i){
        a[i]=a[i-1]+a[i-2];
    }
    cout<<a[n]<<'\n';
}
