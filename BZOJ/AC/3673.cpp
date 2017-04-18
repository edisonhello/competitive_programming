#include<bits/stdc++.h>
#include<ext/rope>

using namespace std;
using namespace __gnu_cxx;

rope<int> *r[20004],*sz[20004];

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
    if(x<y)swap(x,y);
    r[v]->replace(y,x), sz[v]->replace(x,szx+szy);
}
bool C(int v,int x,int y){
    x=F(v,x),y=F(v,y);
    return x==y;
}

int main(){
    int n,m;cin>>n>>m;
    r[0]=new rope<int>(); sz[0]=new rope<int>();
    for(int i=0;i<=n;++i)r[0]->append(i),sz[0]->append(1);
    for(int i=1;i<=m;++i){
        int com;cin>>com;
        if(com==3){
            int u,v;cin>>u>>v;
            r[i]=new rope<int>(*r[i-1]);
            sz[i]=new rope<int>(*sz[i-1]);
            cout<<C(i,u,v)<<endl;
        }
        else if(com==2){
            int v;cin>>v;
            r[i]=new rope<int>(*r[v]);
            sz[i]=new rope<int>(*sz[v]);
        }
        else if(com==1){
            int u,v;cin>>u>>v;
            r[i]=new rope<int>(*r[i-1]);
            sz[i]=new rope<int>(*sz[i-1]);
            U(i,u,v);
        }
    }
}
