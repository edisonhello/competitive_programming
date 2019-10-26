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

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

#include<message.h>
#include"pancakes.h"

const int objSize = 4 * 2;
union obj {
    char byte[objSize];
    struct {
        int cRound;
        int lastStop;
    } detail;
} prv, ans;

int nC[104],nL[104],nR[104];

int main(){
    int nodes = NumberOfNodes();
    int me = MyNodeId();
    int n = GetStackSize();
    int m = GetNumDiners();
    for(int i=0;i<nodes;++i)nC[i]=n/nodes+!!(n%nodes>i);
    for(int i=0;i<nodes;++i)nL[i+1]=nL[i]+nC[i];
    for(int i=0;i<nodes;++i)nR[i]=nL[i+1]-1;

    int startPoint, now;
    if(nL[me]<n){
        startPoint = GetStackItem(nL[me]);
        now = startPoint;
        ++ans.detail.cRound;

        for(int i=nL[me];i<=nR[me];++i){
            // cout<<me<<" "<<n<<" "<<i<<endl;
            int pos = GetStackItem(i);
            if(pos < now){
                ++ans.detail.cRound;
            }
            now = pos;
        }
        ans.detail.lastStop = now;
    }

    if(me){
        Receive(me-1);
        for(int i=0;i<objSize;++i)prv.byte[i]=GetChar(me-1);
        if(nL[me]<n){
            ans.detail.cRound += prv.detail.cRound;
            if(prv.detail.lastStop <= startPoint) --ans.detail.cRound;
        }
        else ans=prv;
    }
    else ;

    // cout<<me<<" "<<ans.detail.cRound<<" , "<<prv.detail.cRound<<endl;

    if(me==nodes-1){
        cout<<ans.detail.cRound<<endl;
    }
    else{
        for(int i=0;i<objSize;++i)PutChar(me+1,ans.byte[i]);
        Send(me+1);
    }
}
