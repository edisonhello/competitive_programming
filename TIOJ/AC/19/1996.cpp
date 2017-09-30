#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<bitset>
#include"lib1996.h"
using namespace std;

deque<int> q[4];
vector<pair<int,int>> G[3000006];
bitset<3000006> u;
int d[3000006];
bool all0=1;

int F(int x){return x==d[x]?x:d[x]=F(d[x]);}
inline void U(int x,int y){d[F(x)]=F(y);}

void init(int N,int M,int A[],int B[],int K[]){
    for(int i=0;i<M;++i){
        G[A[i]].emplace_back(B[i],K[i]);
        G[B[i]].emplace_back(A[i],K[i]);
        if(K[i])all0=0;
    }
    if(all0){
        for(int i=1;i<N;++i)d[i]=i;
        for(int i=0;i<M;++i){
            U(A[i],B[i]);
        } return;
    }
    memset(d,0x3f,sizeof(d)); d[0]=0; q[0].push_back(0);
    for(int D=0;D<6000006;++D){
        int td3=D&3;
        while(q[td3].size()){
            while(q[td3].size() && u[q[td3].front()])q[td3].pop_front();
            if(q[td3].empty())break;
            int now=q[td3].front(); q[td3].pop_front();
            u[now]=1;
            for(auto i:G[now]){
                if(d[i.first]>d[now]+i.second){
                    d[i.first]=d[now]+i.second;
                    q[(d[now]+i.second)&3].push_back(i.first);
                }
            }
        }
    }
}
int get_cost(int x){
    if(all0){
        return (F(x)==F(0)?0:-1);
    }
    if(d[x]==0x3f3f3f3f)return -1;
    else return d[x]<<4;
}
