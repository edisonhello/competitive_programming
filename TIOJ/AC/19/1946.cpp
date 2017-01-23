#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n,N;
int a[(1<<20)];
int lb[(1<<20)],rb[(1<<20)];
int bg[(1<<20)];

inline int lowbit(int x){return x&-x;}
inline void mod(int *BIT,int k,int pos){
    while(pos<=N){
        BIT[pos]+=k;
        pos+=lowbit(pos);
    }
}
inline int que(int *&BIT,int pos){
    int rt=0;
    while(pos){
        rt+=BIT[pos];
        pos-=lowbit(pos);
    }
    return rt;
}
inline int get(int *BIT,int v){
    int pre=que(BIT,v-1),mx=que(BIT,n),
        dist=pre+((mx-pre-1)>>1)+1,
        L=1,R=N,M;
    if(mx-pre==0)return 999999;
    while(R>L){
        M=((L+R)>>1);
        if(que(BIT,M)>=dist)R=M;
        else L=M+1;
    }
    return L-1;
}

int main(){
    int i=0,La,Ra,c,ans=0;
    scanf("%d",&n);
    N=n;while(N!=lowbit(N))N+=lowbit(N);
    for(   ;i<n;++i){scanf("%d",&a[i]);mod(rb,1,i+1);}
    for(i=0;i<n;++i){
        mod(rb,-1,a[i]+1);
        La=get(lb,a[i]+1),Ra=get(rb,a[i]+1);
        mod(lb, 1,a[i]+1);
        c=min(La,Ra);
        if(c==999999)continue;
        ++bg[c];++bg[a[i]];
    }
    for(i=0;i<n;++i)ans=max(ans,bg[i]);
    printf("%d\n",ans);
}
