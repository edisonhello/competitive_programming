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

struct node{
    node *ch[2];
    int sz;
} *trie[100005];

void insert(node *&now,int v,int ptr){
    if(!now)now=new node();
    if(ptr<0)return;
    ++now->sz;
    insert(now->ch[!!(v&(1<<ptr))],v,ptr-1);
}

map<int,int> fac;
void dfsprime(map<int,int>::iterator it,int now,int u){
    if(it==fac.end())insert(trie[now],u,20);
    else for(int i=0,b=1;i<=it->second;++i,b*=it->first){
        dfsprime(next(it),now*b,u);
    }
}
int query(node *now,int x,int s,int ptr,int nx,int bound=1){
    PDE(x,s,ptr,nx,bound);
    if(!now)return -1;
    if(nx+x>s)return -1;
    if(ptr<0)return nx;
    if(!bound){
        if(now->ch[!(x&(1<<ptr))])return query(now->ch[!(x&(1<<ptr))],x,s,ptr-1,nx|(int(!(x&(1<<ptr)))<<ptr),0);
        else return query(now->ch[!!(x&(1<<ptr))],x,s,ptr-1,nx|(int(!!(x&(1<<ptr))))<<ptr,0);
    }
    else{
        int mx=-1;
        if(((nx|(1<<ptr))+x)-1<=s){
            mx=query(now->ch[0],x,s,ptr-1,nx,0);
            int r2=query(now->ch[1],x,s,ptr-1,nx|(1<<ptr));
            if((mx^x)>(r2^x))return mx;
            else return r2;
        }
        return query(now->ch[0],x,s,ptr-1,nx);
    }
}

int main(){
    CPPinput;
    int q; cin>>q; while(q--){
        int t; cin>>t;
        if(t==1){
            int u,uu; cin>>u; uu=u;
            fac.clear();
            for(int i=2;i*i<=u;++i){
                while(u%i==0){
                    u/=i;
                    ++fac[i];
                }
            }
            if(u>1)++fac[u];
            dfsprime(fac.begin(),1,uu);
        }
        else{
            int x,k,s; cin>>x>>k>>s;
            PDE(x,k,s);
            if(x%k || x>s){
                cout<<-1<<'\n';
                continue;
            }
            int mx=query(trie[k],x,s,20,0);
            cout<<mx<<endl;
        }
    }
}
