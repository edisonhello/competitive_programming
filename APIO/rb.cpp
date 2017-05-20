// #include "gd.cpp"
#include<bits/stdc++.h>

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
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x3f,sizeof(x))
#define MSBB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas


#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)

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

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;



int _R,_C;

vector<vector<bool>> tra,v;
void meow(int nr,int nc,int &ar,int &ac,int &br,int &bc);
vector<int> r1,r2,rr;

void init(int R,int C,int sr,int sc,int M,char S[]){
    _R=R, _C=C;
    tra.resize(_R+8);
    for(int i=0;i<_R+8;++i)tra[i].resize(_C+8);
    tra[sr][sc]=1;
    for(int i=0;i<M;++i){
        if(S[i]=='N')--sr;
        else if(S[i]=='S')++sr;
        else if(S[i]=='W')--sc;
        else ++sc;
        tra[sr][sc]=1;
    }
    if(R==2){
        bool fnt=0;
        for(int i=1;i<=C;++i){
            if(fnt==0 && !tra[1][i]){
                fnt=1; r1.push_back(i);
            }
            else if(tra[1][i])fnt=0;
        }
        fnt=0;
        for(int i=1;i<=C;++i){
            if(fnt==0 && !tra[2][i]){
                fnt=1; r2.push_back(i);
            }
            else if(tra[2][i])fnt=0;
        }
        fnt=0;
        for(int i=1;i<=C;++i){
            if(fnt==0 && !(tra[1][i] && tra[2][i])){

                fnt=1; rr.push_back(i);
            }
            else if(tra[1][i] && tra[2][i])fnt=0;
        }

        /*cout<<"r1: "; for(int i:r1)cout<<i<<" ";cout<<endl;
        cout<<"r2: "; for(int i:r2)cout<<i<<" ";cout<<endl;
        cout<<"rr: "; for(int i:rr)cout<<i<<" ";cout<<endl;*/
    }
}

int colour(int ar,int ac,int br,int bc){
    if(_R<=50 && _C<=50){
        v.clear(); v.resize(_R+8);
        for(int i=0;i<_R+8;++i)v[i].resize(_C+8);
        int cnt=0;
        for(int i=ar;i<=br;++i) for(int j=ac;j<=bc;++j){
            if(v[i][j] || tra[i][j])continue;
            // PDE2(i,j);
            meow(i,j,ar,ac,br,bc);
            ++cnt;
        }
        return cnt;
    }
    else{
        if(ar==1 && br==1){
            if(tra[1][ac]){
                auto it1=upper_bound(r1.begin(),r1.end(),ac);
                auto it2=upper_bound(r1.begin(),r1.end(),bc); --it2;
                return it2-it1+1;
            }
            else{
                auto it1=upper_bound(r1.begin(),r1.end(),ac); --it1;
                auto it2=upper_bound(r1.begin(),r1.end(),bc); --it2;
                return it2-it1+1;
            }
        }
        else if(ar==2 && br==2){
            if(tra[2][ac]){
                auto it1=upper_bound(r2.begin(),r2.end(),ac);
                auto it2=upper_bound(r2.begin(),r2.end(),bc); --it2;
                return it2-it1+1;
            }
            else{
                auto it1=upper_bound(r2.begin(),r2.end(),ac); --it1;
                auto it2=upper_bound(r2.begin(),r2.end(),bc); --it2;
                return it2-it1+1;
            }
        }
        else{
            if(tra[1][ac] && tra[2][ac]){
                auto it1=upper_bound(rr.begin(),rr.end(),ac);
                auto it2=upper_bound(rr.begin(),rr.end(),bc); --it2;
                return it2-it1+1;
            }
            else{
                auto it1=upper_bound(rr.begin(),rr.end(),ac); --it1;
                auto it2=upper_bound(rr.begin(),rr.end(),bc); --it2;
                return it2-it1+1;
            }
        }
    }
}



int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void meow(int nr,int nc,int &ar,int &ac,int &br,int &bc){
    /// PDE2(nr,nc);
    v[nr][nc]=1;
    for(int d=0;d<4;++d){
        if(v[nr+dx[d]][nc+dy[d]] || tra[nr+dx[d]][nc+dy[d]])continue;
        if(nr+dx[d]>br || nr+dx[d]<ar || nc+dy[d]>bc || nc+dy[d]<ac)continue;
        meow(nr+dx[d],nc+dy[d],ar,ac,br,bc);
    }
}
