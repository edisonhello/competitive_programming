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
#include"stones.h"

const int objSize = 4 * 3;
union Obj {
    char byte[objSize];
    struct {
        int nowAns;
        int nowFar;
        int nxtFar;
    } detail;
    Obj(){ memset(this, 0, sizeof(Obj)); }
} ans;
#define $(x) x.detail

Obj receive(int from){
    Obj obj;
    Receive(from);
    for(int i=0;i<objSize;++i)obj.byte[i]=GetChar(from);
    return obj;
}
void send(int go, Obj obj){
    for(int i=0;i<objSize;++i)PutChar(go, obj.byte[i]);
    Send(go);
}

int nC[104],nL[104],nR[104];

int farto[10000007];
int cnt[10000007];
int stepfar[10000007];
int prefar[10000007];

int main(){
    int nodes = NumberOfNodes();
    int me = MyNodeId();
    int n = GetNumberOfStones() + 1;
    for(int i=0;i<nodes;++i)nC[i]=n/nodes+!!(n%nodes>i);
    for(int i=0;i<nodes;++i)nL[i+1]=nL[i]+nC[i];
    for(int i=0;i<nodes;++i)nR[i]=nL[i+1]-1;
    
    int offset=nL[me],thiscnt=nR[me]-nL[me]+1;
    cout<<"nL, nR: "<<nL[me]<<" "<<nR[me]<<endl;
    for(int z=0,i=nL[me];i<=nR[me];++i,++z){
        farto[z]=z+GetJumpLength(i);
        if(z)prefar[z]=max(prefar[z-1],farto[z]);
        else prefar[z]=farto[z];
        cout<<"farto["<<z<<"]="<<farto[z]<<endl;
    }
    int cur=0,maxstep;
    for(int i=0;;++i){
        if(cur>thiscnt){
            maxstep=i-1;
            break;
        }
        while(cur<=stepfar[i] && cur<=thiscnt){
            stepfar[i+1]=max(stepfar[i+1],farto[cur]);
            ++cur;
        }
        cout<<"stepfar["<<i+1<<"]="<<stepfar[i+1]<<endl;
        // cout<<i<<" "<<cur<<endl;
    }
    cout<<"maxstep: "<<maxstep<<endl;
    cnt[0]=maxstep;
    for(int i=1;i<=maxstep;++i){
        for(int j=stepfar[i-1];j<min(stepfar[i],thiscnt);++j){
            cnt[j]=maxstep-i+1;
            cout<<"assign cnt["<<j<<"] as "<<maxstep-i+1<<endl;
        }
    }
    for(int i=0;i<thiscnt;++i){
        cout<<"cnt["<<i<<"]="<<cnt[i]<<endl;
    }

    if(me!=0){
        ans=receive(me-1);
    }
    int &nowFar=$(ans).nowFar;
    int &nowAns=$(ans).nowAns;
    int &nxtFar=$(ans).nxtFar;
    cout<<nowFar<<" "<<nowAns<<" "<<nxtFar<<endl;
    while(1){
        if(nowFar>=offset+thiscnt){
            nxtFar=max(nxtFar,prefar[thiscnt-1]+offset);
            break;
        }
        else{
            cout<<"cut in middle"<<endl;
            nxtFar=max(nxtFar,prefar[nowFar-offset]+offset);
            ++nowAns;
            nowFar=nxtFar;
            nxtFar=prefar[thiscnt-1];
        }
    }
    cout<<nowFar<<" "<<nowAns<<" "<<nxtFar<<endl;
    if(me!=nodes-1){
        send(me+1,ans);
    }
    else cout<<nowAns<<endl;
}
