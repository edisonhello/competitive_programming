#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int rit_t,rit_k;
ll rll_t;
char rit_c;
inline int rit();
inline ll rll();
void INIT();

unsigned ll f[102];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    INIT();
    int m=rit();
    while(m--){
        int n=rit();
        unsigned ll k=rll();
        if(k>f[n]){cout<<-1<<endl;continue;}
        if(k==f[n]){cout<<1<<endl;continue;}
        unsigned ll now=
        while(1){

        }
    }
}

void INIT(){
    f[0]=0;
    f[1]=f[2]=1;
    for(int i=3;i<100;++i){
        f[i]=f[i-1]+f[i-2];
        // cout<<f[i]<<endl;
    }
}

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
inline ll rll(){
    rll_t=0,rit_k=1;
    do{
        rit_c=getchar();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rll_t=rll_t*10+rit_c-'0';
        rit_c=getchar();
    }while(rit_c>='0'&&rit_c<='9');
    return rll_t*rit_k;
}
