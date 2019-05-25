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

string mp[111];

int main(){
    CPPinput;
    int ts,ks=0; cin>>ts; while(ts--){
        cout<<"Case #"<<(++ks)<<": ";
        int n,m,nn,mm; cin>>n>>m>>nn>>mm;
        int tot=0;
        for(int i=1;i<=n;++i){
            cin>>mp[i];
            mp[i]='.'+mp[i];
            for(char c:mp[i])if(c=='@')++tot;
        }
        if(tot%((nn+1)*(mm+1))){cout<<"IMPOSSIBLE"<<endl; continue;}
        bitset<111> spt;
        int rcnt[111]={0};
        for(int j=1;j<=m;++j){
            for(int i=1;i<=n;++i){
                if(mp[i][j]=='@')++rcnt[j];
            }
        }
        int rexp=tot/(mm+1);
        bool possible=1;
        for(int i=1,j;i<=m;i=j){
            int now=rcnt[i];
            for(j=i+1;j<=m;++j){
                if(now+rcnt[j]>rexp)break;
                now+=rcnt[j];
            }
            if(now!=rexp){possible=0; break;}
            spt[i]=1;
            PDE("spt:",i);
        }
        PDE(rexp,possible);
        if(!possible){cout<<"IMPOSSIBLE"<<endl; continue;}
        int pcnt[111];
        int pexp=tot/((nn+1)*(mm+1));
        PDE(pexp);
        for(int i=1,j;i<=n;i=j){
            MS(pcnt,0);
            for(int z=1,np=0;z<=m;++z){
                if(spt[z])++np;
                if(mp[i][z]=='@')++pcnt[np];
                PDE(mp[i][z],np);
            }
            for(j=i+1;j<=n;++j){
                int allok=1;
                for(int np=1;np<=mm+1;++np){
                    if(pcnt[np]==pexp);
                    else if(pcnt[np]<pexp)allok=0;
                    else {allok=-1; break;}
                }
                PDE(allok);
                if(allok==-1){possible=0; break;}
                if(allok==1)break;
                for(int z=1,np=0;z<=m;++z){
                    if(spt[z])++np;
                    if(mp[j][z]=='@'){
                        ++pcnt[np];
                        if(pcnt[np]>pexp)possible=0;
                    }
                }
            }
            if(!possible)break;
        }
        if(!possible){cout<<"IMPOSSIBLE"<<endl; continue;}
        cout<<"POSSIBLE"<<endl;
    }
}
