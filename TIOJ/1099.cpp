#include<stdio.h>
#include<set>
#include<queue>
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

char __c;bool __m;int __t;
inline int rit();
template<typename varType>
inline bool rit(varType &inp);
template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args);

struct p{int x,y,z;};
int n,x1,y1,z1,x2,y2,z2;
set<ll> s;
queue<p> q;

ll h(p _p){
    return (ll)_p.x*3005ll*3005ll+(ll)_p.y*3005ll+(ll)_p.z;
}

int main(){
    while(rit(n,x1,y1,z1,x2,y2,z2),n){
        s.clear();
        if(S(q))q.pop();
        if(x1==x2&&y1==y2&&z1==z2){
            printf("Yes\n");
            continue;
        }
        s.insert(h({x1,y1,z1}));
        q.push({x1,y1,z1});
        while(S(q)){
            p c=q.front();q.pop();
            if(s.count(h({c.y,c.x,c.z}))){}
            else if(c.y==x2&&c.x==y2&&c.z==z2){
                printf("Yes\n");
                goto getAns;
            }
            else{
                s.insert(h({c.y,c.x,c.z}));
                q.push({c.y,c.x,c.z});
            }
            if(s.count(h({c.z,c.y,c.x}))){}
            else if(c.z==x2&&c.y==y2&&c.x==z2){
                printf("Yes\n");
                goto getAns;
            }
            else{
                s.insert(h({c.z,c.y,c.x}));
                q.push({c.z,c.y,c.x});
            }
            if(s.count(h({c.x,c.z,c.y}))){}
            else if(c.x==x2&&c.y==z2&&c.z==y2){
                printf("Yes\n");
                goto getAns;
            }
            else{
                s.insert(h({c.x,c.z,c.y}));
                q.push({c.x,c.z,c.y});
            }
            if(s.count(h({2*c.y-c.x+1,2*c.x-c.y-1,c.z}))){}
            else if(2*c.y-c.x+1==x2&&2*c.x-c.y-1==y2&&c.z==z2){
                printf("Yes\n");
                goto getAns;
            }
            else{
                if(2*c.y-c.x+1<0 || 2*c.y-c.x+1>n || 2*c.x-c.y-1<0 || 2*c.x-c.y-1>n)continue;
                s.insert(h({2*c.y-c.x+1,2*c.x-c.y-1,c.z}));
                q.push({2*c.y-c.x+1,2*c.x-c.y-1,c.z});
            }
        }
        printf("No\n");
        getAns:;
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
