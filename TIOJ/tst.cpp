#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define imnot guagua
using namespace std;

inline int rit(){
    int t=0,key=1;
    char j;
    do{
        j=getchar();
        if(j=='-')key=-1;
    }while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t*key;
}

int main(){

    ll m = 8;

    ll ans = 1;
    ll by = 2;

    while(m!=0){
        //n*=by;

        if(m%2==1){
            ans*=by;
        }by*=by;

        m/=2;
    }cout<<ans<<endl;
}
