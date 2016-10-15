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
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int rit_t,rit_k;
char rit_c;
inline int rit();

int m,n,a[205][205],dp[205][205],ud[205][205],stpnt[205];

int main(){
    m=rit(),n=rit();
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            a[i][j]=rit();
            if(a[i][j]==1){
                ud[i][j]=ud[i-1][j]+1;
            }
            // cout<<ud[i][j]<<" ";
        }
        // cout<<endl;
    }
    int mxarea=0;
    for(int i=1;i<=m;++i){
        MS0(stpnt);
        int nowh=0;
        for(int j=0;j<=n+1;++j){
            if(nowh<ud[i][j]){
                ++nowh;
                for(;nowh<=ud[i][j];++nowh){
                    stpnt[nowh]=j;
                }
                --nowh;
            }
            else if(nowh>ud[i][j]){
                for(;nowh>ud[i][j];--nowh){
                    mxarea=max(mxarea,(j-stpnt[nowh])*nowh);
                }
            }
        }
    }
    cout<<mxarea<<'\n';
}

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar_unlocked();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar_unlocked();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
