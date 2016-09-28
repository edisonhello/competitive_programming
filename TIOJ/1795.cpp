#include<bits/stdc++.h>
using namespace std;
struct V{int dis,w;
friend bool operator < (const V &a,const V &b){return a.w<b.w;}
friend bool operator > (const V &a,const V &b){return a.w>b.w;}};

int n,m,k;
vector<V> G[100005];
int d[100005];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        G[v].push_back({u,c});
        G[u].push_back({v,c});
    }

    bool jizz=0;
    int mnk=0;
    {
        bitset<100005> v;
        memset(d,0x7f,sizeof(d));
        d[1]=0;
        int nodes=0;
        priority_queue<V,vector<V>,greater<V>> pq;
        pq.push({1,0});
        while(pq.size()){
            while(pq.size() && v[pq.top().dis]){
                pq.pop();
            }
            if(pq.empty())break;
            v[pq.top().dis]=1;
            int newp=pq.top().dis;
            mnk+=pq.top().w;
            nodes++;
            for(int i=0;i<(int)G[newp].size();i++){
                if(!v[G[newp][i].dis] && d[G[newp][i].dis]>G[newp][i].w){
                    d[G[newp][i].dis]=G[newp][i].w;
                    pq.push({G[newp][i].dis,d[G[newp][i].dis]});
                }
            }
        }
        if(nodes!=n) jizz=1;
    }
    // cout<<mnk<<endl;
    int mxk=0;
    {
        bitset<100005> v;
        memset(d,0xff,sizeof(d));
        d[1]=0;
        int nodes=0;
        priority_queue<V,vector<V>,less<V>> pq;
        pq.push({1,0});
        while(pq.size()){
            while(pq.size() && v[pq.top().dis]){
                pq.pop();
            }
            if(pq.empty())break;
            v[pq.top().dis]=1;
            int newp=pq.top().dis;
            mxk+=pq.top().w;
            nodes++;
            for(int i=0;i<(int)G[newp].size();i++){
                if(!v[G[newp][i].dis] && d[G[newp][i].dis]<G[newp][i].w){
                    d[G[newp][i].dis]=G[newp][i].w;
                    pq.push({G[newp][i].dis,d[G[newp][i].dis]});
                }
            }
        }
        if(nodes!=n) jizz=1;
    }
    // cout<<mxk<<endl;
    if(jizz){
        cout<<"NIE\n";
    }
    else if(mnk<=k && k<=mxk){
        cout<<"TAK\n";
    }
    else{
        cout<<"NIE\n";
    }
    // jizz?
}
