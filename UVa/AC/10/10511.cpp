#include<bits/stdc++.h>
using namespace std;

int ptr;
int gid(map<string,int> &mp,string &str){
    auto &it=mp[str];
    if(it==0)return it=++ptr;
    else return it;
}

struct info{
    int pp,par;
    vector<int> clu;
};

struct edge{
    int u,v,f;
};

vector<edge> edg;
vector<int> G[12000];

void ae(int u,int v,int f){
    // cout<<"add edge "<<u<<" "<<v<<" "<<f<<endl;
    G[u].push_back(edg.size());
    edg.push_back({u,v,f});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0});
}

bitset<12000> inq;
int cf[12000],bn[12000];

bool flow(int s,int t,int &cur){
    memset(bn,0,sizeof(bn)); bn[s]=0x3f3f3f3f;
    inq.reset(); inq[s]=1;
    queue<int> q; q.push(s);
    while(q.size() && !bn[t]){
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
    for(int u=t;u!=s;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[t];
        edg[cf[u]^1].f+=bn[t];
    }
    cur+=bn[t];
    return 1;
}

int flow(int s,int t){
    int f=0;
    while(flow(s,t,f));
    return f;
}

int pple_id[1111];
string clb_get[12000],nam_get[12000];

int main(){
    int t; cin>>t;
    cin.ignore(); cin.ignore();
    while(t--){
        map<string,int> people,party,club;
        map<int,int> cl_id;
        vector<info> p;
        ptr=1;
        edg.clear();
        for(int i=0;i<12000;++i)G[i].clear();
        string s; while(getline(cin,s)){
            if(s=="")break;
            stringstream ss(s);
            string name,pty,cls;
            ss>>name>>pty;
            int pid=gid(people,name);
            int prid=gid(party,pty);
            vector<int> tmp;
            while(ss>>cls){
                tmp.push_back(gid(club,cls));
            }
            p.push_back({pid,prid,tmp});
        }
        for(auto &ps:people)nam_get[ps.second]=ps.first;
        for(auto &pr:club)ae(0,pr.second,1),clb_get[pr.second]=pr.first;

        // for(auto ps:people)cout<<"people "<<ps.first<<" -> "<<ps.second<<endl;
        // for(auto ps:party)cout<<"party "<<ps.first<<" -> "<<ps.second<<endl;
        // for(auto ps:club)cout<<"club "<<ps.first<<" -> "<<ps.second<<endl;

        vector<int> track;
        for(auto &ps:p){
            for(int clb:ps.clu){
                track.push_back(edg.size());
                ae(clb,ps.pp,1);
            }
            ae(ps.pp,ps.par,1);
        }
        int __max=(club.size()+1)/2-1;
        for(auto &pr:party)ae(pr.second,1,__max);
        // cout<<"b4 flow"<<endl;
        int mflow=flow(0,1);
        /* cout<<"mflow: "<<mflow<<endl;
        cout<<"clubz: "<<club.size()<<endl; */
        if(mflow!=int(club.size()))cout<<"Impossible."<<'\n';
        else{
            for(auto &eid:track){
                if(edg[eid].f==0){
                    cout<<nam_get[edg[eid].v]<<" "<<clb_get[edg[eid].u]<<'\n';
                }
            }
        }
        if(t)cout<<endl;
    }
}
