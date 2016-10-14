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

ll rit_t,rit_k;
char rit_c;
inline ll rit();
ll m,p,n,s[105],cnt,now,ptr,ed;
int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    m=rit(),p=rit(),n=rit();
    for(int i=0;i<n;i++){
        s[i]=rit();
    }
    s[n]=p;
    now=0,ptr=0,cnt=0,ed=m;
    while(1){
        // cout<<now<<" "<<ed<<endl;
        bool walk=0;
        for(;ptr<=n;ptr++){
            if(s[ptr]<=ed){
                now=s[ptr];
                walk=1;
            }
            else{
                break;
            }
        }
        if(!walk){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        if(ed>=p){
            break;
        }
        ed=now+m;
        cnt++;
    }
    cout<<cnt<<endl;
}

inline ll rit(){
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
