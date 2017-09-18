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

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define rz(x) resize(x)
#define reset(x,n) (x).clear(),(x).resize(n)
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
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define exp expexpexpexpexp
#define expl explexplexplexpl

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
#define DEBUG 1
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
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm,const priority_queue<TA,TB,TC> &inp){priority_queue<TA,TB,TC> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

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
#endif

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

string its[100005];
vector<string> exp,nexp;
vector<string> expl,nexpl;
set<string> cuexp,cunexp;
vector<string> uxexp,uxnexp;
vector<pair<string,string>> mmvv;
string _itos(int i){
    stack<int> st; string rt;
    while(i)st.push(i%10),i/=10;
    while(st.size())rt+=(char)st.top()+'0',st.pop();
    if(rt.length()==0u)rt+='0';
    return rt;
}
int _stoi(string &s){
    if(s[0]=='0')return -1;
    for(char &c:s)if(c<'0'||c>'9')return -1;
    int rt=0;
    for(char &c:s)rt=rt*10+c-'0';
    return rt;
}
string g6s(){
    srand(time(NULL));
    string s;
    for(int i=0;i<6;++i){
        s+=(char)(rand()%26+'a');
    } return s;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        string fname; int type;
        cin>>fname>>type;
        if(type==1)exp.pb(fname);
        else nexp.pb(fname);
    }
    int e=exp.size();
    for(int i=1;i<=n;++i){
        its[i]=_itos(i);
        if(i<=e)cuexp.insert(its[i]);
        else cunexp.insert(its[i]);
    }
    for(string &expn:exp){
        auto it=cuexp.find(expn);
        if(it!=cuexp.end())cuexp.erase(it);
        else{
            int mean=_stoi(expn);
            if(mean!=-1 && mean>e && mean<=n){
                cunexp.erase(cunexp.find(expn));
                uxnexp.pb(expn);
            }
            else{
                expl.pb(expn);
            }
        }
    }
    for(string &nexpn:nexp){
        auto it=cunexp.find(nexpn);
        if(it!=cunexp.end())cunexp.erase(it);
        else{
            int mean=_stoi(nexpn);
            if(mean!=-1 && mean<=e){
                cuexp.erase(cuexp.find(nexpn));
                uxexp.pb(nexpn);
            }
            else{
                nexpl.pb(nexpn);
            }
        }
    }
    if(cuexp.empty() && cunexp.empty()){
        if(e==0 || e==n || (uxexp.empty() && uxnexp.empty())){
            cout<<0<<endl;
            exit(0);
        }
        string procc=uxexp.back(); uxexp.pop_back();
        string nnwww=g6s();
        PDE2(procc,nnwww);
        mmvv.push_back({procc,nnwww});
        nexpl.pb(nnwww);
        cuexp.insert(procc);
    }
    while(cuexp.size() || cunexp.size()){
    PDE2(cuexp,cunexp);
    PDE2(uxexp,uxnexp);
    PDE2(expl,nexpl);
        if(cuexp.size()){
            string procc;
            if(uxnexp.size()){
                procc=uxnexp.back();
                uxnexp.pop_back();
                cunexp.insert(procc);
            }
            else{
                procc=expl.back();
                expl.pop_back();
            }
            string nnaaa;
            nnaaa=*cuexp.begin(); cuexp.erase(cuexp.begin());
            PDE2(procc,nnaaa);
            mmvv.push_back({procc,nnaaa});
        }
        else{
            string procc;
            if(uxexp.size()){
                procc=uxexp.back();
                uxexp.pop_back();
                cuexp.insert(procc);
            }
            else{
                procc=nexpl.back();
                nexpl.pop_back();
            }
            string nnaaa;
            nnaaa=*cunexp.begin(); cunexp.erase(cunexp.begin());
            mmvv.push_back({procc,nnaaa});
        }
    }
    cout<<mmvv.size()<<endl;
    for(auto i:mmvv){
        cout<<"move "<<i.first<<" "<<i.second<<endl;
    }
}
// 30434298 54:26 RE 4
// 30435949 62:31 RE 4
// 30436983 67:45 AC
