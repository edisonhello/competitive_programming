#include<bits/stdc++.h>
using namespace std;
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

int n;
bool pm[1000005];
bitset<1000005> v;
stack<int> ans;
void init(){
    pm[1]=1;
    for(int i=2;i<1000003;++i){
        for(int j=2*i;j<1000003;j+=i){
            pm[j]=1;
        }
    }
}

int dfs(int n){
    // cout<<n<<endl;
    if(n==0)return 1;
    for(int i=n;i>0;--i){
        if(!pm[i]&&!v[i]){
            v[i]=1;
            // cout<<"get "<<i<<" , left=";
            if(dfs(n-i)){
                ans.push(i);
                return 1;
            }
            v[i]=0;
        }
    }
    return 0;
}

int main(){
    int ts=rit();
    init();
    // for(int i=1;i<=10;++i)cout<<pm[i]<<" ";cout<<endl;
    while(ts--){
        n=rit();
        v.reset();
        if(pm[n]) printf("0\n");
        else{
            if(n==2)printf("2\n");
            else if(n==3)printf("3\n");
            else{
                v[n]=1;
                if(dfs(n)){
                    while(ans.size()){
                        printf("%d",ans.top());
                        ans.pop();
                        if(ans.size())printf(" ");
                    }
                    printf("\n");
                }
                else{
                    printf("%d\n",n);
                }
            }
        }
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
