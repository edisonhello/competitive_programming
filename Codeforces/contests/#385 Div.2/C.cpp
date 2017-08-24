#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<map>
#include<utility>
using namespace std;

int djs[1005],sz[1005],n,m,k,c[1005],ans;
bool v[1005];

int F(int x){
    if(x==djs[x])return x;
    return djs[x]=F(djs[x]);
}
inline void U(int x,int y){
    x=F(x),y=F(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    djs[y]=x;
    sz[x]+=sz[y];
}
inline int S(int x){
    x=F(x);
    return sz[x];
}
inline bool C(int x,int y){
    return F(x)==F(y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<k;++i)cin>>c[i];
    for(int i=1;i<=n;++i)djs[i]=i,sz[i]=1;
    // cout<<"fads"<<endl;
    {int a,b;for(int i=0;i<m;++i){
        cin>>a>>b;
        U(a,b);
    }}
    int haveLargeC=-1,largeMax=0;
    // cout<<"fads"<<endl;
    for(int i=0;i<k;++i){
        if(S(c[i])>largeMax){
            largeMax=S(c[i]);
            haveLargeC=c[i];
        }
    }
    // cout<<"fads"<<endl;
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j){
            if(C(i,c[j]))goto NOOO;
        }
        U(haveLargeC,i);
        NOOO:;
    }
    for(int i=1,hd;i<=n;++i){
        hd=F(i);
        if(v[hd])continue;
        v[hd]=1;
        int s=S(hd);
        ans+=s*(s-1)/2;
    }
    cout<<ans-m<<endl;
}
