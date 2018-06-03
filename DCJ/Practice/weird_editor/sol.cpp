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
#include"weird_editor.h"
#define int long long

const int objSize = sizeof(int) * 15;
union Obj {
    char byte[objSize];
    struct {
        int cnt[15];
    } detail;
    Obj(){ memset(this, 0, sizeof(Obj)); }
} val[104];

Obj receive(int from, int size = objSize){
    Obj obj;
    // cout<<"waiting message from "<<from<<endl;
    Receive(from);
    for(int i=0;i<size;++i)obj.byte[i]=GetChar(from);
    // cout<<"got message from "<<from<<endl;
    return obj;
}
void send(int go, Obj obj, int size = objSize){
    for(int i=0;i<size;++i)PutChar(go, obj.byte[i]);
    Send(go);
    // cout<<"send message to "<<go<<endl;
}

int pw(int b,int n,int m=mod,int a=1){
    while(n){
        if(n&1)a=1ll*a*b%m;
        b=1ll*b*b%m; n>>=1;
    }
    return a;
}
int pw11(int n,int m=mod){
    if(n==0)return 0;
    if(n==1)return 1;
    int z=pw11(n/2);
    int x=(z*pw(10,n/2)+z)%m;
    if(n&1)x=(x*10+1)%m;
    return x;
}

int nC[104],nL[104],nR[104];
// int pw10[10000007],all1[10000007];

int32_t main(){
    int nodes = NumberOfNodes() - 1;
    int me = MyNodeId();
    int n = GetNumberLength();
    for(int i=0;i<nodes;++i)nC[i]=n/nodes+!!(n%nodes>i);
    for(int i=0;i<nodes;++i)nL[i+1]=nL[i]+nC[i];
    for(int i=0;i<nodes;++i)nR[i]=nL[i+1]-1;
    ++nodes;
    
    if(me==nodes-1){
        // for(int i=0;i<nodes;++i)cout<<i<<" : "<<nL[i]<<" to "<<nR[i]<<endl;
        
        // pw10[0]=1;
        // for(int i=1;i<10000007;++i)pw10[i]=pw10[i-1]*10ll%mod;
        int nowtop=1;
        int value=0;
        int nowbase=1;
        int leftdigit=n;
        for(int i=0;i<nodes-1;++i)val[i]=receive(i);
        for(int i=nodes-2;i>=0;--i){
            int bottom=nowtop;
            nowtop=9; while(val[i].detail.cnt[nowtop]==0 && nowtop>bottom)--nowtop;
            val[i].detail.cnt[10]=nowtop;
            val[i].detail.cnt[11]=bottom;
            val[i].detail.cnt[12]=nowbase;
            send(i,val[i]);
            // cout<<i<<" digit range "<<bottom<<" to "<<nowtop<<endl;
            int cnt=0;
            for(int j=bottom;j<=nowtop;++j)cnt+=val[i].detail.cnt[j];
            nowbase=1ll*nowbase*pw(10,cnt)%mod;
            leftdigit-=cnt;
        }
        for(int i=0;i<nodes-1;++i){
            val[i]=receive(i);
            value+=val[i].detail.cnt[13];
            if(value>=mod)value-=mod;
        }
        int base=1;
        while(leftdigit){
            if(leftdigit>=10000000){
                base=1ll*base*pw(10,10000000)%mod;
                leftdigit-=10000000;
            }
            else{
                base=1ll*base*pw(10,leftdigit)%mod;
                leftdigit=0;
            }
        }
        cout<<1ll*value*base%mod<<endl;
    }
    else{
        int nowtop=1;
        // cout<<nL[me]<<" to "<<nR[me]<<endl;
        for(int i=nR[me];i>=nL[me];--i){
            int dig=GetDigit(i);
            while(nowtop<dig)++nowtop;
            if(dig<nowtop)continue;
            // cout<<"dig "<<i<<" is "<<dig<<endl;
            ++val[me].detail.cnt[dig];
        }
        send(nodes-1,val[me]);
        // pw10[0]=1;
        // for(int i=1;i<10000007;++i)pw10[i]=pw10[i-1]*10ll%mod;
        // all1[0]=0;
        // for(int i=1;i<10000007;++i)all1[i]=(all1[i-1]*10ll+1)%mod;
        Obj obj=receive(nodes-1);
        int &value=obj.detail.cnt[13];
        // cout<<"value: "<<value<<endl;
        for(int i=obj.detail.cnt[11];i<=obj.detail.cnt[10];++i){
            value=(value+1ll*i*pw11(obj.detail.cnt[i])%mod*obj.detail.cnt[12])%mod;
            // cout<<i<<" "<<value<<endl;
            obj.detail.cnt[12]=(obj.detail.cnt[12]*pw(10,obj.detail.cnt[i]))%mod;
        }
        send(nodes-1,obj);
        // cout<<"value: "<<value<<endl;
    }
}
