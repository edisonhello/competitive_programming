#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second
#define M (l+r)/2

ll n,mxw;
vint a;
ll mx;

inline ll rit(){
    ll t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

void sol(){
    ll MX=pow(2,n);
    for(int i=0;i<MX;i++){
        ll thisw = 0;
        for(int j=1,k=0;k<n;j*=2,k++){
            if(i&j){
                thisw += a[k];
            }
        }
        if(thisw<=mxw){
            mx=max(mx,thisw);
        }
    }
}

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    n=rit();
    mxw=rit();
    a.rz(n);
    for(int i=0;i<n;i++)a[i]=rit();

    sol();
    cout<<mx<<endl;
}
