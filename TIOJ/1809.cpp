#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define vint vector<int>
#define pii pair<int,int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;

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

ll n,m,q;
vector<pair<int,int> > h;

int _f(int a,int b){
    int l=0,r=h.size();
    pii t=MP(a,b);
    while(r-l>1){
        int m=(l+r)/2;
        // printf("%d %d %d\n",l,r,m);

        if(t==h[m])return 1;
        if(t>h[m])l=m;
        else r=m;
    }
    if(t==h[m])return 1;
    return 0;
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    n=rit(),m=rit(),q=rit();
    for(ll i=0;i<m;i++){
        ll a=rit(),b=rit();
        h.PB(MP(a,b));
        h.PB(MP(b,a));
    }
    sort(h.begin(),h.end());
    // for(int i=0;i<h.size();i++){
    //     printf("%d %d\n",h[i].X,h[i].Y);
    // }
    for(ll i=0;i<q;i++){
        ll a=rit(),b=rit();
        if(_f(a,b) || _f(b,a)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}