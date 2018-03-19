#include<bits/stdc++.h>
using namespace std;
#define fmax fiii

struct edge{
    int u,v,f,c;
    // edge():u(0),v(0),f(0),c(0){}
};
vector<edge> edg;
vector<int> G[2222];

void ae(int u,int v,int f,int c){
    // cout<<"addedge "<<u<<" "<<v<<" "<<f<<" "<<c<<endl;
    G[u].push_back(edg.size());
    edg.push_back({u,v,f,c});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0,-c});
}

int cost[2222],fmax[2222],cfe[2222];
bitset<2222> inq;
bool go(int s,int t,int &ncost){
    memset(cost,0xb0,sizeof(cost)); cost[s]=0;
    memset(fmax,0,sizeof(fmax)); fmax[s]=0x3f3f3f3f;
    inq.reset();
    queue<int> q;
    q.push(s);
    while(q.size()){
        int now=q.front(); q.pop();
        // cout<<"now: "<<now<<endl;
        inq[now]=0;
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(e.f>0 && cost[e.v]<cost[now]+e.c){
                cost[e.v]=cost[now]+e.c;
                fmax[e.v]=min(fmax[now],e.f);
                cfe[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    if(!cost[t] || !fmax[t])return 0;
    ncost+=cost[t]*fmax[t];
    for(int u=t;u!=s;u=edg[cfe[u]].u){
        edg[cfe[u]].f-=fmax[t];
        edg[cfe[u]^1].f+=fmax[t];
    }
    return 1;
}

int flow(int s,int t){
    int cost=0;
    while(go(s,t,cost));
    return cost;
}

int s[1234],t[1234],c[1234],busy[66];
vector<int> weid;

int main(){
    int n,k; cin>>n>>k;
    vector<int> tpnt;
    for(int i=0;i<n;++i){
        cin>>s[i]>>t[i]>>c[i];
        tpnt.push_back(s[i]);
        tpnt.push_back(s[i]+t[i]);
    }
    sort(tpnt.begin(),tpnt.end());
    tpnt.resize(unique(tpnt.begin(),tpnt.end())-tpnt.begin());
    for(int i=1;i<tpnt.size();++i){
        ae(i-1,i,k,0);
    }
    ae(2000,0,k,0);
    ae(tpnt.size()-1,2001,k,0);
    for(int i=0;i<n;++i){
        int sp=lower_bound(tpnt.begin(),tpnt.end(),s[i])-tpnt.begin();
        int tp=lower_bound(tpnt.begin(),tpnt.end(),s[i]+t[i])-tpnt.begin();
        weid.push_back(edg.size());
        ae(sp,tp,1,c[i]);
    }
    flow(2000,2001);
    // cout<<flow(2000,2001)<<endl;
    for(int i=0;i<n;++i){
        int eid=weid[i];
        if(edg[eid].f==0){
            cout<<"1 ";
            continue;
            for(int j=1;j<=k;++j){
                if(busy[j]<=s[i]){
                    busy[j]=s[i]+t[i];
                    cout<<j<<" ";
                    break;
                }
            }
        }
        else cout<<"0 ";
    }
    cout<<endl;
}
