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
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>

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
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas

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
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define endl '\n'
#define getchar gtx
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

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
inline bool rit(T& x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c-'0');
    while(c=getchar(), c>='0' && c<='9')x=x*10+c-'0';
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
void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

struct node{
    node *l,*r;
    int v,sz;
    node():l(NULL),r(NULL),v(0),sz(1){};
    node(int val):l(NULL),r(NULL),v(val),sz(1){};
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
};
void printTree(node *now);
void psz(node *now){
    if(!now)return;
    now->sz=now->lz()+now->rz()+1;
}
void rot(node *&now,int dir){
    if(dir==1){
        node *tmp=now->l;
        now->l=tmp->r;
        tmp->r=now;
        now=tmp;
    }
    else{
        node *tmp=now->r;
        now->r=tmp->l;
        tmp->l=now;
        now=tmp;
    }
}
void pull(node *&now){
    if(!now)return;
    if(now->lz()>now->rz()+1)rot(now,1);
    else if(now->rz()>now->lz()+1)rot(now,2);
    psz(now->l), psz(now->r), psz(now);
}
void insert(node *&now,int v){
    if(!now)now=new node(v);
    else{
        if(now->v>v)insert(now->l,v);
        else insert(now->r,v);
        pull(now);
    }
}
void remove(node *&now){
    if(!now->l && !now->r){
        delete now; now=0; return;
    }
    if(now->rz()>now->lz()){
        rot(now,2);
        remove(now->l);
        pull(now);
    }
    else{
        rot(now,1);
        remove(now->r);
        pull(now);
    }
}
void remove(node *&now,int v){
    if(now->v>v)remove(now->l,v);
    else if(now->v<v)remove(now->r,v);
    else remove(now);
    pull(now);
}
int bigger(node *now,int v){
    if(!now)return 0;
    if(now->v==v)return now->rz();
    if(now->v>v)return bigger(now->l,v)+1+now->rz();
    return bigger(now->r,v);
}

void printTree(node *now){
    if(!now)return;
    if(now->l)cout<<"(",printTree(now->l),cout<<")";
    cout<<now->v;
    if(now->r)cout<<"(",printTree(now->r),cout<<")";
}

int n,a[200009];
node *BIT[200009];
ll ni;

void add(int x,int v){
    while(x<=n){
        insert(BIT[x],v);
        x+=lowbit(x);
    }
}
void mns(int x,int v){
    while(x<=n){
        remove(BIT[x],v);
        x+=lowbit(x);
    }
}
int query(int x,int v){
    int rt=0;
    while(x>0){
        rt+=bigger(BIT[x],v);
        x-=lowbit(x);
    } return rt;
}
// int meow(int x,int v){
//     int leftBig=query(x,v);
//     return leftBig+v-x+leftBig;
// }

int main(){
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i)add(i,i),a[i]=i;
    while(q--){
        int l,r; cin>>l>>r; if(l==r)goto jump; if(l>r)swap(l,r);
        // ni-=query(r,a[r])+query(l,a[l]);
        if(a[l]<a[r]){
            {
                int l_left_big=query(l,a[l]);
                int l_right_small=a[l]-l+l_left_big;
                ni-=l_left_big+l_right_small; mns(l,a[l]);
                int r_left_big=query(r,a[r]);
                int r_right_small=a[r]-r+r_left_big;
                ni-=r_left_big+r_right_small; mns(r,a[r]);
            }
            {
                int l_left_big=query(l,a[r]);
                int l_right_small=a[r]-l+l_left_big-1;
                ni+=l_left_big+l_right_small; add(l,a[r]);
                int r_left_big=query(r,a[l]);
                int r_right_small=a[l]-r+r_left_big;
                ni+=r_left_big+r_right_small; add(r,a[l]);
            }
        }
        else{
            {
                int l_left_big=query(l,a[l]);
                int l_right_small=a[l]-l+l_left_big;
                ni-=l_left_big+l_right_small; mns(l,a[l]);
                int r_left_big=query(r,a[r]);
                int r_right_small=a[r]-r+r_left_big+1;
                ni-=r_left_big+r_right_small; mns(r,a[r]);
            }
            {
                int l_left_big=query(l,a[r]);
                int l_right_small=a[r]-l+l_left_big;
                ni+=l_left_big+l_right_small; add(l,a[r]);
                int r_left_big=query(r,a[l]);
                int r_right_small=a[l]-r+r_left_big;
                ni+=r_left_big+r_right_small; add(r,a[l]);
            }
        }
        swap(a[l],a[r]);
        jump:cout<<ni<<endl;
    }
}
