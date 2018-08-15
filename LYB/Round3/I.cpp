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

#ifndef WEAK
#include "grader.h"
#else
vint Initial(){
    cout<<"Initial"<<endl;
    int n; cin>>n;
    vint v(n);
    for(int &i:v)cin>>i;
    return v;
}
void Take(int a,int b,int &c,int &d){
    cout<<"from pile "<<a<<" took "<<b<<endl;
    cin>>c>>d;
}
void Surrender(){
    cout<<"Surendered"<<endl;
    exit(0);
}
#endif

#define Take(a,b,c,d) Take(a+1,b,c,d)
int main(){
    // Surrender();
    vint v=Initial();
    int n=int(v.size());
    if(v.size()==1u){ int c,d; Take(0,v[0],c,d); }
    int sg=0;
    for(int i:v)sg^=i;
    PDE(sg);
    while(1){
    if(!sg){
        if(![&]()->bool{
            if(n==2)Surrender();
            auto success=[&](int mx,int sg)->bool{
                return (sg^mx)>mx;
            };
            int mx=-1,mxi=-1;
            for(int i=0;i<n;++i)if(mx<v[i])mx=v[i],mxi=i;
            for(int i=0;i<n;++i)if(i!=mxi){
                for(int j=0;j<v[i];++j){
                    if(success(mx,j)){
                        int c,d;
                        Take(i,v[i]-j,c,d);
                        v[i]=j;
                        v[c-1]-=d;
                        return 1;
                    }
                }
            }
            mx=-1;
            for(int i=0;i<n;++i)if(i!=mxi)mx=max(mx,v[i]);
            for(int j=0;j<v[mxi];++j){
                if(success(mx,j)){
                    int c,d;
                    Take(mxi,v[mxi]-j,c,d);
                    v[mxi]=j;
                    v[c-1]-=d;
                    return 1;
                }
            }
            return 0;
        }())Surrender();
    }
        int sg=0;
        for(int i:v)sg^=i;
        bool tk=0;
        PDE(v,sg);
        vector<int> id(n);
        for(int i=0;i<n;++i)id[i]=i;
        sort(id.begin(),id.end(),[&](const int &a,const int &b){ return v[a]>v[b]; });
        for(int i=0;i<n;++i){
            if(v[id[i]]==0)continue;
            if(tk)break;
            for(int j=0;j<v[id[i]];++j){
                if((sg^v[id[i]]^j)==0){
                    tk=1;
                    int c,d;
                    Take(i,v[id[i]]-j,c,d);
                    v[id[i]]=j;
                    v[c-1]-=d;
                    break;
                }
            }
        }
    }
}

/* map<multiset<int>,int> sg;

int go(multiset<int> v,int who){
    if(v.empty())return 0;
    auto it=sg.find(v);
    if(it!=sg.end())return it->second;
    auto &sgval=sg[v];
    if(who){
        set<int> sgs;
        set<int> vals;
        for(int i:v)vals.insert(i);
        for(int i:vals){
            v.erase(v.find(i));
            for(int z=0;z<i;++z){
                if(z)v.insert(z);
                sgs.insert(go(v,who^1));
                if(z)v.erase(v.find(z));
            }
            v.insert(i);
        }
        for(int i=0;;++i)if(sgs.find(i)==sgs.end())return sgval+=i;
    }
    else{ // take max
        int mx=*prev(v.end());
        v.erase(v.find(mx));
        set<int> sgs;
        for(int z=0;z<mx;++z){
            if(z)v.insert(z);
            sgs.insert(go(v,who^1));
            if(z)v.erase(v.find(z));
        }
        for(int i=0;;++i)if(sgs.find(i)==sgs.end())return sgval+=i;
    }
} */

/* int main(){
    CPPinput;
    int NN=20;
    for(int i=1;i<=NN;++i){
        for(int j=i;j<=NN;++j){
            for(int k=j;k<=NN;++k){
                for(int l=k;l<=NN;++l){
                    multiset<int> st;
                    st.insert(i);
                    st.insert(j);
                    st.insert(k);
                    st.insert(l);
                    if(go(st,1)==0)
                    cout<<i<<" "<<j<<" "<<k<<" "<<l<<" xor: "<<(i^j^k^l)<<'\n';
                    // cout<<i<<" "<<j<<" "<<k<<" "<<go(st,1)<<'\n';
                }
            }
        }
    }
} */
