// zj b412
#include<ext/rope>
using namespace __gnu_cxx;
rope<int> *r[100009],*sz[100009];

int F(int ver,int u){
    int ru=r[ver]->at(u);
    if(ru==u)return u;
    int rur=F(ver,ru);
    if(rur==ru)return rur;
    r[ver]->replace(u,rur);
    return rur;
}
void U(int ver,int u,int v){
    u=F(ver,u); v=F(ver,v);
    if(u==v)return;
    int szu=sz[ver]->at(u), szv=sz[ver]->at(v);
    if(szu<szv)swap(u,v);
    r[ver]->replace(v,u); sz[ver]->replace(u,szu+szv);
}
bool C(int ver,int u,int v){
    u=F(ver,u); v=F(ver,v);
    return u==v;
}

int _r[100009],_sz[100009];
int main(){
    int n,m,i,op,day,u,v;rit(n,m);
    for(i=0;i<=n;++i)_r[i]=i,_sz[i]=1;
    r[0]=new rope<int>(_r,n+1); sz[0]=new rope<int>(_sz,n+1);
    bool x=0;
    for(i=1;i<=m;++i){
        rit(op);op^=x;
        if(op==0){
            rit(day);day^=x;
            r[i]=new rope<int>(*r[day]);
            sz[i]=new rope<int>(*sz[day]);
        }
        else if(op==1){
            rit(u,v);u^=x;v^=x;
            r[i]=new rope<int>(*r[i-1]);
            sz[i]=new rope<int>(*sz[i-1]);
            U(i,u,v);
        }
        else{
            rit(u,v);u^=x;v^=x;
            r[i]=new rope<int>(*r[i-1]);
            sz[i]=new rope<int>(*sz[i-1]);
            pit(x=C(i,u,v)),el;
        }
    }
}
