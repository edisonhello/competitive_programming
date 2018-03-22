// #pragma GCC optimize("no-stack-protector")
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

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define vll vector<ll>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)

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
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

template<typename T,int I>struct raw{
    vector<T> d;
    raw(){d.resize(I);}
    T& operator[](int id){return d[id];}
    const T& operator[](int id)const{return d[id];}
};
template<typename T,int I>struct mat{
    vector<raw<T,I>> r;
    mat(int x=0){
        r.resize(I);
        if(x)setI();
        else setO();
    }
    raw<T,I>& operator[](int id){return r[id];}
    const raw<T,I>& operator[](int id)const{return r[id];}
    void setI(){for(int i=0;i<I;++i)for(int j=0;j<I;++j)r[i][j]=(i==j);}
    void setO(){for(int i=0;i<I;++i)for(int j=0;j<I;++j)r[i][j]=0;}
};
template<typename T,int I>mat<T,I> operator*(const mat<T,I> &a,const mat<T,I> &b){
    mat<T,I> rt;
    for(int i=0;i<I;++i)for(int j=0;j<I;++j)for(int k=0;k<I;++k)rt[i][j]=(rt[i][j]+a[i][k]*b[k][j])%mod;
    return rt;
}
template<typename T,int I>mat<T,I> operator+(const mat<T,I> &a,const mat<T,I> &b){
    mat<T,I> rt;
    for(int i=0;i<I;++i)for(int j=0;j<I;++j)rt[i][j]=(a[i][j]+b[i][j])%mod;
    return rt;
}
template<typename T,int I>mat<T,I> pw(mat<T,I> b,long long n,mat<T,I> a=mat<T,I>(1)){
    while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    } return a;
}
template<typename T,int I>ostream& operator<<(ostream &ostm,const raw<T,I> &r){ostm<<"["; for(int i=0;i<I;++i)ostm<<r[i]<<(i==I-1?"]":", "); return ostm;}
template<typename T,int I>ostream& operator<<(ostream &ostm,const mat<T,I> &m){ostm<<"\n["; for(int i=0;i<I;++i)ostm<<m[i]<<(i==I-1?"]\n":",\n "); return ostm;}

#define int long long

map<ll,map<int,int>> block;

int32_t main(){
    CPPinput;
    int n;
    long long m; cin>>n>>m;
    for(int i=0;i<n;++i){
       int a,l,r; cin>>a>>l>>r;
       if(l==1)++l;
       block[l][a-1]+=1;
       block[r+1][a-1]-=1;
    }
    ll prv=1;
    mat<ll,3> fullt,now;
    now[0][1]=1;
    fullt[0][0]=fullt[0][1]=fullt[1][0]=fullt[1][1]=fullt[1][2]=fullt[2][1]=fullt[2][2]=1;
    int status[3]={0,0,0};
    for(auto i:block){
        mat<ll,3> trans;
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if(abs(i-j)<=1 && status[j]==0)trans[i][j]=1;
            }
        }
        ll nowpos=i.first;
        PDE(nowpos,prv);
        trans=pw(trans,nowpos-prv-1);
        now=now*trans;
        prv=nowpos-1;
        for(auto ii:i.second)status[ii.first]+=ii.second;
    }
    PDE(m,prv);
    now=now*pw(fullt,m-prv);
    cout<<now[0][1]<<endl;
}
