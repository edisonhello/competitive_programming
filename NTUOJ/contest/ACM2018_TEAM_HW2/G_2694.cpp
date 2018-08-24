#include<bits/stdc++.h>
using namespace std;

bitset<50> G[50];
int ans,n;

void meow(bitset<50> &cliq,bitset<50> other){
    // if(((double)clock())/CLOCKS_PER_SEC>=0.228)return;
    if(!other.count()){
        ans=max(ans,int(cliq.count()));
        return;
    }
    if((cliq|other).count()<=ans)return;
    int pivot=other._Find_first();
    bitset<50> cand=other&~G[pivot];
    for(register int i=cand._Find_first();i<n;i=cand._Find_next(i)){
        cliq[i]=1;
        meow(cliq,other&G[i]);
        cliq[i]=0;
        other[i]=0;
    }
}

int deg[50],id[50],vert[50];
void sol(){
    ans=0;
    memset(deg,0,sizeof(deg));
    memset(id,0,sizeof(id));
    memset(vert,0,sizeof(vert));
    for(int i=0;i<50;++i)G[i].reset();
    for(int i=0;i<n;++i){
        // for(int j=0;j<n;++j)G[i][j]=1;
        // G[i][i]=0;
        vert[i]=i;
    }
    // vector<pair<int,int>> bk(m);
    for(int i=0;i<n;++i)for(int j=0,t;j<n;++j)cin>>t,G[i][j]=t,deg[i]+=t,deg[j]+=t;
    /* while(m--){
        int u,v; scanf("%d%d",&u,&v);
        ++deg[u], ++deg[v];
        bk[m]={u,v};
    } */
    sort(vert,vert+n,[&](const int &a,const int &b){return deg[a]<deg[b];});
    for(int i=0;i<n;++i)id[vert[i]]=i;
    // random_shuffle(vert,vert+n);
    /* for(auto &i:bk){
        G[id[i.first]][id[i.second]]=G[id[i.second]][id[i.first]]=0;
    } */
    bitset<50> cliq,other;
    for(int i=0;i<n;++i)other[i]=1;
    meow(cliq,other);
    cout<<ans<<endl;
}

int main(){
    while(cin>>n,n)sol();
}
