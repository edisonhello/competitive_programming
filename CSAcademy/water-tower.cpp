// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

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
#define vpii vector<pair<int,int>>
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

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

pair<int,int> t[100005];
int h[100005];

int main(){
    CPPinput;
    int H,n; cin>>H>>n;
    // for(int i=1;i<=n;++i)cin>>t[i].first>>t[i].second;
    for(int i=1;i<=n;++i)cin>>t[i].first>>h[i],t[i].second=1e9;
    PQ<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> keytime;
    for(int i=1;i<=n;++i)keytime.emplace(t[i].first,i),keytime.emplace(t[i].second,i);
    if([&]()->bool{for(int i=1;i<=n;++i)if(h[i]==0)return 0;return 1;}())exit((cout<<-1<<endl,0));
    double nowh=H,nowt=0;
    int nowhole=0;
    multiset<int> activeh;
    while(nowh>eps){
        PDE(nowh,nowt);
        if(keytime.empty())exit((cout<<-1<<endl,0));
        if(nowhole==0){
            nowt=keytime.top().first;
            int i=keytime.top().second;
            keytime.pop();
            if(int(nowt)==t[i].second)continue;
            if(nowh<=h[i])continue;
            nowhole++;
            activeh.insert(h[i]);
            continue;
        }
        double nkt=keytime.top().first;
        int i=keytime.top().second;
        // keytime.pop();
        double dt=nkt-nowt;
        double dh=dt*nowhole;
        int nhh=*prev(activeh.end());
        if(nhh!=0){
            if(nowh-dh>=nhh){
                keytime.pop();
                nowt+=dt;
                nowh-=dh;
                if(int(nkt)==t[i].first){
                    if(nowh<=h[i]);
                    else{
                        nowhole++;
                        activeh.insert(h[i]);
                    }
                }
                else{
                    if(nowh<=h[i]);
                    else{
                        nowhole--;
                        activeh.erase(activeh.find(h[i]));
                    }
                }
            }
            else{
                dh=nowh-nhh;
                dt=dh/nowhole;
                nowt+=dt;
                nowh-=dh;
                activeh.erase(prev(activeh.end()));
                nowhole--;
            }
        }
        else{
            keytime.pop();
            if(dh>nowh)exit((cout<<fixed<<setprecision(14)<<nowt+nowh/nowhole<<endl,0));
            else{
                nowt+=dt;
                nowh-=dh;
                if(int(nkt)==t[i].first){
                    if(nowh<=h[i]);
                    else{
                        nowhole++;
                        activeh.insert(h[i]);
                    }
                }
                else{
                    if(nowh<=h[i]);
                    else{
                        nowhole--;
                        activeh.erase(activeh.find(h[i]));
                    }
                }
            }
        }
    }
    cout<<fixed<<setprecision(14)<<nowt<<endl;
}
