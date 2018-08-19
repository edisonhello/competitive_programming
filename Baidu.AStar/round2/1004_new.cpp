// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define exp expexpexpexp
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; T t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

namespace std{
    template<> struct hash<vector<int>> {
        unsigned long long operator()(const vector<int> a)const{
            unsigned long long rt=0;
            for(int i:a)rt=rt*i+7122;
            return rt;
        }
    };
}

struct my_hash{
    unsigned int operator()(const vector<int> a)const{
        unsigned int rt=0;
        for(int i:a)rt=(rt*i+7122)^7902131;
        return rt;
    }
};

// int nx[6][1111][1111];
vector<int> pos[6][1111];
int n,k,ans,a[6][1111],ptr[6];

unordered_map<vector<int>,int,my_hash> mp;
int dfs2(){
    PDE(ptr[1],ptr[2]);
    auto it=mp.find(vector<int>(ptr+1,ptr+3));
    if(it!=mp.end())return it->second;

    int rt=1;
    int cpy[2]={ptr[1],ptr[2]};
    int rii=-1,riii=-1;
    for(int i=1;i<=2;++i)if(ptr[i]>rii)rii=ptr[i],riii=i;
    set<int> used;
    for(int z=rii+1,i;z<=n;++z){
        i=a[riii][z];
        if(used.find(i)!=used.end())continue;
        used.insert(i);
        auto it1=upper_bound(pos[1][i].begin(),pos[1][i].end(),ptr[1]);
        auto it2=upper_bound(pos[2][i].begin(),pos[2][i].end(),ptr[2]);
        for(auto zit1=it1;zit1!=pos[1][i].end();++zit1){
            ptr[1]=*zit1;
            for(auto zit2=it2;zit2!=pos[2][i].end();++zit2){
                ptr[2]=*zit2;
                rt+=dfs2();
            }
        }
        memcpy(ptr+1,cpy,2<<2);
    }
    return mp[vector<int>(ptr+1,ptr+3)]=rt;
}
int dfs3(){
    auto it=mp.find(vector<int>(ptr+1,ptr+4));
    if(it!=mp.end())return it->second;

    int rt=1;
    int cpy[3]={ptr[1],ptr[2],ptr[3]};
    int rii=-1,riii=-1;
    for(int i=1;i<=3;++i)if(ptr[i]>rii)rii=ptr[i],riii=i;
    set<int> used;
    for(int z=rii+1,i;z<=n;++z){
        i=a[riii][z];
        if(used.find(i)!=used.end())continue;
        used.insert(i);
        auto it1=upper_bound(pos[1][i].begin(),pos[1][i].end(),ptr[1]);
        auto it2=upper_bound(pos[2][i].begin(),pos[2][i].end(),ptr[2]);
        auto it3=upper_bound(pos[3][i].begin(),pos[3][i].end(),ptr[3]);
        for(auto zit1=it1;zit1!=pos[1][i].end();++zit1){
            ptr[1]=*zit1;
            for(auto zit2=it2;zit2!=pos[2][i].end();++zit2){
                ptr[2]=*zit2;
                for(auto zit3=it3;zit3!=pos[3][i].end();++zit3){
                    ptr[3]=*zit3;
                    rt+=dfs3();
                }
            }
        }
        memcpy(ptr+1,cpy,3<<2);
    }
    return mp[vector<int>(ptr+1,ptr+4)]=rt;
}
int dfs4(){
    auto it=mp.find(vector<int>(ptr+1,ptr+5));
    if(it!=mp.end())return it->second;

    int rt=1;
    int cpy[4]={ptr[1],ptr[2],ptr[3],ptr[4]};
    int rii=-1,riii=-1;
    for(int i=1;i<=4;++i)if(ptr[i]>rii)rii=ptr[i],riii=i;
    set<int> used;
    for(int z=rii+1,i;z<=n;++z){
        i=a[riii][z];
        if(used.find(i)!=used.end())continue;
        used.insert(i);
        auto it1=upper_bound(pos[1][i].begin(),pos[1][i].end(),ptr[1]);
        auto it2=upper_bound(pos[2][i].begin(),pos[2][i].end(),ptr[2]);
        auto it3=upper_bound(pos[3][i].begin(),pos[3][i].end(),ptr[3]);
        auto it4=upper_bound(pos[4][i].begin(),pos[4][i].end(),ptr[4]);
        for(auto zit1=it1;zit1!=pos[1][i].end();++zit1){
            ptr[1]=*zit1;
            for(auto zit2=it2;zit2!=pos[2][i].end();++zit2){
                ptr[2]=*zit2;
                for(auto zit3=it3;zit3!=pos[3][i].end();++zit3){
                    ptr[3]=*zit3;
                    for(auto zit4=it4;zit4!=pos[4][i].end();++zit4){
                        ptr[4]=*zit4;
                        rt+=dfs4();
                    }
                }
            }
        }
        memcpy(ptr+1,cpy,4<<2);
    }
    return mp[vector<int>(ptr+1,ptr+5)]=rt;
}
int dfs5(){
    auto it=mp.find(vector<int>(ptr+1,ptr+6));
    if(it!=mp.end())return it->second;
    // PDE(ptr[1],ptr[2],ptr[3],ptr[4],ptr[5]);

    int rt=1;
    int cpy[5]={ptr[1],ptr[2],ptr[3],ptr[4],ptr[5]};
    int rii=-1,riii=-1;
    for(int i=1;i<=5;++i)if(ptr[i]>rii)rii=ptr[i],riii=i;
    set<int> used;
    for(int z=rii+1,i;z<=n;++z){
        i=a[riii][z];
        // PDE(rii,riii,z,i);
        if(used.find(i)!=used.end())continue;
        used.insert(i);
        auto it1=upper_bound(pos[1][i].begin(),pos[1][i].end(),ptr[1]);
        auto it2=upper_bound(pos[2][i].begin(),pos[2][i].end(),ptr[2]);
        auto it3=upper_bound(pos[3][i].begin(),pos[3][i].end(),ptr[3]);
        auto it4=upper_bound(pos[4][i].begin(),pos[4][i].end(),ptr[4]);
        auto it5=upper_bound(pos[5][i].begin(),pos[5][i].end(),ptr[5]);
        for(auto zit1=it1;zit1!=pos[1][i].end();++zit1){
            ptr[1]=*zit1;
            for(auto zit2=it2;zit2!=pos[2][i].end();++zit2){
                ptr[2]=*zit2;
                for(auto zit3=it3;zit3!=pos[3][i].end();++zit3){
                    ptr[3]=*zit3;
                    for(auto zit4=it4;zit4!=pos[4][i].end();++zit4){
                        ptr[4]=*zit4;
                        for(auto zit5=it5;zit5!=pos[5][i].end();++zit5){
                            ptr[5]=*zit5;
                            rt+=dfs5();
                        }
                    }
                }
            }
        }
        memcpy(ptr+1,cpy,5<<2);
    }
    // PDE("end");
    return mp[vector<int>(ptr+1,ptr+6)]=rt;
}

void sol(){
    mp.clear();
    rit(k,n);
    for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)rit(a[i][j]);
    // for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)nx[i][n][j]=n+1;
    // for(int i=1;i<=k;++i)for(int j=n-1;j>=0;--j)for(int k=1;k<=n;++k)nx[i][j][k]=a[i][j+1]==k?j+1:nx[i][j+1][k];
    for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)pos[i][j].clear();
    for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)pos[i][a[i][j]].push_back(j);
    // for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)if(pos[i][j].size())PDE(i,j,pos[i][j]);
    int sum=0;
    for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)sum+=pos[i][j].size();
    // PDE(sum);
    MS(ptr,0);
    if(k==2)ans=dfs2();
    if(k==3)ans=dfs3();
    if(k==4)ans=dfs4();
    if(k==5)ans=dfs5();
    pit(ans-1);
}

int main(){
    int t; rit(t); while(t--){
        sol();
    }
}
