#include<bits/stdc++.h>
using namespace std;

bool print;
struct Edge {
    int to, rev, cap;
    Edge() {}
    Edge(int a, int b, int c): to(a), cap(b), rev(c) {}
};
vector<Edge> G[600010];
struct Dinic {
    static const int maxn=600010;
    int n, s, t;
    vector<int> level;
    bool bfs() {
        level.assign(n, -1);
        level[s] = 0; 
        queue<int> que; que.push(s);
        while (que.size()) {
            int tmp = que.front(); que.pop();
            for (auto e : G[tmp]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[tmp] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    int flow(int now, int low) {
        if (now == t) return low;
        int ret = 0;
        for (auto &e : G[now]) {
            if (e.cap > 0 && level[e.to] == level[now] + 1) {
                int tmp = flow(e.to, min(e.cap, low - ret));
                e.cap -= tmp; G[e.to][e.rev].cap += tmp;
                ret += tmp;
            }
        }
        if (ret == 0) level[now] = -1;
        return ret;
    }
    Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
        fill(G, G + maxn, vector<Edge>());
    }
    void add_edge(int a, int b, int c) {
        // if(print)cout<<"addedge: "<<a<<" "<<b<<" "<<c<<endl;
        G[a].push_back(Edge(b, c, G[b].size()));
        G[b].push_back(Edge(a, 0, G[a].size() - 1));
    }
    int maxflow() {
        int ret = 0;
        while (bfs()) ret += flow(s, 1000000000);
        return ret;
    }
    void solve(){
        cout<<maxflow()<<endl;
        bitset<300001> x,y;
        vector<int> newpt,prv;
        for(auto e:G[s])if(e.cap==1)x[e.to]=1,prv.push_back(e.to);
        // cout<<"x choose: "; for(int i:prv)if(i<3)cout<<i<<" "; cout<<endl;
        while(prv.size()){
            if(prv[0]<=300000){
                // go unmatch edges
                for(int i:prv){
                    for(auto e:G[i]){
                        if(e.to>=300001 && e.to<=600001 && e.cap==1 && !y[e.to-300001]){
                            newpt.push_back(e.to);
                            y[e.to-300001]=1;
                        }
                    }
                }
            }
            else{
                // go match edge
                for(int i:prv){
                    // cout<<"edges from "<<i<<" : ";
                    for(auto e:G[i]){
                        // cout<<"("<<e.to<<","<<e.cap<<")";
                        if(e.to<=300000 && e.cap==1 && !x[e.to]){
                            newpt.push_back(e.to);
                            x[e.to]=1;
                        }
                    }
                    // cout<<endl;
                }
            }
            prv.clear();
            swap(newpt,prv);
            // cout<<"newpt: "; for(int i:prv)cout<<i<<" "; cout<<endl;
        }
        x.flip();
        cout<<x.count()<<endl;
        for(int i=0;i<=300000;++i)if(x[i])cout<<i<<" "; cout<<endl;
        cout<<y.count()<<endl;
        for(int i=0;i<=300000;++i)if(y[i])cout<<i<<" "; cout<<endl;
    }
};

struct e{
    int l,r,type;
};
vector<e> v[300005];

struct node{
    node *l,*r;
    int val,tag;
    node():l(0),r(0),val(0),tag(0){}
} *root;

void push(node *now){
    if(!now || !now->l || !now->tag)return;
    now->l->val+=now->tag;
    now->l->tag+=now->tag;
    now->r->val+=now->tag;
    now->r->tag+=now->tag;
    now->tag=0;
}
void pull(node *now){
    now->val=max(now->l->val,now->r->val);
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int ml,int mr,int v){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr){
        now->tag+=v;
        now->val+=v;
        return;
    }
    push(now);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    pull(now);
}
void go(node *now,int l,int r,int x,Dinic &flow){
    if(l==r && now->val>0){
        flow.add_edge(x,l+300001,1);
        return;
    }
    if(!now->val)return;
    push(now);
    go(now->l,l,mid,x,flow);
    go(now->r,mid+1,r,x,flow);
}


int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        v[x1].push_back({y1,y2,1});
        v[x2+1].push_back({y1,y2,-1});
    }
    build(root=new node(),0,300000);
    // Dinic flow;
    Dinic flow(600005,600002,600003);
    for(int i=0;i<=300000;++i){
        flow.add_edge(600002,i,1);
        flow.add_edge(i+300001,600003,1);
    }
    print=1;
    for(int i=0;i<=300000;++i){
        for(e ee:v[i])modify(root,0,300000,ee.l,ee.r,ee.type);
        go(root,0,300000,i,flow);
    }
    flow.solve();
}
