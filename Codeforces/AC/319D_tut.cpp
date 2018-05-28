#pragma GCC optimize("O3")
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
const ll p=47017;

ll hsh[50005],ppp[50005];

inline ll ghh(int L,int R){
    return (hsh[R]-(L?hsh[L-1]:0)+mod)*ppp[50004-R]%mod;
}

int main(){
    CPPinput;
    string s; cin>>s;
    int n=s.size();
    ppp[0]=1; for(int i=1;i<50005;++i)ppp[i]=ppp[i-1]*p%mod;
    hsh[0]=s[0];
    for(int i=1;i<n;++i)hsh[i]=(hsh[i-1]+s[i]*ppp[i])%mod;
    auto chk1=[&]()->void{
        string ss;
        for(char c:s){
            if(ss.size() && c==ss.back());
            else ss+=c;
        }
        s=ss;
        n=s.size();
        hsh[0]=s[0];
        for(int i=1;i<n;++i)hsh[i]=(hsh[i-1]+s[i]*ppp[i])%mod;
        return;
    };
    auto chk2=[&]()->void{
        bool rt=0;
        string ss;
        for(char c:s){
            if(ss.size()>1 && c==ss[ss.size()-2] && ss.back()==ss[ss.size()-3])ss.pop_back();
            else ss+=c;
        }
        s=ss;
        n=s.size();
        hsh[0]=s[0];
        for(int i=1;i<n;++i)hsh[i]=(hsh[i-1]+s[i]*ppp[i])%mod;
        return;
    };
    int len,spos;
    auto chk=[&]()->int{
        for(int j=spos+len-1,L,R,fr,bk,mid,jj;j+len<n;j+=len){
            if(s[j]!=s[j+len])continue;
            L=0,R=len;
            jj=j+len;
            while(R>L){
                mid=(L+R+1)>>1;
                if(ghh(j-mid+1,j)==ghh(jj-mid+1,jj))L=mid;
                else R=mid-1;
            }
            fr=L;
            L=0,R=min(len,n-jj);
            while(R>L){
                mid=(L+R+1)>>1;
                if(ghh(j,j+mid-1)==ghh(jj,jj+mid-1))L=mid;
                else R=mid-1;
            }
            bk=L-1;
            if(fr+bk>=len){
                s.erase(j,len);
                n=s.size();
                hsh[0]=s[0];
                for(int i=1;i<n;++i)hsh[i]=(hsh[i-1]+s[i]*ppp[i])%mod;
                return j-len+1;
            }
        }
        return -1;
    };
    chk1();
    chk2();
    for(len=3;len<=s.size()>>1;++len){
        spos=0;
        while((spos=chk())!=-1);
    }
    cout<<s<<endl;
}
