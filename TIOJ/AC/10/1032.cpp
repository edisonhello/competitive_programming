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
unordered_map<int,pair<int,int>> G[100005];
int n,m,val[100005];
int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    rit(n,m);
    srand(7122345);
    while(m--){
        int com=rit();
        if(com==0){
            int a,b;rit(a,b);if(a>b)swap(a,b);
            if(G[a][b].Y==0){
                int rd=rand();
                G[a][b].X=rd;
                G[a][b].Y=1;
                val[a]^=rd;
                val[b]^=rd;
            }
            else{
                ++G[a][b].Y;
            }
        }
        else if(com==1){
            int a,b;rit(a,b);if(a>b)swap(a,b);
            if(G[a][b].Y==1){
                val[a]^=G[a][b].X;
                val[b]^=G[a][b].X;
                G[a].erase(G[a].find(b));
            }
            else{
                --G[a][b].Y;
            }
        }
        else if(com==2){
            int k=rit();
            int nowv=0,t;
            while(k--){
                t=rit();
                nowv^=val[t];
            }
            if(nowv==0){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
    }
}


inline int rit(){
    __t=0,__m=0;
    do{
        __c=getchar();
        if(__c=='-')__m=1;
    }while((__c<'0'||__c>'9'));
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
        if(__c=='-')__m=1;
    }while((__c<'0'||__c>'9'));
    if(__c=='-')__m=1;
    do{
        inp=inp*10+__c-'0';
        __c=getchar();
    }while(__c>='0'&&__c<='9');
    if(__m)inp=-inp;
    return true;
}
