#include<bits/stdc++.h>
using namespace std;

struct disjointSet{
    std::vector<int> djs;
    void init(int size){
        djs.resize(size);
        for(int i=0;i<size;++i)djs[i]=i;
    }
    int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
    void U(int x,int y){djs[F(x)]=F(y);}
    bool C(int x,int y){return F(x)==F(y);}
} djs;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q; cin>>n>>m>>q;
    djs.init(n+5);
    while(m--){
        int u,v; cin>>u>>v;
        djs.U(u,v);
    }
    while(q--){
        int u,v; cin>>u>>v;
        if(djs.C(u,v))cout<<":)"<<endl;
        else cout<<":("<<endl;
    }
}
