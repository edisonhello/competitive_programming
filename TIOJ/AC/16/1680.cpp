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
bool ms[10000];
int a[10000];
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>ms[i];
    }
    string line;
    getline(cin,line);
    for(int i=0,t=0;i<n;++i,t=0){
        getline(cin,line);
        SS ss(line);
        while(ss>>a[t++]){/*cout<<"t="<<t<<", a[t-1]="<<a[t-1]<<endl;*/}
        --t;
        // cout<<t<<endl;
        for(int j=t-2;j>=0;--j){
            // cout<<"ae"<<endl;
            // cout<<"comp to j="<<j<<" : "<<a[j]<<" < "<<abs(a[j+1]-a[j+2])<<endl;;
            if((a[j]<abs(a[j+1]-a[j+2]))!=ms[j])goto notU;
            // a[j]=abs(a[j]-a[j+1]);
        }
        // cout<<"line";
        cout<<line<<'\n';
        return 0;
        notU:;
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
