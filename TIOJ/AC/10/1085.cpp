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

char __c;bool __m;int __t;
inline int rit();
template<typename varType>
inline bool rit(varType &inp);
template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args);

int x,y,z;
bool mp[55][55][55],go[55][55][55];
struct P{int x,y,z;};
struct S{P c;vector<P> h;};
queue<S> q;
int main(){
    rit(x,y,z);
    for(int k=1;k<=z;++k){
        for(int j=1;j<=y;++j){
            for(int i=1;i<=x;++i){
                rit(mp[i][j][k]);
                mp[i][j][k]^=1;
            }
        }
    }
    if(mp[1][1][1]==0||mp[x][y][z]==0){
        printf("no route\n");
        return 0;
    }

    q.push({{1,1,1},(vector<P>)0});
    go[1][1][1]=1;
    S t;
    while(S(q)){
        t=q.front();q.pop();
        t.h.push_back({t.c.x,t.c.y,t.c.z});
        if(t.c.x==x&&t.c.y==y&&t.c.z==z)goto hasrd;
        if(mp[t.c.x+1][t.c.y][t.c.z]&&!go[t.c.x+1][t.c.y][t.c.z]){q.push({{t.c.x+1,t.c.y,t.c.z},t.h});go[t.c.x+1][t.c.y][t.c.z]=1;}
        if(mp[t.c.x-1][t.c.y][t.c.z]&&!go[t.c.x-1][t.c.y][t.c.z]){q.push({{t.c.x-1,t.c.y,t.c.z},t.h});go[t.c.x-1][t.c.y][t.c.z]=1;}
        if(mp[t.c.x][t.c.y+1][t.c.z]&&!go[t.c.x][t.c.y+1][t.c.z]){q.push({{t.c.x,t.c.y+1,t.c.z},t.h});go[t.c.x][t.c.y+1][t.c.z]=1;}
        if(mp[t.c.x][t.c.y-1][t.c.z]&&!go[t.c.x][t.c.y-1][t.c.z]){q.push({{t.c.x,t.c.y-1,t.c.z},t.h});go[t.c.x][t.c.y-1][t.c.z]=1;}
        if(mp[t.c.x][t.c.y][t.c.z+1]&&!go[t.c.x][t.c.y][t.c.z+1]){q.push({{t.c.x,t.c.y,t.c.z+1},t.h});go[t.c.x][t.c.y][t.c.z+1]=1;}
        if(mp[t.c.x][t.c.y][t.c.z-1]&&!go[t.c.x][t.c.y][t.c.z-1]){q.push({{t.c.x,t.c.y,t.c.z-1},t.h});go[t.c.x][t.c.y][t.c.z-1]=1;}
    }
    printf("no route\n");
    return 0;

    hasrd:;
    for(int i=0;i<S(t.h);++i){
        if(i)printf("->");
        printf("(%d,%d,%d)",t.h[i].x,t.h[i].y,t.h[i].z);
    }
    printf("\n");
    return 0;
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
