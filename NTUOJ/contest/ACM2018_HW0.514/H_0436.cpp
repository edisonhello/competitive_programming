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

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define exp expexpexpexp
#define expl explexplexpl

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
const ld eps=1e-8;
const ll mod=1e9+7;

pii p[111];

int main(){
    CPPinput;
    int n; while(cin>>n,n){
        for(int i=0;i<n;++i)cin>>p[i].first>>p[i].second;
        for(int i=0;i<n;++i)p[i].first+=2001,p[i].second+=2001;
        int ans=0;
        for(int x=0;x<4004;++x){
            bitset<4004> mp;
            vector<pair<double,double>> lr;
            for(int i=0;i<n;++i){
                pii c=p[i],d=p[i==n-1?0:i+1];
                if(c.first==d.first)continue;
                if(c.first>d.first)swap(c,d);
                if(!(d.first<=x || c.first>=x+1)){
                    double y_x=(double)(d.second-c.second)/(d.first-c.first);
                    double l=(x-c.first)*y_x+c.second,r=(x+1-c.first)*y_x+c.second;
                    lr.eb(l,r);
                }
            }
            sort(lr.begin(),lr.end());
            for(int i=0;i<int(lr.size())-1;i+=2){
                for(int z=floor(min(lr[i].first,lr[i].second)+eps);z<ceil(max(lr[i+1].first,lr[i+1].second)-eps);++z){
                    mp[z]=1;
                }
            }
            ans+=mp.count();
            // if(lr.size())PDE(x,lr);
        }
        cout<<ans<<endl;
    }
}
