#include<bits/stdc++.h>
using namespace std;

bitset<777> G[777],v,go;
vector<int> iG[777];
int c[777],d[777],w[777],z[777];

int F(int x){ return x==d[x]?x:d[x]=F(d[x]); }
void U(int x,int y){ d[F(x)]=F(y); }

void JIZZ(){ cout<<"-1"<<endl; exit(0); }

void dfs(int now,int col){
    c[now]=col;
    v[now]=1;
    for(int i:iG[now]){
        U(now,i);
        if(v[i] && c[i]==col)JIZZ();
        else if(v[i]);
        else dfs(i,!col);
    }
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        G[u][v]=G[v][u]=1;
    }
    int e=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(!G[i][j] && (i^j))iG[i].push_back(j),++e;
        }
    }
    e>>=1;
    for(int i=1;i<=n;++i)d[i]=i;
    for(int i=1;i<=n;++i)if(!v[i])dfs(i,1);
    for(int i=1;i<=n;++i)w[F(i)]+=c[i],++z[F(i)];
    go[0]=1;
    for(int i=1;i<=n;++i)go=(go<<w[i])|(go<<z[i]-w[i]);
    // cout<<go<<endl;
    int one=0;
    for(int i=1;i<=n;++i)if(go[i] && max(one,n-one)>max(i,n-i))one=i;
    // cout<<"one: "<<one<<endl;
    cout<<one*(one-1)/2+(n-one)*(n-one-1)/2<<endl;
}
