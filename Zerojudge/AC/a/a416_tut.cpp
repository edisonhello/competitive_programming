#include<bits/stdc++.h>
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

vector<int> odd;
int d[1004][1004],deg[1004],dp[1<<21],totwei;

int dfs(int x,int now){
    if(dp[x])return dp[x];
    if(x==0)return 0;
    // cout<<bitset<6>(x)<<" "<<now<<endl;
    while(!(x&(1<<now)))--now;
    int a=now,xx=x; xx=x^(1<<now); --now;
    dp[x]=99999999;
    for(int val;now>=0;--now){
        if(xx&(1<<now)){
            if((val=dfs(xx^(1<<now),a-1))+d[odd[a]][odd[now]]<dp[x]){
                dp[x]=val+d[odd[a]][odd[now]];
                // if(a==1 && (now==3 || now==5))cout<<a<<" "<<now<<" "<<dp[x]<<endl;
            }
        }
    }
    // cout<<"dp of "<<bitset<6>(x)<<" is "<<dp[x]<<endl;
    return dp[x];
}
void addodd(){
    totwei+=dfs((1<<odd.size())-1,odd.size()-1);
    /* int tmp=0;
    for(int i=0;i<odd.size();++i)tmp+=d[odd[i]][odd[match[i]]];
    for(int i=0;i<odd.size();++i)cout<<"match of "<<odd[i]<<" is "<<odd[match[i]]<<endl;
    totwei+=tmp/2; */
}

int main(){
    int n,m,s,t; rit(n,m,s,t);
    memset(d,0x3f,sizeof(d));
    while(m--){
        int u,v,c; rit(u,v,c);
        ++deg[u], ++deg[v];
        d[u][v]=d[v][u]=c;
        totwei+=c;
    }
    ++deg[s], ++deg[t];
    for(int i=1;i<=n;++i)d[i][i]=0,(deg[i]&1?odd.push_back(i):void());
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    // odd.clear(); for(int i=1;i<=20;++i)odd.push_back(i);
    addodd();
    int ans=0;
    cout<<totwei<<endl;
}
