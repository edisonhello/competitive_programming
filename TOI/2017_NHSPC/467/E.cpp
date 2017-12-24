#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;

int djs[5005];
vector<int> G[5005];
vector<int> cont[5005];

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}

int nowdeg[5005];
__gnu_pbds::detail::left_child_next_sibling_heap_node_point_const_iterator_<__gnu_pbds::detail::left_child_next_sibling_heap_node_<std::pair<int, int>, __gnu_pbds::null_type, std::allocator<char> >, std::allocator<char> > it[5005];
int meow(vector<int> &ct){
    __gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>> pq;
    memset(nowdeg,0,sizeof(nowdeg));
    for(int i:ct)it[i]=pq.push({G[i].size(),i}),nowdeg[i]=G[i].size();

    int ans=pq.top().first*pq.size();
    bitset<5005> outset;
    while(pq.size()){
        while(pq.size() && outset[pq.top().second])pq.pop();
        if(pq.empty())break;
        auto i=pq.top(); pq.pop();
        outset[i.second]=1;
        for(int ii:G[i.second]){
            if(outset[ii])continue;
            --nowdeg[ii];
            pq.modify(it[ii],{nowdeg[ii],ii});
        }
        ans=max(ans,pq.empty()?0:int(pq.top().first*pq.size()));
    }
    return ans;
}

int main(){
    int n,m; cin>>n>>m;
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
