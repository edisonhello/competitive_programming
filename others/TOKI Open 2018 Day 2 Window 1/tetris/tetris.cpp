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

#include "tetris.h"

struct result{
    int v,hh;
    bitset<450> zz;
};

namespace std{
    template<> struct hash<pair<int,bitset<450>>> {
        long long operator()(const pair<int,bitset<450>> &p) const {
            return hash<int>{}(p.first)*47017 + hash<bitset<450>>{}(p.second);
        }
    };
}

unordered_map<pair<int,bitset<450>>,result> meow[205];
vint realgo(int n,string s){
    meow[0][make_pair(0,bitset<450>())]=result{0,0,bitset<450>()};
    s="."+s;
    for(int i=1,h,top1,top2;i<=n;++i){
        char c=s[i];
        int HH=450;
        for(auto &p:meow[i-1]){
            h=p.first.first;
            bitset<450> z=p.first.second;
            bitset<450> zz=z;
            PDE(i);
#define case(x) if(c==(x))
#define asgn(y,v) meow[i][make_pair(y,zz)]=result{v,h,z}, HH=min(HH,y);
#define ih if(h-2<=HH)
            case('O'){
                asgn(h,0);
            }
            top1=(z>>(h-1)).to_ulong();
            top2=(z>>(h-2)).to_ulong();
            case('T'){
                if(!h){
                    asgn(2,1);
                    zz[0]=1; zz[1]=1;
                    asgn(2,3);
                    zz[0]=0; zz[1]=0;
                }
                else if(top1==0){
                    ih asgn(h+2,1);
                    zz.flip(h-1);
                    asgn(h,3);
                    zz.flip(h-1);
                }
                else{
                    zz.flip(h-1);
                    asgn(h,1);
                    zz.flip(h-1); zz.flip(h); zz.flip(h+1); 
                    ih asgn(h+2,3);
                    zz.flip(h); zz.flip(h+1);
                }
            }
            case('J'){
                if(!h){
                    asgn(2,1);
                    zz[0]=1; zz[1]=1;
                    asgn(2,3);
                    zz[0]=0; zz[1]=0;
                }
                else if(top2==0){
                    ih asgn(h+2,1);
                    zz.flip(h); zz.flip(h+1);
                    ih asgn(h+2,3);
                    zz.flip(h); zz.flip(h+1);
                }
                else if(top2==1){
                    ih asgn(h+2,1);
                    zz.flip(h); zz.flip(h+1);
                    ih asgn(h+2,3);
                    zz.flip(h); zz.flip(h+1);
                }
                else if(top2==2){
                    zz.flip(h-1);
                    asgn(h,1);
                    zz.flip(h-1); zz.flip(h); zz.flip(h+1);
                    ih asgn(h+2,3);
                    zz.flip(h); zz.flip(h+1);
                }
                else{
                    zz.flip(h-1); zz.flip(h-2);
                    asgn(h-2,1);
                    zz.flip(h-1); zz.flip(h-2); zz.flip(h); zz.flip(h+1);
                    ih asgn(h+2,3);
                    zz.flip(h); zz.flip(h+1);
                }
            }
            case('L'){
                if(!h){
                    asgn(2,1);
                    zz[0]=1; zz[1]=1;
                    asgn(2,3);
                    zz[0]=0; zz[1]=0;
                }
                else if(top2==0){
                    ih asgn(h+2,1);
                    asgn(h-2,3);
                }
                else if(top2==1){
                    ih asgn(h+2,1);
                    zz.flip(h-1);
                    asgn(h,3);
                    zz.flip(h-1);
                }
                else if(top2==2){
                    ih asgn(h+2,1);
                    zz.flip(h); zz.flip(h+1);
                    ih asgn(h+2,3);
                    zz.flip(h); zz.flip(h+1);
                }
                else{
                    ih asgn(h+2,1);
                    zz.flip(h); zz.flip(h+1);
                    ih asgn(h+2,3);
                    zz.flip(h); zz.flip(h+1);
                }
            }
            case('S'){
                if(!h){
                    zz.flip(0);
                    asgn(2,1);
                    zz.flip(0);
                }
                else if(top1==0){
                    asgn(h,1);
                }
                else{
                    zz.flip(h);
                    ih asgn(h+2,1);
                    zz.flip(h);
                }
            }
            case('Z'){
                if(!h){
                    zz.flip(1);
                    asgn(2,1);
                    zz.flip(1);
                }
                else if(top1==0){
                    zz.flip(h);
                    ih asgn(h+2,1);
                    zz.flip(h);
                }
                else{
                    asgn(h,1);
                }
            }
#undef case
#undef ih
#undef asgn
        }
    }
    auto it=meow[n].find(make_pair(0,bitset<450>()));
    if(it==meow[n].end()){
        auto c=clock();
        while((double)(clock()-c)/CLOCKS_PER_SEC<0.4);
        return vint();
    }
    stack<int> anz;
    bitset<450> nowz;
    int ny=0,nx=n;
    while(nx){
        auto &dp=meow[nx][make_pair(ny,nowz)];
        anz.push(dp.v);
        // PDE(nx,ny,nz);
        tie(nx,ny,nowz)=make_tuple(nx-1,dp.hh,dp.zz);
    }
    vint ans;
    while(anz.size()){
        ans.pb(anz.top());
        anz.pop();
    }
    return ans;
}

vint solve18(int n,string s){
    for(int i=0;i<(1<<n);++i){
        vint rt,state;
        for(int j=0;j<n;++j){
            int o=(!!(i&(1<<j)))*2+1;
            rt.pb(o);
            if(s[j]=='T'){
                if(o==1){
                    if(state.size() && state.back()==2)state.back()=1;
                    else state.pb(1),state.pb(1);
                }
                else{
                    if(state.size() && state.back()==1)state.back()=2;
                    else state.pb(2),state.pb(2);
                }
            }
            if(s[j]=='J'){
                if(o==1){
                    int del=0;
                    for(int i=0;i<2;++i){
                        if(state.size() && state.back()==2)state.pop_back(),++del;
                        else break;
                    }
                    for(;del<2;++del){
                        state.pb(1);
                    }
                }
                else state.pb(2),state.pb(2);
            }
            if(s[j]=='L'){
                if(o==3){
                    int del=0;
                    for(int i=0;i<2;++i){
                        if(state.size() && state.back()==1)state.pop_back(),++del;
                        else break;
                    }
                    for(;del<2;++del){
                        state.pb(2);
                    }
                }
                else state.pb(1),state.pb(1);
            }
            if(s[j]=='S'){
                if(state.size() && state.back()==1);
                else state.pb(2),state.pb(1);
            }
            if(s[j]=='Z'){
                if(state.size() && state.back()==2);
                else state.pb(1),state.pb(2);
            }
        }
        if(state.empty())return rt;
    }
    return vint();
}

vint arrangeTetrominoes(int n, string s, int q) {
    /* if(solve18(n,s).empty() ^ realgo(n,s).empty()){
        cout<<"jizzed!"<<endl;
        return vint();
    } */
    if(n<=18)return solve18(n,s);
    return realgo(n,s);
}
