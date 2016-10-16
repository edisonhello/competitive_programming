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
char rit_c;
inline int rit();
inline void rT(string&);
struct line{int lo,ev;};
struct _pq{int pt,tm;};
bool operator>(const _pq &a,const _pq &b){
    return a.tm>b.tm;
}
int n,m,nb,ne,ts,te;
string STst,STed;
line g[105][105];
void init();
int getT(string&);
bitset<105> v;
int d[105];


int main(){
    while(scanf("%d%d",&n,&m)!=EOF,n){
        init();
        for(int i=0,a,b,p,t;i<m;i++){
            a=rit(),b=rit(),p=rit(),t=rit();
            g[a][b]={t,p};
        }
        nb=rit(),ne=rit();
        rT(STst),rT(STed);
        ts=getT(STst);te=getT(STed);

        PQ<_pq,vector<_pq>,greater<_pq>> pq;
        pq.push({nb,ts});
        for(int _i=0;_i<n;++_i){
            while(S(pq)&&v[pq.top().pt]){
                pq.pop();
            }
            if(S(pq)==0)break;
            v[pq.top().pt]=1;
            d[pq.top().pt]=pq.top().tm;
            int np=pq.top().pt,nt=pq.top().tm;
            for(int i=1;i<=n;++i){                          // waiting time
                if(g[np][i].lo!=0 && d[i]>d[np]+g[np][i].lo+(g[np][i].ev-(d[np]%g[np][i].ev)%g[np][i].ev)){
                    d[i]=d[np]+g[np][i].lo+(g[np][i].ev-(d[np]%g[np][i].ev)%g[np][i].ev);
                    pq.push({i,d[np]+g[np][i].lo+(g[np][i].ev-(d[np]%g[np][i].ev)%g[np][i].ev)});
                }
            }
        }
        cout<<ts<<" "<<te<<endl;
        if(d[ne]==0x7f7f7f7f){
            printf("No way\n");
            continue;
        }
        else{
            printf("--%d--\n",d[ne]);
        }
    }
}
void init(){
    MS0(g);
    MSB(d);
    v.reset();
}
int getT(string &inp){
    int t=0,_t=0;
    t+=inp[0]-'0';
    t*=10;
    t+=inp[1]-'0';
    t*=60;
    _t+=inp[3]-'0';
    _t*=10;
    _t+=inp[4]-'0';
    return t+_t;
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
inline void rT(string &inp){
    inp="";
    do{
        rit_c=getchar();
    }while(rit_c<'0'||rit_c>'9');
    inp+=rit_c;
    rit_c=getchar();inp+=rit_c;
    rit_c=getchar();inp+=rit_c;
    rit_c=getchar();inp+=rit_c;
    rit_c=getchar();inp+=rit_c;
    return;
}
