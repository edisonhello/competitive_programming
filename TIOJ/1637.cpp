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

int a[1000005],n,l[1000005],r[1000005];
ll ans;
stack<int> st;
int main(){
    n=rit();--n;
    for(int i=0;i<n;++i){
        a[i]=rit();
    }
    for(int i=0;i<n;++i){
        if(i && a[i]>=a[i-1])l[i]+=l[i-1]-1;
        if(S(st) && st.top()<=a[i]){
            while(S(st) && st.top()<=a[i]){
                st.pop();
                ++l[i];
            }
        }
        ++l[i];
        st.push(a[i]);
    }
    while(S(st))st.pop();
    for(int i=n-1;i>=0;--i){
        if(i<n-1 && a[i]>a[i+1])r[i]+=r[i+1]-1;
        if(S(st) && st.top()<a[i]){
            while(S(st) && st.top()<a[i]){
                st.pop();
                ++r[i];
            }
        }
        ++r[i];
        st.push(a[i]);
    }
    for(int i=0;i<n;++i)ans+=(ll)l[i]*(ll)r[i]*(ll)a[i];
    printf("%lld\n",ans);
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
