// UVa 753
int n,m,k;
map<string,int> msi;
struct edge{
    int u,v,cap;
    edge(int u,int v,int cap):u(u),v(v),cap(cap){};
};
vector<edge> edg;
vector<int> G[1111];

void clear(){
    msi.clear();
    edg.clear();
    for(int i=0;i<1111;++i)G[i].clear();
}

vector<int> d,se;
vector<bool> inq,v;
int flowwww(int &mxf){
    d.clear(), d.resize(1111);
    se.clear(), se.resize(1111);
    inq.clear(), inq.resize(1111);
    v.clear(), v.resize(1111);

    queue<int> q; q.push(0); d[0]=8787;
    while(q.size()){
        int x=q.front(); q.pop();
        PDE1(x);
        for(int edi:G[x]){
            if(edg[edi].cap<=0)continue;
            if(!inq[edg[edi].v]){
                d[edg[edi].v]=min(d[x],edg[edi].cap);
                se[edg[edi].v]=edi;
                q.push(edg[edi].v);
                inq[edg[edi].v]=1;
            }
        }
        if(d[777])break;
    }
    if(!d[777])return 0;
    for(int u=777;u;u=edg[se[u]].u){
        edg[se[u]].cap-=d[777];
        edg[se[u]^1].cap+=d[777];
    }
    return mxf+=d[777];
}
int flowww(){
    int ans=0;
    while(flowwww(ans));
    return ans;
}

int gid(string &s){
    int &id=msi[s];
    if(id==0)id=msi.size()+1;
    return id;
}

int main(){
    int ts; cin>>ts; while(ts--){
        clear();
        cin>>n; for(int i=0;i<n;++i){
            string s; cin>>s; int sid=gid(s);
            G[sid].push_back(edg.size());
            G[777].push_back(edg.size()+1);
            edg.push_back(edge(sid,777,1));
            edg.push_back(edge(777,sid,0));
        }
        cin>>m; for(int i=0;i<m;++i){
            string s,ss; cin>>s>>ss;
            int ssid=gid(ss);
            PDE3(i,ss,ssid);
            G[0].push_back(edg.size());
            G[ssid].push_back(edg.size()+1);
            edg.push_back(edge(0,ssid,1));
            edg.push_back(edge(ssid,0,0));
        }
        cin>>k; for(int i=0;i<k;++i){
            string s,ss; cin>>s>>ss;
            int sid=gid(s),ssid=gid(ss);
            G[sid].push_back(edg.size());
            G[ssid].push_back(edg.size()+1);
            edg.push_back(edge(sid,ssid,8787));
            edg.push_back(edge(ssid,sid,0));
        }
        cout<<m-flowww()<<endl;
        if(ts)cout<<endl;
    }
}
