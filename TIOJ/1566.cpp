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
#define md (l+r)/2
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

char __c;bool __m;int __t;
inline int rit();
template<typename varType>
inline bool rit(varType &inp);
template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args);

int n,m,k,h[10000007];
PQ<pii,vector<pii>,greater<pii>> gt;
PQ<pii,vector<pii>,less<pii>> ls;
vector<pii> anss;

int main(){
    n=rit(),m=rit(),k=rit();
    for(int i=1;i<=n;++i){
        h[i]=rit();
    }
    for(int ed=1,st=ed-m+1;st<=n;++st,++ed){
        while(S(gt) && gt.top().Y<st)gt.pop();
        while(S(ls) && ls.top().Y<st)ls.pop();
        gt.push({h[ed],ed});
        ls.push({h[ed],ed});
        // cout<<ls.top().X<<" "<<gt.top().X<<endl;
        if(ls.top().X-gt.top().X==k){
            anss.push_back({st,ed});
        }
    }
    /*for(int i=-m+1;i<=n;++i){
        gt.push({h[i+m],i+m});
        ls.push({h[i+m],i+m});
        while(gt.top().Y<=i)gt.pop();
        while(ls.top().Y<=i)ls.pop();
        if(ls.top().X-gt.top().X==k){
            cout<<"i = "<<i<<" "<<ls.top().X<<" "<<ls.top().Y<<" "<<gt.top().X<<" "<<gt.top().Y<<endl;
            anss.PB(i);
        }
    }*/
    printf("%d\n",S(anss));
    for(pii v:anss){
        if(v.X<1)printf("1 ");
        else printf("%d ",v.X);
        if(v.Y>n)printf("%d\n",n);
        else printf("%d\n",v.Y);
    }
}

inline int rit(){
    __t=0,__m=0;
    do{
        __c=getchar();
    }while((__c<'0'||__c>'9')&&(__c!='-'));
    if(__c=='-')__m=1;
    do{
        __t=__t*10+__c-'0';
        __c=getchar();
    }while(__c>='0'&&__c<='9');
    if(__m)__t=-__t;
    return __t;
}

template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args){
    return rit(inp)&&rit(args...);
}

template<typename varType>
inline bool rit(varType &inp){
    inp=0;__m=0;
    do{
        __c=getchar();
        if(__c==-1)return false;
    }while((__c<'0'||__c>'9')&&__c!='-');
    if(__c=='-')__m=1;
    do{
        inp=inp*10+__c-'0';
        __c=getchar();
    }while(__c>='0'&&__c<='9');
    if(__m)inp=-inp;
    return true;
}
