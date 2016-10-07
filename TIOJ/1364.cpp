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

inline int rit();
int n,k,t;
PQ<int,vector<int>,greater<int>> pq;
int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    while(scanf("%d%d",&n,&k)!=EOF){
        while(pq.size())pq.pop();
        for(int i=0;i<n;++i){
            t=rit();
            pq.push(t);
            if(pq.size()>k)pq.pop();
        }
        printf("%d\n",pq.top());
    }
}

int rit_t,rit_k;
char rit_c;

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
