#include<bits/stdc++.h>
#include "lib1172.h"
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
#define m (l+r)/2
#define dm (dl+dr)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;


int ar[1000006];
int *d_;
void BS(int l,int r,int dl,int dr){
    if(l==r)return ;
    if(dl==dr)return ;
    nth_element(ar+l,ar+d_[dm],ar+r+1,comp);
    BS(l,d_[dm],dl,dm);
    BS(d_[dm]+1,r,dm+1,dr);
}
void query(int n, int D[], int l, int ans[]){
    d_=D;
    for(int i=0;i<=n+1;i++)ar[i]=i;
    BS(0,n-1,0,l);
    int ptr=0;
    for(int i=0;i<l;i++){
        ans[i]=ar[d_[i]];
    }
}
