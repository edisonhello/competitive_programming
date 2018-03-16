#include<bits/stdc++.h>
using namespace std;

int djs[100005];
vector<int> spG[100005],ptG[100005];
int spin[100005],spot[100005],ptcon[100005];
int timer=0;
bitset<100005> ans,ptv;
vector<int> rts;

set<int> part;
struct Q{
    int x,i;
};
vector<Q> qs[100005];

void spdfs(int now){
    spin[now]=++timer;
    for(int i:spG[now])spdfs(i);
    spot[now]=++timer;
}

set<int>* dfs(int now,set<int> *exi){
    ptv[now]=1;
    vector<set<int>*> v; v.push_back(new set<int>());
    v.back()->insert(now);
    for(int i:spG[now]){
        v.push_back(dfs(i,exi));
    }
    set<int>* it=*v.begin();
    for(auto iit:v){
        if(iit->size()>it->size())it=iit;
    }
    for(auto iit:v){
        if(iit==it)continue;
        for(int i:*iit){
            it->insert(i);
        }
        delete iit;
    }
    for(auto q:qs[now]){
        ans[q.i]=(djs[now]==now && exi->find(q.x)!=exi->end());
    }
    if(ptG[now].size()){
        if(now==djs[now]){
            for(int i:*it)exi->insert(i);
            for(int i:ptG[now])dfs(i,exi);
            for(int i:*it)exi->erase(i);
        }
        else{
            for(int i:ptG[now])dfs(i,it);
        }
    }
    return it;
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=n;++i){
        int par,typ; cin>>par>>typ;
        if(par==-1){
            rts.push_back(i);
        }
        else if(typ==0){
            djs[i]=djs[par];
            spG[par].push_back(i);
        }
        else{
            ptcon[i]=par;
            rts.push_back(i);
        }
    }
    for(int i=1;i<=n;++i){
        if(djs[i]!=i)continue;
        spdfs(i);
    }

    int q; cin>>q;
    for(int i=1;i<=q;++i){
        int x,a,b; cin>>x>>a>>b;
        if(x==1){
            if(djs[a]==djs[b] && spin[a]<spin[b] && spot[b]<spot[a])ans[i]=1;
        }
        else{
            qs[b].push_back({a,i});
        }
    }

    for(int i:rts){
        while(1){
            if(!ptcon[i])break;
            ptG[ptcon[i]].push_back(i);
            // cout<<"ptG generate edge: "<<ptcon[i]<<" to "<<i<<endl;
            int tmp=ptcon[i]; ptcon[i]=0;
            if(djs[tmp]==tmp)i=tmp;
            else break;
        }
    }

    for(int i=1;i<=n;++i){
        if(!ptv[i]){
            // cout<<"ptdfs start! from "<<i<<endl;
            dfs(i,new set<int>());
        }
    }

    for(int i=1;i<=q;++i){
        if(ans[i])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
