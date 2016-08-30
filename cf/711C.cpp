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

struct node{
    vector<*node> ch;
}

int n,m,k;
int c[105];
int p[105][105];
// vector<ll> ans;

int bfs(int from,ll l){
    for(;from<=n;from++){
        if(c[from]==0)break;
    }
how to end
judge to cut
    ll mn=1<<60;
    for(int i=1;i<=m;i++){
        c[from]=i;
        mn = min(bfs(from,l+p[from][i]),mn);
    }
    c[from]=0;
    return mn;
}

int main(){
    n=rit();
    m=rit();
    k=rit();
    for(int i=1;i<=n;i++)c[i]=rit();
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=rit();

    cout<<bfs(1,0)<<endl;
}
