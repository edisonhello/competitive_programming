#include<bits/stdc++.h>
using namespace std;
#include"lib1740.h"

int djs[100005],u[100005],v[100005],c[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}

int main(){
    int n,m,k;
    Init(n,m,k,u,v,c);
    vector<int> ans;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=0;i<m;++i)if(c[i])U(u[i],v[i]);
    for(int i=0;i<m;++i)if(!c[i] && !C(u[i],v[i]))U(u[i],v[i]),ans.push_back(i);
    if(ans.size()>k)exit((NoSolution(),0));
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i:ans)U(u[i],v[i]);
    for(int i=0;i<m && ans.size()<k;++i)if(!c[i] && !C(u[i],v[i]))U(u[i],v[i]),ans.push_back(i);
    if(ans.size()<k)exit((NoSolution(),0));
    for(int i=0;i<m;++i)if(c[i] && !C(u[i],v[i]))U(u[i],v[i]),ans.push_back(i);
    for(int i:ans)Solution(u[i],v[i],c[i]);
}
