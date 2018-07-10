// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
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
#include<functional>
#include<complex>
#include<climits>

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

int n,djs[20][40005];

int F(int i,int x){ return djs[i][x]==x?x:djs[i][x]=F(i,djs[i][x]); }
void U(int i,int x,int y){ djs[i][F(i,x)]=F(i,y); }
bool C(int i,int x,int y){ return F(i,x)==F(i,y); }

vector<int> v;
int dp[1<<14];

int go(int x){
    if(!x)return 0;
    if(dp[x]!=-1)return dp[x];
    int fi=-1,oxx=x;
    for(int i=0;;++i)if(x&(1<<i)){ fi=i; x^=1<<i; break; }
    for(int i=fi+1;i<int(v.size());++i){
        if(!(x&(1<<i)))continue;
        if(C(0,v[fi],v[i]) || C(0,v[fi],v[i]+n)){
            int rt=go(x^(1<<i));
            if(rt!=-1){
                for(int z=0;z<20;++z){
                    if(C(z,v[fi],v[i]));
                    else if(C(z,v[fi],v[i]+n))rt^=(1<<z);
                    else while(7122);
                }
                return dp[oxx]=rt;
            }
        }
    }
    return -1;
}

int main(){
    CPPinput;
    int q,ks=0; while(cin>>n>>q){
        if(n==0 && q==0)break;
        ++ks; cout<<"Case "<<ks<<":\n";
        for(int z=0;z<20;++z)for(int i=0;i<=n*2;++i)djs[z][i]=i;
        bool skip=0;
        int fc=0;
        while(q--){
            char c; cin>>c;
            string s; getline(cin,s); SS ss(s);
            if(skip)continue;
            if(c=='I'){
                ++fc;
                vector<int> tmp;
                { int t; while(ss>>t)tmp.pb(t); }
                if(tmp.size()==2u){
                    int p=tmp[0]+1,v=tmp[1];
                    bool ok=1;
                    for(int i=0;i<20;++i){
                        if(v&(1<<i)){
                            if(C(i,p,0)){ ok=0; break; }
                            else U(i,p+n,0);
                        }
                        else{
                            if(C(i,p+n,0)){ ok=0; break; }
                            else U(i,p,0);
                        }
                    }
                    if(!ok){
                        cout<<"The first "<<fc<<" facts are conflicting."<<endl;
                        skip=1;
                    }
                }
                else{
                    int p=tmp[0]+1,q=tmp[1]+1,v=tmp[2];
                    bool ok=1;
                    for(int i=0;i<20;++i){
                        if(v&(1<<i)){
                            if(C(i,p,q) || C(i,p+n,q+n)){ ok=0; break; }
                            else U(i,p,q+n),U(i,p+n,q);
                        }
                        else{
                            if(C(i,p,q+n) || C(i,p+n,q)){ ok=0; break; }
                            else U(i,p,q),U(i,p+n,q+n);
                        }
                    }
                    if(!ok){
                        cout<<"The first "<<fc<<" facts are conflicting."<<endl;
                        skip=1;
                    }
                }
            }
            else{
                int k; ss>>k;
                int val=0;
                v.clear();
                while(ss>>k){
                    ++k;
                    if(C(0,k,0) || C(0,k+n,0)){
                        for(int i=0;i<20;++i){
                            if(C(i,k,0));
                            else if(C(i,k+n,0))val^=(1<<i);
                            else while(7122);
                        }
                    }
                    else v.pb(k);
                }
                if(v.size()&1){ cout<<"I don't know.\n"; }
                else{
                    memset(dp,0xff,sizeof(dp));
                    int rt=go((1<<v.size())-1);
                    if(rt!=-1)cout<<(val^rt)<<'\n';
                    else cout<<"I don't know.\n";
                }
            }
        }
        cout<<endl;
    }
}
