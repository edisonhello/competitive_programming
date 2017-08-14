#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>
#include<tuple>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define reset(x,n) (x).clear(), (x).resize(n)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x3f,sizeof(x))
#define MSBB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG "jizz"
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#define DEBUG 0
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif


#define lowbit(x) ((x)&(-(x)))

inline int gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

inline void pit(int x){printf("%d",x);}
inline void pln(ll x){printf("%I64d",x);}
template<typename ...Args>
inline void pit(int x,Args ...args){printf("%d ",x);pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x);pit(args...);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

vector<vector<int>> a,b,c;

struct Matrix{
    int size,x,y;

    void init(int N,int sx,int sy){
        size=N; x=sx; y=sy;
    }
    Matrix submat(bool gx,bool gy)const{
        const Matrix &a=*this;
        return Matrix::init(size>>1,x+(gx?size>>1:0),y+(gy?size>>1:0));
    }
    Matrix operator+(const Matrix b)const{
        const Matrix &a=*this;
        Matrix c; c.init(size);
        for(int i=0;i<size;++i)for(int j=0;j<size;++j)c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
        return c;
    }
    Matrix operator-(const Matrix b)const{
        const Matrix &a=*this;
        Matrix c; c.init(size);
        for(int i=0;i<size;++i)for(int j=0;j<size;++j)c.mat[i][j]=a.mat[i][j]-b.mat[i][j];
        return c;
    }
    Matrix operator*(const Matrix b)const{
        const Matrix &a=*this;
        if(size==1){
            Matrix c; c.init(1); c.mat[0][0]=a.mat[0][0]*b.mat[0][0]; return c;
        }
        if(size<=2){
            Matrix c; c.init(size);
            for(int i=0;i<size;++i)for(int j=0;j<size;++j)for(int k=0;k<size;++k)c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
            return c;
        }
        Matrix m[8];
        Matrix A11=a.submat(0,0),A12=a.submat(0,1),A21=a.submat(1,0),A22=a.submat(1,1),
               B11=b.submat(0,0),B12=b.submat(0,1),B21=b.submat(1,0),B22=b.submat(1,1);
        m[1]=(A11+A22)*(B11+B22),
        m[2]=(A21+A22)*B11,
        m[3]=A11*(B12-B22),
        m[4]=A22*(B21-B11),
        m[5]=(A11+A12)*B22,
        m[6]=(A21-A11)*(B11+B12),
        m[7]=(A12-A22)*(B21+B22);
        Matrix c; c.init(size);
        for(int i=0;i<(size>>1);++i)for(int j=0;j<(size>>1);++j)c.mat[i][j]=m[1].mat[i][j]+m[4].mat[i][j]-m[5].mat[i][j]+m[7].mat[i][j];
        for(int i=0;i<(size>>1);++i)for(int j=0;j<(size>>1);++j)c.mat[i][j+(size>>1)]=m[3].mat[i][j]+m[5].mat[i][j];
        for(int i=0;i<(size>>1);++i)for(int j=0;j<(size>>1);++j)c.mat[i+(size>>1)][j]=m[2].mat[i][j]+m[4].mat[i][j];
        for(int i=0;i<(size>>1);++i)for(int j=0;j<(size>>1);++j)c.mat[i+(size>>1)][j+(size>>1)]=m[1].mat[i][j]-m[2].mat[i][j]+m[3].mat[i][j]+m[6].mat[i][j];
        return c;
    }
} ma,mb,c;

int main(){
    int n,N; rit(n); N=n;
    while(lowbit(N)!=N)N+=lowbit(N);
    a.resize(N); for(int i=0;i<N;++i)a[i].resize(N);
    b.resize(N); for(int i=0;i<N;++i)b[i].resize(N);
    c.resize(N); for(int i=0;i<N;++i)c[i].resize(N);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)rit(a[i][j]);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)rit(b[i][j]);
    ma.init(N,0,0); mb.init(N,0,0);
    c=a*b;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)printf("%d ",c.mat[i][j]);
        printf("\n");
    }
}
