// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
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

string s[303][303],t[303][303];
int same[303][303];
deque<char> dq[303][303];
int c1[303][303],c0[303][303];


// queue<pair<pair<int,int>,int>> provide,request

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>s[i][j],reverse(s[i][j].begin(),s[i][j].end());
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>t[i][j],reverse(t[i][j].begin(),t[i][j].end());
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
        for(char c:s[i][j]){
            dq[i][j].push_back(c);
            if(c=='0')++c0[i][j];
            else ++c1[i][j];
        }
    }
    vector<pair<pair<int,int>,pair<int,int>>> ans;
#define add(a,b,c,d) ans.emplace_back(make_pair(a,b),make_pair(c,d))
    auto move=[&](int a,int b,int c,int d)->void{
        // swap(a,c); swap(b,d);
        // PDE(a,b,c,d);
        char cc=dq[a][b].front(); dq[a][b].pop_front();
        if(cc=='0')--c0[a][b]; else --c1[a][b];
        dq[c][d].push_back(cc);
        if(cc=='0')++c0[c][d]; else ++c1[c][d];
        add(a,b,c,d);
    };

    for(int i=1;i<=n;++i)for(int j=3;j<=m;++j){
        while(dq[i][j].size()){
            if(dq[i][j].front()=='0')move(i,j,i,1);
            else move(i,j,i,2);
        }
    }
    for(int i=3;i<=n;++i){
        for(int j=1;j<=2;++j){
            while(dq[i][j].size()){
                if(j==1){
                    if(dq[i][j].front()=='0')move(i,1,2,1);
                    else move(i,1,1,1);
                }
                else{
                    if(dq[i][j].front()=='0')move(i,2,2,2);
                    else move(i,2,1,2);
                }
            }
        }
    }
    while(dq[2][2].size()){
        if(dq[2][2].front()=='0')move(2,2,2,1);
        else move(2,2,1,2);
    }
    while(dq[1][1].size()){
        if(dq[1][1].front()=='0')move(1,1,2,1);
        else move(1,1,1,2);
    }
    while(c1[2][1]){
        if(dq[2][1].front()=='0'){
            move(2,1,1,1);
            move(1,1,2,1);
        }
        else{
            move(2,1,1,1);
            move(1,1,1,2);
        }
    }
    while(c0[1][2]){
        if(dq[1][2].front()=='0'){
            move(1,2,1,1);
            move(1,1,2,1);
        }
        else{
            move(1,2,1,1);
            move(1,1,1,2);
        }
    }


    for(int i=1;i<=n;++i)for(int j=3;j<=m;++j){
        for(char c:t[i][j]){
            if(c=='0'){
                if(i==2)move(2,1,2,j);
                else{
                    move(2,1,i,1);
                    move(i,1,i,j);
                }
            }
            else{
                if(i==1)move(1,2,1,j);
                else{
                    move(1,2,i,2);
                    move(i,2,i,j);
                }
            }
        }
    }
    for(int i=3;i<=n;++i)for(int j=1;j<=2;++j){
        for(char c:t[i][j]){
            if(c=='0'){
                if(j==1)move(2,1,i,1);
                else{
                    move(2,1,2,2);
                    move(2,2,i,2);
                }
            }
            else{
                if(j==2)move(1,2,i,2);
                else{
                    move(1,2,1,1);
                    move(1,1,i,1);
                }
            }
        }
    }
    for(char c:t[1][2]){
        if(c=='0')move(2,1,1,1);
        else move(1,2,1,1);
    }
    while(dq[1][1].size())move(1,1,1,2);
    for(char c:t[2][1]){
        if(c=='0')move(2,1,1,1);
        else move(1,2,1,1);
    }
    while(dq[1][1].size())move(1,1,2,1);
    for(char c:t[1][1]){
        if(c=='0')move(2,1,1,1);
        else move(1,2,1,1);
    }
    for(char c:t[2][2]){
        if(c=='0')move(2,1,2,2);
        else move(1,2,2,2);
    }

    cout<<ans.size()<<endl;
    for(auto p:ans){
        cout<<p.X.X<<" "<<p.X.Y<<" ";
        cout<<p.Y.X<<" "<<p.Y.Y<<"\n";
    }

}
