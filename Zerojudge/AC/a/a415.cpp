// #pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker,"/STACK:36777216")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)

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
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define PDE(...) macro_dispatcher(PDE, __VA_ARGS__)(__VA_ARGS__)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG 1
#else
#define PDE(...) ;
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
// ostream& operator<<(ostream &ostm,const __int128 &val){__int128 cpy=val; stack<int> st; while(cpy)st.push(cpy%10),cpy/=10; while(st.size())ostm<<st.top(),st.pop();return ostm;}

// #define getchar gtx
// #define fread fread_unlocked
inline char gtx(){
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

/* template<class T>void writeInt(T x, char endc = '\n'){
    static char _buf[4096],*ptr=_buf,*end=_buf+4096;
    if(x<0)*ptr++='-',x=-x; if(x==0)*ptr++='0';
    char* s=ptr;
    while(x){T t=x/10; char c=x-10*t+'0'; *ptr++=c; x=t;}
    char* f=ptr-1; while(s<f)swap(*s,*f), ++s,--f;
    if(ptr>end)cout.write(_buf,ptr-_buf), ptr=_buf;
    *ptr++=endc;
} */

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

struct station{
    int timetonext,timetoprev;
    pair<int,int> interinfo;
    station(){
        timetonext=0;
        timetoprev=0;
        interinfo={0,0};
    }
};
struct train{
    int arrive,line,pos;
    bool operator<(const train &b)const{return this->arrive<b.arrive;}
    bool operator>(const train &b)const{return this->arrive>b.arrive;}
};
ostream& operator<<(ostream &o,const train &a){o<<"("<<a.arrive<<", ("<<a.line<<", "<<a.pos<<"))"; return o;}
vector<station> lineinfo[102];
int d[111][22],v[111][22];
int solve(int line1,int pos1,int line2,int pos2){
    memset(d,0x3f,sizeof(d)); d[line1][pos1]=0;
    memset(v,0,sizeof(v));
    priority_queue<train,vector<train>,greater<train>> pq;
    pq.push({0,line1,pos1});
    while(pq.size()){
        while(pq.size() && v[pq.top().line][pq.top().pos])pq.pop();
        if(pq.empty())break;
        v[pq.top().line][pq.top().pos]=1;
        if(v[line2][pos2])break;
        if(pq.top().pos+1<lineinfo[pq.top().line].size() && !v[pq.top().line][pq.top().pos+1] && d[pq.top().line][pq.top().pos+1]>pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetonext){
            d[pq.top().line][pq.top().pos+1]=pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetonext;
            pq.push({d[pq.top().line][pq.top().pos+1],pq.top().line,pq.top().pos+1});
        }
        if(pq.top().pos>0 && !v[pq.top().line][pq.top().pos-1] && d[pq.top().line][pq.top().pos-1]>pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetoprev){
            d[pq.top().line][pq.top().pos-1]=pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetoprev;
            pq.push({d[pq.top().line][pq.top().pos-1],pq.top().line,pq.top().pos-1});
        }
        if(lineinfo[pq.top().line][pq.top().pos].interinfo.X){
            int line=lineinfo[pq.top().line][pq.top().pos].interinfo.X,pos=lineinfo[pq.top().line][pq.top().pos].interinfo.Y;
            if(!v[line][pos]){
                v[line][pos]=1; d[line][pos]=pq.top().arrive;
                if(pos+1<lineinfo[line].size() && !v[line][pos+1] && d[line][pos+1]>pq.top().arrive+lineinfo[line][pos].timetonext){
                    d[line][pos+1]=pq.top().arrive+lineinfo[line][pos].timetonext;
                    pq.push({d[line][pos+1],line,pos+1});
                }
                if(pos>0 && !v[line][pos-1] && d[line][pos-1]>pq.top().arrive+lineinfo[line][pos].timetoprev){
                    d[line][pos-1]=pq.top().arrive+lineinfo[line][pos].timetoprev;
                    pq.push({d[line][pos-1],line,pos-1});
                }
            }
        }
    }
    return d[line2][pos2];
}
bool same(int i,int p,int j,int q){
    if(i==j && p==q)return 1;
    return lineinfo[i][p].interinfo.X==j && lineinfo[i][p].interinfo.Y==q;
}
int main(){
    int lines,inter; cin>>lines>>inter;
    while(lines--){
        int linenumber,stations; cin>>linenumber>>stations;
        lineinfo[linenumber].resize(stations);
        for(int i=0;i<stations;++i){
            int drivetime; cin>>drivetime; ++drivetime;
            if(i)lineinfo[linenumber][i-1].timetonext=drivetime,
            lineinfo[linenumber][i].timetoprev=drivetime;
        }
        
    }
    while(inter--){
        int i,p,j,q; cin>>i>>p>>j>>q; --p, --q;
        lineinfo[i][p].interinfo={j,q};
        lineinfo[j][q].interinfo={i,p};
    }
    for(int _=0;_<5;++_){
        int H,M,i,p,j,q; cin>>H>>M>>i>>p>>j>>q; --p, --q, H-=6, M+=H*60;
        cout<<(same(i,p,j,q)?0:solve(i,p,j,q))<<endl;
    }
}

// Wrong Understanding of problem: waiting time should be add into answer
/* 
struct station{
    int timetonext,timetoprev,timeneedfromhead,timeneedfromtail;
    pair<int,int> interinfo;
    station(){
        timetonext=0;
        timetoprev=0;
        timeneedfromhead=0;
        timeneedfromtail=0;
        interinfo={0,0};
    }
};
struct train{
    int arrive,direction,line,pos;
    bool operator<(const train &b)const{return this->arrive<b.arrive;}
    bool operator>(const train &b)const{return this->arrive>b.arrive;}
};
ostream& operator<<(ostream &o,const train &a){o<<"("<<a.arrive<<", "<<a.direction<<", ("<<a.line<<", "<<a.pos<<"))"; return o;}
vector<station> lineinfo[102];
int d[111][22],v[111][22];
int solve(int T,int line1,int pos1,int line2,int pos2){
    memset(d,0x3f,sizeof(d)); d[line1][pos1]=T;
    memset(v,0,sizeof(v));
    priority_queue<train,vector<train>,greater<train>> pq;
    if(pos1+1<lineinfo[line1].size()){
        ++pos1;
        int trainarrivefromhead=max(int(floor((((double)(T-lineinfo[line1][pos1-1].timeneedfromhead-1))/5)))+1,0)*5+lineinfo[line1][pos1-1].timetonext+1;
        d[line1][pos1]=min(d[line1][pos1],trainarrivefromhead);
        pq.push({trainarrivefromhead,1,line1,pos1});
        --pos1;
    }
    if(pos1>0){
        --pos1;
        int trainarrivefromtail=max(int(floor((((double)(T-lineinfo[line1][pos1+1].timeneedfromtail-1))/5)))+1,0)*5+lineinfo[line1][pos1+1].timetoprev+1;
        PDE(int(floor((((double)(T-lineinfo[line1][pos1].timeneedfromtail-1))/5)))+1,trainarrivefromtail);
        d[line1][pos1]=min(d[line1][pos1],trainarrivefromtail);
        pq.push({trainarrivefromtail,-1,line1,pos1});
        ++pos1;
    }
    if(lineinfo[line1][pos1].interinfo.X){
        {int __tmp1=lineinfo[line1][pos1].interinfo.X,__tmp2=lineinfo[line1][pos1].interinfo.Y;line1=__tmp1,pos1=__tmp2;}
        d[line1][pos1]=T;
        if(pos1+1<lineinfo[line1].size()){
            ++pos1;
            int trainarrivefromhead=max(int(floor((((double)(T-lineinfo[line1][pos1-1].timeneedfromhead-1))/5)))+1,0)*5+lineinfo[line1][pos1-1].timetonext+1;
            d[line1][pos1]=min(d[line1][pos1],trainarrivefromhead);
            pq.push({trainarrivefromhead,1,line1,pos1});
            --pos1;
        }
        if(pos1>0){
            --pos1;
            int trainarrivefromtail=max(int(floor((((double)(T-lineinfo[line1][pos1+1].timeneedfromtail-1))/5)))+1,0)*5+lineinfo[line1][pos1+1].timetoprev+1;
            d[line1][pos1]=min(d[line1][pos1],trainarrivefromtail);
            pq.push({trainarrivefromtail,-1,line1,pos1});
            ++pos1;
        }
    }
    while(pq.size()){
        PDE("gogo",pq.top().arrive,pq.top().direction,pq.top().line,pq.top().pos);
        while(pq.size() && v[pq.top().line][pq.top().pos])pq.pop();
        PDE("gogo",pq.top().arrive,pq.top().direction,pq.top().line,pq.top().pos);
        if(pq.empty())break;
        PDE("gogo",pq.top().arrive,pq.top().direction,pq.top().line,pq.top().pos);
        v[pq.top().line][pq.top().pos]=1;
        if(v[line2][pos2])break;
        PDE("gogo",pq.top().arrive,pq.top().direction,pq.top().line,pq.top().pos);
        if(pq.top().direction==1 && pq.top().pos+1<lineinfo[pq.top().line].size() && !v[pq.top().line][pq.top().pos+1] && d[pq.top().line][pq.top().pos+1]>pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetonext+1){
            d[pq.top().line][pq.top().pos+1]=pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetonext+1;
            pq.push({d[pq.top().line][pq.top().pos+1],1,pq.top().line,pq.top().pos+1});
        }
        if(pq.top().direction==-1 && pq.top().pos>0 && !v[pq.top().line][pq.top().pos-1] && d[pq.top().line][pq.top().pos-1]>pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetoprev+1){
            d[pq.top().line][pq.top().pos-1]=pq.top().arrive+lineinfo[pq.top().line][pq.top().pos].timetoprev+1;
            pq.push({d[pq.top().line][pq.top().pos-1],-1,pq.top().line,pq.top().pos-1});
            PDE(pq);
        }
        if(lineinfo[pq.top().line][pq.top().pos].interinfo.X){
            int line=lineinfo[pq.top().line][pq.top().pos].interinfo.X,pos=lineinfo[pq.top().line][pq.top().pos].interinfo.Y,T=pq.top().arrive;
            d[line][pos]=T;
            v[line][pos]=1;
            if(pos+1<lineinfo[line].size()){
                ++pos;
                int trainarrivefromhead=max(int(floor((((double)(T-lineinfo[line1][pos1].timeneedfromhead-1))/5)))+1,0)*5;
                d[line][pos]=min(d[line][pos],trainarrivefromhead);
                pq.push({trainarrivefromhead,1,pq.top().line,pq.top().pos});
                --pos;
            }
            if(pos>0){
                --pos;
                int trainarrivefromtail=max(int(floor((((double)(T-lineinfo[line1][pos1].timeneedfromtail-1))/5)))+1,0)*5;
                d[line][pos]=min(d[line][pos],trainarrivefromtail);
                pq.push({trainarrivefromtail,-1,pq.top().line,pq.top().pos});
                ++pos;
            }
        }
    }
    return d[line2][pos2];
}
bool same(int i,int p,int j,int q){
    if(i==j && p==q)return 1;
    return lineinfo[i][p].interinfo.X==j && lineinfo[i][p].interinfo.Y==q;
}
int main(){
    int lines,inter; cin>>lines>>inter;
    while(lines--){
        int linenumber,stations; cin>>linenumber>>stations;
        lineinfo[linenumber].resize(stations);
        for(int i=0;i<stations;++i){
            int drivetime; cin>>drivetime;
            if(i)lineinfo[linenumber][i-1].timetonext=drivetime,
                 lineinfo[linenumber][i].timeneedfromhead=lineinfo[linenumber][i-1].timeneedfromhead+1+lineinfo[linenumber][i-1].timetonext;
            lineinfo[linenumber][i].timetoprev=drivetime;
        }
        for(int i=stations-2;i>=0;--i)lineinfo[linenumber][i].timeneedfromtail=lineinfo[linenumber][i+1].timeneedfromtail+1+lineinfo[linenumber][i+1].timetoprev;
        
    }
    while(inter--){
        int i,p,j,q; cin>>i>>p>>j>>q; --p, --q;
        lineinfo[i][p].interinfo={j,q};
        lineinfo[j][q].interinfo={i,p};
    }
    for(int _=0;_<5;++_){
        int H,M,i,p,j,q; cin>>H>>M>>i>>p>>j>>q; --p, --q, H-=6, M+=H*60;
        cout<<(same(i,p,j,q)?0:solve(M,i,p,j,q))<<endl;
    }
}
*/
