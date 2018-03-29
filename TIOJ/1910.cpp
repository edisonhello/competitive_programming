#include<bits/stdc++.h>
using namespace std;

#include"/home/edison/Coding/cpp/template/debug.cpp"
// #define PDE(...) ;

void _exit(int ext_id){cout<<"Exit code "<<ext_id<<".\n"; exit(ext_id);}

struct edge{int to,w;};
struct BCC_edge{int to,to_id,w;};
struct PQ_edge{int u,v,w;};

bool operator>(const PQ_edge &a,const PQ_edge &b){return a.w>b.w;}

struct segtree{
    struct node{
        node *l,*r;
        int mx;
        node(int v=0):l(0),r(0),mx(v){}
    } *root;
    int L,R;
#define mid ((l+r)>>1)
    void build(node *now,int l,int r){
        if(l==r)return;
        build(now->l=new node(),l,mid);
        build(now->r=new node(),mid+1,r);
    }
    void modify(node *now,int l,int r,int ml,int mr,int v){
        
    }
    void modify(int x,int y,int v){
        modify(node,L,R,x,y,v);
    }
    segtree(int l,int r):L(l),R(r){
        build(root=new node(),L,R);
    }
};

int n,m,q;
vector<edge> G[100005],MST_G[100005];
vector<BCC_edge> BCC_G[100005];
vector<int> BCC_member[100005];

int tarjan_dfs_in[100005],tarjan_dfs_low[100005],tarjan_dfs_now;
stack<int> tarjan_stack;

int BCC_belong[100005],BCC_count;

priority_queue<PQ_edge,vector<PQ_edge>,greater<PQ_edge>> MST_candi[100005];
int disjoint_set[100005];

int MST_dep[100005],MST_pa[17][100005],MST_max[17][100005];

int TREE_sz[100005],TREE_son_mx[100005],TREE_mx_to[100005];
int chain_count,chain_number[100005],inchain_pos[100005],chain_pa[100005];

int BCC_go_up_id[100005];
BCC_edge BCC_edge_up[100005];

int djs_F(int u){return disjoint_set[u]==u?u:disjoint_set[u]=djs_F(disjoint_set[u]);}
void djs_U(int u,int v){disjoint_set[djs_F(u)]=djs_F(v);}
bool djs_C(int u,int v){return djs_F(u)==djs_F(v);}

void tarjan(int now,int pa){
    tarjan_dfs_in[now]=++tarjan_dfs_now;
    tarjan_dfs_low[now]=tarjan_dfs_now;
    tarjan_stack.push(now);

    for(auto i:G[now]){
        if(i.to==pa)continue;
        if(tarjan_dfs_in[i.to]){
            tarjan_dfs_low[now]=min(tarjan_dfs_low[now],tarjan_dfs_in[i.to]);
        }
        else{
            tarjan(i.to,now);
            tarjan_dfs_low[now]=min(tarjan_dfs_low[now],tarjan_dfs_low[i.to]);
        }
    }

    if(tarjan_dfs_low[now]>=tarjan_dfs_in[now]){
        ++BCC_count;
        while(tarjan_stack.size()){
            int top=tarjan_stack.top(); tarjan_stack.pop();
            BCC_belong[top]=BCC_count;
            BCC_member[BCC_count].push_back(top);
            if(top==now)break;
        }
    }
}

void MST_dfs(int now,int pa,int dep=1){
    MST_pa[0][now]=pa;
    MST_dep[now]=dep;
    for(int i=1;i<17;++i){
        MST_pa[i][now]=MST_pa[i-1][MST_pa[i-1][now]];
        MST_max[i][now]=max(MST_max[i-1][now],MST_max[i-1][MST_pa[i-1][now]]);
    }
    for(edge e:MST_G[now]){
        if(e.to==pa)continue;
        MST_max[0][e.to]=e.w;
        MST_dfs(e.to,now,dep+1);
    }
}

void TREE_dfs1(int now,int pa){
    TREE_sz[now]=1;
    for(BCC_edge edg:BCC_G[now]){
        if(edg.to==pa){
            BCC_go_up_id[now]=edg.to_id;
        }

        TREE_dfs1(edg.to,now);
        TREE_sz[now]+=TREE_sz[edg.to];
        if(TREE_sz[edg.to]>TREE_son_mx[now]){
            TREE_son_mx[now]=TREE_sz[edg.to];
            TREE_mx_to[now]=edg.to;
        }
    }
}

void TREE_decom(int now,int pa,int _chain_number,int _inchain_pos){
    chain_number[now]=_chain_number;
    inchain_pos[now]=_inchain_pos;
    for(BCC_edge edg:BCC_G[now]){
        if(edg.to==pa){
            BCC_edge_up[now]=edg;
        }
        if(edg.to==TREE_mx_to[now]){
            BCC_edge_up[edg.to]=edg;
            TREE_decom(edg.to,now,_chain_number,_inchain_pos+1);
        }
        else{
            BCC_edge_up[edg.to]=edg;
            chain_pa[++chain_count]=now;
            TREE_decom(edg.to,now,chain_count,1);
        }
    }
}

int MST_query(int u,int v){
    if(BCC_belong[u]!=BCC_belong[v])_exit(401);
    if(u==v)return -(1<<30);
    if(MST_dep[u]>MST_dep[v])swap(u,v);
    int mx=-(1<<30);
    for(int i=0;i<17;++i)if((MST_dep[v]-MST_dep[u])&(1<<i)){
        mx=max(mx,MST_max[i][v]);
        v=MST_pa[i][v];
    }
    if(u==v)return mx;
    for(int i=16;i>=0;--i){
        if(MST_pa[i][u]!=MST_pa[i][v]){
            mx=max(mx,max(MST_max[i][u],MST_max[i][v]));
            u=MST_pa[i][u];
            v=MST_pa[i][v];
        }
    }
    return max(mx,max(MST_max[0][u],MST_max[0][v]));
}

int main(){
    // 1 base
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i=1;i<=100000;++i)disjoint_set[i]=i;

    cin>>n>>m>>q;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        ++u, ++v;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    tarjan(1,1);

    for(int i=1;i<=n;++i){
        for(auto j:G[i]){
            if(BCC_belong[i]==BCC_belong[j.to]){
                MST_candi[BCC_belong[i]].push({i,j.to,j.w});
            }
            else{
                BCC_G[BCC_belong[i]].push_back({BCC_belong[j.to],j.to,j.w});
                BCC_G[BCC_belong[j.to]].push_back({BCC_belong[i],i,j.w});
            }
        }
    }

    for(int i=1;i<=BCC_count;++i){
        while(MST_candi[i].size()){
            PQ_edge edg=MST_candi[i].top(); MST_candi[i].pop();
            if(djs_C(edg.u,edg.v))continue;
            djs_U(edg.u,edg.v);
            MST_G[edg.u].push_back({edg.v,edg.w});
            MST_G[edg.v].push_back({edg.u,edg.w});
        }
        MST_dfs(BCC_member[i][0],BCC_member[i][0]);
    }

    TREE_dfs1(1,1);
    TREE_decom(1,1,++chain_count,1);


}
