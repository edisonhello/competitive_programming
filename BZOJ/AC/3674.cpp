#include<bits/stdc++.h>
#include<ext/rope>

using namespace std;
using namespace __gnu_cxx;

rope<int> *r[200005],*sz[200005];

int F(int v,int x){
    int rx=r[v]->at(x);
    if(rx==x)return x;
    int rt=F(v,rx);
    if(rt==rx)return rt;
    r[v]->replace(x,rt);
    return rt;
}
void U(int v,int x,int y){
    x=F(v,x),y=F(v,y);
    if(x==y)return;
    int szx=sz[v]->at(x),szy=sz[v]->at(y);
    if(szx<szy)swap(x,y);
    r[v]->replace(y,x), sz[v]->replace(x,szx+szy);
}
bool C(int v,int x,int y){
    x=F(v,x),y=F(v,y);
    return x==y;
}

int _r[200005],_sz[200005];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<=n;++i)_r[i]=i,_sz[i]=1;
    r[0]=new rope<int>(_r,n+1); sz[0]=new rope<int>(_sz,n+1);
    int x=0;
    for(int i=1;i<=m;++i){
        int com;scanf("%d",&com);
        if(com==3){
            int u,v;scanf("%d%d",&u,&v);u^=x;v^=x;
            r[i]=new rope<int>(*r[i-1]);
            sz[i]=new rope<int>(*sz[i-1]);
            x=C(i,u,v);
            printf("%d\n",x);
        }
        else if(com==2){
            int v;scanf("%d",&v);v^=x;
            r[i]=r[v];
            sz[i]=sz[v];
        }
        else if(com==1){
            int u,v;scanf("%d%d",&u,&v);u^=x;v^=x;
            r[i]=new rope<int>(*r[i-1]);
            sz[i]=new rope<int>(*sz[i-1]);
            U(i,u,v);
        }
    }
}
