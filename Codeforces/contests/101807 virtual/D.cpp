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

int main(){
    CPPinput;
    string s; cin>>s;
    if(s=="0")JIZZ("0\n");
    vector<string> v;
    string ns;
    for(char c:s){
        if(c=='+' || c=='-' && ns!=""){
            v.pb(ns);
            ns="";
            if(c=='-')ns+=c;
        }
        else{
            ns+=c;
        }
    }
    v.pb(ns); ns="";
    if(v.size()==1u){
        bool cons=1;
        for(char c:v[0])if(c=='x')cons=0;
        if(cons)JIZZ("0\n");
    }
    for(string &s:v){
        bool sign=(s[0]=='-');
        if(s[0]=='-')s=s.substr(1,s.size()-1);
        int posx=-1;
        for(int i=0;i<s.size();++i)if(s[i]=='x')posx=i;
        if(posx==-1){s=""; continue;}
        int xi=0;
        if(posx==0)xi=1;
        else{
            stringstream ss(s.substr(0,posx));
            ss>>xi;
        }
        int po=0;
        if(posx==s.size()-1)po=1;
        else{
            stringstream ss(s.substr(posx+1,s.size()-posx-1));
            ss>>po;
        }
        PDE(xi,po);
        xi*=po; --po;
        string ns;
        if(sign)ns+='-';
        if(xi!=1 || po==0){
            stringstream ss; ss<<xi;
            string tmp; ss>>tmp;
            ns+=tmp;
        }
        if(po!=0){
            ns+="x";
            if(po!=1){
                stringstream ss; ss<<po;
                string tmp; ss>>tmp;
                ns+=tmp;
            }
        }
        s=ns;
    }
    if(v.back()=="")v.pop_back();
    for(int i=0;i<v.size();++i){
        if(i && v[i][0]!='-')cout<<'+';
        cout<<v[i];
    }
    cout<<endl;
}
