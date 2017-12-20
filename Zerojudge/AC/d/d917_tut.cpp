#include<bits/stdc++.h>
using namespace std;

vector<int> G[2][2][505];
int n,ind[505],dep[505];
bitset<505> v;
int meow(vector<int> *G,vector<int> *iG){
    memset(ind,0,sizeof(ind)); memset(dep,0,sizeof(dep)); v.reset();
    for(int i=1;i<=n;++i)for(int ii:G[i])++ind[ii];
    int meow=1; int rt=0;
    while(meow--){
        for(int i=1;i<=n;++i)if(!ind[i] && !v[i]){
            v[i]=1;
            for(int ii:iG[i])dep[i]=max(dep[i],dep[ii]+1);
            rt=max(rt,dep[i]);
            for(int ii:G[i])--ind[ii];
            meow|=1;
        }
    } return rt+1;
}
int main(){
    int w; cin>>n>>w;
    int a,b,c; while(cin>>a>>b>>c){
        if(c){
            G[0][0][a].push_back(b);
            G[0][1][b].push_back(a);
        }
        else{
            G[1][0][a].push_back(b);
            G[1][1][b].push_back(a);
        }
    }
    cout<<w*w*meow(G[0][0],G[0][1])*meow(G[1][0],G[1][1])<<endl;
}
