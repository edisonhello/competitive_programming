#include<bits/stdc++.h>
using namespace std;

void no(){cout<<"Impossible"<<endl; exit(0);}

struct edge{
    int u,v,c;
    int op(int x){return x==u?v:u;}
};

vector<edge> e;
vector<int> G[123],ans;
int djs[453];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=2*n;++i)djs[i]=i;

    while(m--){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back(e.size());
        G[v].push_back(e.size());
        e.push_back({u,v,c});
        if(c==0){
            if(C(u,v) || C(u+n,v+n))no();
            U(u,v+n); U(u+n,v);
        }
        else{
            if(C(u,v+n) || C(u+n,v))no();
            U(u,v); U(u+n,v+n);
        }
    }

    for(int i=1;i<=n;++i){
        if(F(i)>n)ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
