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
struct pnt{int d,t;};
bool operator > (const pnt &a,const pnt &b){return a.t>b.t;};
int ts,n,m,s,k[10004],edh,lowcn[10004],lowcv[10004];
vector<int> G[10004];
bitset<10004> gone;
PQ<pnt,vector<pnt>,greater<pnt>> pq;

int main(){
    ts=rit();
    for(int cs=1;cs<=ts;cs++){
        n=rit(),m=rit(),s=rit();
        edh=(1<<30);
        gone.reset();
        MSB(lowcn);
        MSB(lowcv);
        while(pq.size())pq.pop();
        for(int i=0;i<n;i++){
            k[i]=rit();
            if(k[i]<edh){
                edh=k[i];
            }
            G[i].clear();
        }
        // cout<<"k:";for(int i=0;i<n;i++)cout<<k[i]<<" ";cout<<endl;
        for(int i=0;i<m;i++){
            int _=rit(),__=rit();
            G[_].PB(__);
            G[__].PB(_);
            if(lowcv[_]>k[__] && k[__]<k[_]){
                lowcv[_]=k[__];
                lowcn[_]=__;
            }
            if(lowcv[__]>k[_] && k[_]<k[__]){
                lowcv[__]=k[_];
                lowcn[__]=_;
            }
        }
        // cout<<"lowcv:";for(int i=0;i<n;i++)cout<<lowcv[i]<<" ";cout<<endl;
        // cout<<"lowcn:";for(int i=0;i<n;i++)cout<<lowcn[i]<<" ";cout<<endl;
        int CAR;
        {
            int now=s;
            int cnt=0;
            while(k[now]!=edh){
                if(lowcv[now]==0x7f7f7f7f){
                    break;
                }
                now=lowcn[now];
                cnt++;
            }
            if(k[now]==edh){
                CAR=cnt;
            }
            else{
                CAR=0x789abcde;
            }
        }
        int WAK=0x789abcde;
        {
            pq.push({s,0});
            gone[s]=1;
            while(pq.size()){
                if(k[pq.top().d]==edh){
                    WAK=pq.top().t;
                    break;
                }
                for(int i=0;i<(int)G[pq.top().d].size();i++){
                    pq.push({G[pq.top().d][i],pq.top().t+1});
                    gone[G[pq.top().d][i]]=1;
                }
                pq.pop();
            }
        }
        // cout<<"CAR:"<<CAR<<", WAK:"<<WAK<<endl;
        cout<<"Case #"<<cs<<": ";
        if(WAK==0x789abcde){
            cout<<"Call 119!\n";
        }
        else if(CAR==0x789abcde){
            cout<<WAK*6<<'\n';
        }
        else{
            cout<<WAK*6-CAR<<'\n';
        }
    }
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
