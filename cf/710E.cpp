#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

inline int rit(){
    int t=0,k=1;
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
};

int n,x,y;
int a[1000007];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    cin>>n>>x>>y;

    a[1]=x;
    for(int i=2;i<=n;i++){
        if(i&1){
            a[i]=min(a[i/2+1]+y,a[i-1]+x);
        }
        else{
            a[i]=min(a[i/2]+y,a[i-1]+x);
        }
    }
    cout<<a[n]<<endl;
}
