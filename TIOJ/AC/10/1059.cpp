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

ll s,t,n,tmp,tot;


int main(){
    s=rit(),t=rit(),n=rit();
    for(int i=0;i<n;i++){
        tmp=rit();
        tot+=tmp;
    }
    ll pay=s*t*3/10;
    ll get=0;
    if(tot>=t/5){
        get+=t/5*s*7/10;
        tot-=t/5;
        if(tot>=t/5){
            get+=t/5*s*4/5;
            tot-=t/5;
            if(tot>=t/5){
                get+=t/5*s*9/10;
                tot-=t/5;
                get+=tot*s;
            }
            else{
                get+=tot*s*9/10;
            }
        }
        else{
            get+=tot*s*4/5;
        }
    }
    else{
        get+=tot*s*7/10;
    }
    // cout<<get<<" "<<pay<<endl;
    printf("%lld\n",get-pay);
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
