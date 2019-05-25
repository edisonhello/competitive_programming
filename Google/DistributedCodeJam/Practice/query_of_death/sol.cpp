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
#include"query_of_death.h"

const int objSize = 4 + 4 + 8 + 8;
union Obj {
    char byte[objSize];
    struct {
        int messageType, sum;
        long long data1, data2;
        // 1: [L, R]
        // 2: [hash1, hash2]
        // 0: shutdown
        void setData(int a,int b){
            data1 = a;
            data2 = b;
        }
        void append(unsigned int idx1,unsigned int idx2,int data){
            if(data==0)return;
            idx1&=63;
            idx2&=63;
            data1^=1ll<<idx1;
            data2^=1ll<<idx2;
        }
    } detail;
    Obj(){ memset(this, 0, sizeof(Obj)); }
} shutdown;

int nodes, me;

Obj receive(int from){
    Obj obj;
    // cout<<me<<" is waiting "<<from<<endl;
    Receive(from);
    for(int i=0;i<objSize;++i)obj.byte[i]=GetChar(from);
    // cout<<me<<" received "<<from<<endl;
    return obj;
}
void send(int go, Obj obj){
    // cout<<"send from "<<me<<" to "<<go<<endl;
    for(int i=0;i<objSize;++i)PutChar(go, obj.byte[i]);
    Send(go);
}

int main(){
    nodes = NumberOfNodes();
    me = MyNodeId();

    int len = GetLength();
    
    if(me==nodes-2)return 0;
    if(me==nodes-1){
        // controller
        vector<int> availableChildren;
        for(int i=0;i<nodes-2;++i){
            availableChildren.push_back(i);
        }
        int L=0,R=len-1;
        int sum=0;

        while(R>L){
            int blockLen=(R-L+1)/availableChildren.size()+(!!((R-L+1)%availableChildren.size()));
            int nowL=L,nowR=R,ptr=0;
            vector<pair<int,int>> record;
            while(nowL<=nowR){
                int thisL=nowL,thisR=nowL+blockLen-1;
                thisR=min(thisR,nowR);
                nowL=thisR+1;
                Obj obj;
                obj.detail.messageType=1;
                obj.detail.setData(thisL,thisR);
                // cout<<"send to "<<availableChildren[ptr].first<<" and "<<availableChildren[ptr].second<<endl;
                send(availableChildren[ptr],obj);
                record.emplace_back(thisL,thisR);
                ++ptr;
            }
            int change=-1;
            int thisSum=0;
            for(int i=0;i<ptr;++i){
                Obj res=receive(availableChildren[i]);
                // cout<<"data1: "<<res1.detail.data1<<" and "<<res2.detail.data1<<endl;
                // cout<<"data2: "<<res1.detail.data2<<" and "<<res2.detail.data2<<endl;
                if(res.detail.data1 || res.detail.data2){
                    // cout<<"got different"<<endl;
                    L=record[i].first;
                    R=record[i].second;

                    send(availableChildren[i],shutdown);
                    change=i;
                }
                else{
                    thisSum+=res.detail.sum;
                }
            }
            if(change!=-1){
                sum+=thisSum;
                availableChildren.erase(availableChildren.begin()+change);
            }
        }
        cout<<sum+GetValue(L)<<endl;
        for(int worker:availableChildren){
            send(worker,shutdown);
        }
    }
    else{
        // receiver
        while(1){
            Obj mission=receive(nodes-1);
            if(mission.detail.messageType==0){
                // cout<<me<<" received 0, stop"<<endl;
                return 0;
            }
            Obj ret;
            ret.detail.messageType=2;
            unsigned int idx1=43,idx2=17;
            // cout<<me<<" got job "<<mission.detail.data1<<" to "<<mission.detail.data2<<endl;
            for(int i=mission.detail.data1;i<=mission.detail.data2;++i){
                int get=GetValue(i);
                ret.detail.append(idx1,idx2,get);
                idx1=(idx1<<7)^(idx1>>5);
                idx2=(idx2<<3)^(idx2>>6);
                ret.detail.sum+=get;
            }
            idx1=43, idx2=17;
            for(int i=mission.detail.data1;i<=mission.detail.data2;++i){
                int get=GetValue(i);
                ret.detail.append(idx1,idx2,get);
                idx1=(idx1<<7)^(idx1>>5);
                idx2=(idx2<<3)^(idx2>>6);
            }
            // cout<<me<<" datas: "<<ret.detail.data1<<" , "<<ret.detail.data2<<endl;
            send(nodes-1,ret);
        }
    }
}
