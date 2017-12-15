// copy from TIOJ 1915
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker,"/STACK:36777216")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<bitset>
using namespace std;

#define getchar gtx
#define fread fread_unlocked
inline char gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

vector<int> G[500008];
int deg[500008],cnt[500008],newnum[500008];
bitset<500008> rem;
int main(){
    int t; rit(t); while(t--){
        int n,e,u,v,ans1=0,ans2=0,nnptr=-1; rit(n,e);
        for(int i=0;i<n;++i)G[i].clear(),deg[i]=0,cnt[i]=0; rem.reset();
        while(e--){
            rit(u,v);
            G[u].push_back(v);
            G[v].push_back(u);
            ++deg[u], ++deg[v];
            if(u<v)++cnt[u]; else ++cnt[v];
            ans1=max(ans1,max(cnt[u],cnt[v]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // for(int i=0;i<n;++i)cout<<"deg of "<<i<<" = "<<deg[i]<<endl;
        for(int i=0;i<n;++i)pq.emplace(deg[i],i),cnt[i]=0;
        while(pq.size()){
            while(pq.size() && rem[pq.top().second])pq.pop();
            if(pq.empty())break;
            newnum[pq.top().second]=++nnptr;
            rem[pq.top().second]=1;
            for(int i:G[pq.top().second]){
                if(rem[i])continue;
                --deg[i];
                pq.emplace(deg[i],i);
            }
        }
        // for(int i=0;i<n;++i)cout<<"newnum of "<<i<<" is "<<newnum[i]<<endl;
        for(int i=0;i<n;++i){
            for(int ii:G[i]){
                if(newnum[i]<newnum[ii])++cnt[i]; else ++cnt[ii];
                ans2=max(ans2,max(cnt[i],cnt[ii]));
            }
        }
        // for(int i=0;i<n;++i)cout<<"cnt of new graph "<<i<<" is "<<cnt[i]<<endl;
        printf("%d %d\n",ans1,ans2>>1);
    }
}
