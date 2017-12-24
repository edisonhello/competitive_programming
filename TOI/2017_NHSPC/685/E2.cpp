#include<bits/stdc++.h>
using namespace std;

int n,djs[5005];
vector<int> G[5005];
vector<int> cont[5005];

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}

bitset<5005> sele;
int nowdeg[5005];
int meow(vector<int> &ct){
    for(int i:ct)nowdeg[i]=G[i].size(),sele[i]=1;
    for(int i:ct)for(int ii:G[i])assert(sele[ii]);
    int ans=0;
    while("meow"){
        int mndeg=9999,num;
        for(int i=1;i<=n;++i){
            if(sele[i] && nowdeg[i]<mndeg){
                mndeg=nowdeg[i];
                num=i;
            }
        }
        if(mndeg==9999)break;
        ans=max(ans,int(mndeg*sele.count()));
        sele[num]=0;
        for(int i:G[num]){
            if(sele[i])--nowdeg[i];
        }
    }
    assert(sele.count()==0);
    return ans;
}

int main(){
    int m; cin>>n>>m;
    for(int i=1;i<=n;++i)djs[i]=i;
    while(m--){
        int u,v; cin>>u>>v;
        U(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        cont[F(i)].push_back(i);
    }
    for(int i=1;i<=n;++i){
        if(cont[i].size()){
            ans=max(ans,meow(cont[i]));
        }
    }
    cout<<ans<<endl;
}
