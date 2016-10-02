#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define S0(x) memset((x),0,sizeof(x))
#define SB(x) memset((x),0x7f,sizeof(x))

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar_unlocked();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t*k;
}

map<int,int> mp;
int a[100005];
int main(){
    int n,m;
    n=rit(),m=rit();
    for(int i=1;i<=n;++i){
        int t=rit();
        mp[t]=i;
    }
    for(auto i:mp){
        ++a[i.second];
    }
    for(int i=100002;i>=0;--i){
        a[i]+=a[i+1];
    }
    do{
        int t=rit();
        cout<<a[t]<<'\n';
    }while(--m);
}
