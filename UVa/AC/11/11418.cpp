#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,f;
    string s;
};
vector<edge> edg;
vector<int> G[100];

void ae(int s,int t,int f,string st=""){
    // cout<<"ae "<<s<<" "<<t<<" "<<f<<" "<<st<<endl;
    G[s].push_back(edg.size());
    edg.push_back({s,t,f,st});
    G[t].push_back(edg.size());
    edg.push_back({t,s,0,st});
}

int bn[100],cf[100];
bitset<100> inq;
bool flow(int s,int t,int &cur){
    inq.reset(); inq[s]=1;
    queue<int> q; q.push(s);
    memset(bn,0,sizeof(bn)); bn[s]=0x3f3f3f3f;
    while(!bn[t] && q.size()){
        int now=q.front(); q.pop(); inq[now]=0;
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(bn[e.v]<min(bn[now],e.f)){
                bn[e.v]=min(bn[now],e.f);
                cf[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    if(!bn[t])return 0;
    cur+=bn[t];
    for(int u=t;u!=s;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[t];
        edg[cf[u]^1].f+=bn[t];
    }
    return 1;
}

int flow(int s,int t){
    int f=0;
    while(flow(s,t,f));
    return f;
}

int main(){
    int ts; cin>>ts; for(int ks=1;ks<=ts;++ks){
        int n; cin>>n;
        for(int i=0;i<100;++i)G[i].clear();
        for(int i=1;i<=n;++i){
            ae(0,i,1);
            ae(n+i,n+30,1);
            int c; cin>>c; while(c--){
                string s; cin>>s;
                ae(i,(s[0]|32)-'a'+n+1,1,s);
            }
        }
        int f=flow(0,n+30);
        // for(auto e:edg)cout<<"["<<e.u<<" "<<e.v<<" "<<e.f<<" "<<e.s<<"]"; cout<<endl;
        // cout<<"f: "<<f<<endl;
        cout<<"Case #"<<ks<<":\n";
        for(int i=0;i<n;++i){
            for(int eid:G[i+1+n]){
                // cout<<edg[eid].v<<" "<<edg[eid].s<<" "<<edg[eid].f<<endl;
                if(edg[eid].v==n+30)continue;
                if(edg[eid].f){
                    // cout<<"in"<<endl;
                    for(char &c:edg[eid].s)c|=32;
                    edg[eid].s[0]&=(1<<8)-1-32;
                    cout<<edg[eid].s<<'\n';
                }
            }
        }
    }
}
