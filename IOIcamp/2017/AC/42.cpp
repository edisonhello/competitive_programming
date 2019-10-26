#include<queue>
#include<iostream>
#include<vector>
using namespace std;

struct eg{int a,c;};
bool operator>(const eg &a,const eg &b){return a.c>b.c;}

int d[100005];
bool v[100005];
vector<int> G[100005];
priority_queue<eg,vector<eg>,greater<eg>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    int ts,n,m,a,b;
    cin>>ts;while(ts--){
        cin>>n>>m>>a>>b;

        while(pq.size())pq.pop();
        for(int i=1;i<=n;++i){
            v[i]=0;
            d[i]=b;
            G[i].clear();
        }

        {int u,v;while(m--){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }}

        d[1]=0;
        pq.push({1,0});
        while(pq.size()){
            while(pq.size() && v[pq.top().a])pq.pop();

            if(pq.empty())break;
            v[pq.top().a]=1;
            if(pq.top().c>=b)break;

            for(int i=0;i<(int)G[pq.top().a].size();++i){
                if(!v[G[pq.top().a][i]] && d[G[pq.top().a][i]] > d[pq.top().a]+a){
                    d[G[pq.top().a][i]]=d[pq.top().a]+a;
                    pq.push({G[pq.top().a][i],d[G[pq.top().a][i]]});
                }
            }
        }
        for(int i=1;i<=n;++i){
            if(i-1)cout<<" ";
            cout<<d[i];
        }cout<<endl;
    }
}
