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
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
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
#endif

#define lowbit(x) ((x)&(-(x)))

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

struct bus{
    int u,v,s,t;
    bus(int u=0,int v=0,int s=0,int t=0):u(u),v(v),s(s),t(t){};
};
ostream& operator<<(ostream &ostm,const bus &inp){ostm<<"[ "<<inp.u<<" -> "<<inp.v<<" : "<<inp.s<<", "<<inp.t<<" ]";return ostm;}
bool operator<(const bus &a,const bus &b){return a.t<b.t;}
bool operator>(const bus &a,const bus &b){return a.t>b.t;}
priority_queue<bus,vector<bus>,less<bus> > pq;

struct timeseq{
    int id,arr,dep;
    timeseq(int id=0,int dep=0,int arr=0):id(id),dep(dep),arr(arr){};
};
ostream& operator<<(ostream &ostm,const timeseq &inp){ostm<<"[ id: "<<inp.id<<", dep: "<<inp.dep<<", arr: "<<inp.arr<<" ]";return ostm;}
bool cmp_by_arr(const timeseq &a,const timeseq &b){return a.arr<b.arr;}
bool reverse_cmp_by_arr(const timeseq &a,const timeseq &b){return a.arr>b.arr;}
bool cmp_by_dep(const timeseq &a,const timeseq &b){return a.dep<b.dep;}
vector<timeseq> ans;

struct info{
    int nt,id;
    info(int nt=0,int id=0):nt(nt),id(id){};
};
ostream& operator<<(ostream &ostm,const info &inp){ostm<<"[ id: "<<inp.id<<", nt: "<<inp.nt<<" ]";return ostm;}
bool operator<(const info &a,const info &b){return a.nt==b.nt?a.id<b.id:a.nt<b.nt;}
set<info> stat[100009];
map<int,int> idgo[100009];

int totid=0;

int main(){
    int n,m; scanf("%d%d",&n,&m);
    while(m--){
        int s,t,x,y; scanf("%d%d%d%d",&s,&t,&x,&y);
        pq.push(bus(s,t,x,y));
    }
    while(pq.size()){
        bus nb=pq.top(); pq.pop();
        PDE1(nb);
        if(nb.v==1 || nb.u==n)continue;
        if(nb.v==n){
            stat[nb.v].insert(info(nb.t,totid));
            ans.push_back(timeseq(totid,0,nb.t));
            ++totid;
        }
        for(set<info>::iterator it=stat[nb.v].begin();it!=stat[nb.v].end();++it){
            if(it->nt>=nb.t){
                map<int,int>::iterator iit=idgo[nb.u].find(it->id);
                if(iit==idgo[nb.u].end())stat[nb.u].insert(info(nb.s,it->id)),idgo[nb.u][it->id]=nb.s;
                else{
                    if(iit->second<nb.s){
                        stat[nb.u].erase(stat[nb.u].find(info(iit->second,it->id)));
                        iit->second=nb.s; stat[nb.u].insert(info(iit->second,it->id));
                    }
                }
            }
        }
        PDE2(stat[nb.u],stat[nb.v]);
    }
    for(set<info>::iterator it=stat[1].begin();it!=stat[1].end();++it)ans[it->id].dep=max(ans[it->id].dep,it->nt);
    sort(ans.begin(),ans.end(),cmp_by_arr);
    for(int i=1;i<ans.size();++i)if(ans[i].dep<ans[i-1].dep)ans[i].dep=ans[i-1].dep;
    PDE1(ans);
    int q; scanf("%d",&q); while(q--){
        int arrt; scanf("%d",&arrt);
        int L=0,R=ans.size()-1,A=ans.size();
        while(R>=L){
            int M=((L+R)>>1);
            if(ans[M].arr>arrt)R=M-1;
            else A=M,L=M+1;
        }
        if(A==(int)ans.size())printf("-1\n");
        else printf("%d\n",ans[A].dep);
        // PDE1(*lower_bound(ans.rbegin(),ans.rend(),timeseq(0,0,arrt),reverse_cmp_by_arr))
        // vector<timeseq>::reverse_iterator it=lower_bound(ans.rbegin(),ans.rend(),timeseq(0,0,arrt),reverse_cmp_by_arr);
        // cout<<(it==ans.rend()?-1:it->dep)<<endl;
    }
}
