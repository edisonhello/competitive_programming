#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,f;
};

vector<edge> edg;
vector<int> G[111],fG[777];
int ind[111],outd[111],need[111];

void ae(int u,int v,int f){
    // cout<<"flow edge: "<<u<<" "<<v<<" "<<f<<endl;
    fG[u].push_back(edg.size());
    edg.push_back({u,v,f});
    fG[v].push_back(edg.size());
    edg.push_back({v,u,0});
}

int bn[777],cf[777];
bitset<777> inq;
bool flow(int s,int t,int &nf){
    queue<int> q; q.push(s);
    inq.reset(); inq[s]=1;
    memset(bn,0,sizeof(bn)); bn[s]=0x3f3f3f3f;
    while(!bn[t] && q.size()){
        int now=q.front(); q.pop(); inq[now]=0;
        // cout<<"now: "<<now<<endl;
        for(int ei:fG[now]){
            edge &e=edg[ei];
            if(e.f && bn[e.v]<min(bn[e.u],e.f)){
                bn[e.v]=min(bn[e.u],e.f);
                cf[e.v]=ei;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    if(!bn[t])return 0;
    nf+=bn[t];
    for(int u=t;u!=s;u=edg[cf[u]].u){
        // cout<<"u: "<<u<<endl;
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

vector<int> ans;
int e_ptr[111];
void dfs(int now){
    // cout<<"dfs: "<<now<<endl;
    for(++e_ptr[now];e_ptr[now]<G[now].size();++e_ptr[now]){
        dfs(G[now][e_ptr[now]]);
    }
    ans.push_back(now);
}

int main(){
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        for(int i=0;i<111;++i)G[i].clear();
        for(int i=0;i<777;++i)fG[i].clear();
        memset(ind,0,sizeof(ind));
        memset(outd,0,sizeof(outd));
        vector<pair<int,int>> bi;
        for(int i=0;i<m;++i){
            int u,v; char c; cin>>u>>v>>c;
            if(c=='U'){
                bi.emplace_back(v,u);
                ++ind[u]; ++outd[v];
            }
            else{
                G[v].push_back(u);
                ++ind[u]; ++outd[v];
            }
        }
        bool over=0;
        for(int i=1;i<=n;++i){
            if((ind[i]+outd[i])&1){
                cout<<"No euler circuit exist\n";
                over=1;
                if(t)cout<<endl;
                break;
            }
            need[i]=ind[i]-outd[i];
            // cout<<"in out of "<<i<<" : "<<ind[i]<<" "<<outd[i]<<endl;
        }
        if(over)continue;
        int demend=0;
        for(int i=1;i<=n;++i){
            if(need[i]==0)continue;
            if(need[i]>0)ae(0,i,need[i]/2),demend+=need[i]/2;
            if(need[i]<0)ae(i,n+1,-need[i]/2);
        }
        vector<int> track;
        for(auto i:bi){
            track.push_back(edg.size());
            // cout<<"flow edge from "<<i.second<<" to "<<i.first<<endl;
            ae(i.second,i.first,1);
        }
        // cout<<"b4 flow"<<endl;
        if(flow(0,n+1)!=demend){
            cout<<"No euler circuit exist\n";
            over=1;
            if(t)cout<<endl;
        }
        // cout<<"af flow"<<endl;
        if(over)continue;
        for(int eid:track){
            edge &e=edg[eid];
            if(e.f){
                G[e.v].push_back(e.u);
                // cout<<"new edge "<<e.v<<" "<<e.u<<endl;
            }
            else{
                
                G[e.u].push_back(e.v);
                // cout<<"new edge "<<e.v<<" "<<e.u<<" ( reversed )"<<endl;
            }
        }
        /* cout<<"graph: \n";
        for(int i=1;i<=n;++i){
            cout<<i<<": ";
            for(int ii:G[i])cout<<ii<<" ";
            cout<<endl;
        } */
        ans.clear();
        memset(e_ptr,0xff,sizeof(e_ptr));
        dfs(1);
        if(ans.size()!=m+1){
            cout<<"No euler circuit exist\n";
            over=1;
            if(t)cout<<endl;
        }
        if(over)continue;
        for(int i=0;i<ans.size();++i)cout<<ans[i]<<" \n"[i==ans.size()-1];
        if(t)cout<<endl;
    }
}
