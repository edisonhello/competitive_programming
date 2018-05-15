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
} *trie[35];

bool exi[100005];

int main(){
    CPPinput;
    int q; cin>>q; while(q--){
        int t; cin>>t;
        if(t==1){
            int u; cin>>u;
            exi[u]=1;
        }
        else{
            int x,k,s; cin>>x>>k>>s;
            PDE(x,k,s);
            if(__gcd(x,k)%k){
                cout<<-1<<'\n';
                continue;
            }
            PDE(x,k,s);
            int step=(s-x)/k;
            int vmax=step*k;
            int start=k;
            int mx0=-1,mx1=-1,mx2=-1,mx3=-1,mx4=-1,mx5=-1,mx6=-1,mx7=-1;
            int bg=step/8,le=step-bg*8;
            bool *ptr=exi+k;
            PDE(bg,le,ptr-exi);
            switch(le){
                case 7: mx7=max(mx7,(*ptr)*(start^x)),ptr+=k,start+=k;
                case 6: mx6=max(mx6,(*ptr)*(start^x)),ptr+=k,start+=k;
                case 5: mx5=max(mx5,(*ptr)*(start^x)),ptr+=k,start+=k;
                case 4: mx4=max(mx4,(*ptr)*(start^x)),ptr+=k,start+=k;
                case 3: mx3=max(mx3,(*ptr)*(start^x)),ptr+=k,start+=k;
                case 2: mx2=max(mx2,(*ptr)*(start^x)),ptr+=k,start+=k;
                PDE(ptr-exi,start,mx2);
                case 1: mx1=max(mx1,(*ptr)*(start^x)),ptr+=k,start+=k;
                PDE(ptr-exi,start,mx1);
            }
            int vl0=start,vl1=start+k,vl2=start+k*2,vl3=start+k*3;
            int vl4=start*4,vl5=start+k*5,vl6=start+k*6,vl7=start+k*7;
    #define zzz(c) mx##c=max(mx##c,(*ptr)*((vl##c)^x)),ptr+=k,vl##c+=k<<3
            while(bg--){
                zzz(0);
                zzz(1);
                zzz(2);
                zzz(3);
                zzz(4);
                zzz(5);
                zzz(6);
                zzz(7);
            }
    #define ggg(q,w) mx##q=max(mx##q,mx##w)
            ggg(0,1);
            ggg(2,3);
            ggg(4,5);
            ggg(6,7);
            ggg(0,2);
            ggg(4,6);
            ggg(0,4);
            if(mx0==-1)cout<<-1<<endl;
            else cout<<(mx0^x)<<endl;
        }
    }
}
