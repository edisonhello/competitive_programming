#include<bits/stdc++.h>
using namespace std;

#ifdef WEAK
#include</home/edison/Coding/cpp/template/debug.cpp>
#else
#define PDE(...) ;
#endif

struct node{
    node *l,*r;
    long long tag,val;
    void push(int len){ l->tag+=tag; l->val+=tag*((len+1)>>1);
                        r->tag+=tag; r->val+=tag*((len  )>>1); tag=0; }
    void pull(){ val=l->val+r->val; }
    node():l(0),r(0),tag(0),val(0){}
} *root;

vector<int> G[100005];

int a[100005],in[100005],out[100005],dt,tid[100005],dep[100005],p[18][100005];

void dfs(int now,int pa,int d){
    dep[now]=d;
    in[now]=++dt;
    tid[dt]=now;
    p[0][now]=pa;
    for(int i=1;i<17;++i)p[i][now]=p[i-1][p[i-1][now]];
    for(int i:G[now])if(i!=pa)dfs(i,now,d+1);
    out[now]=dt;
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){ now->val=a[tid[l]]; return; }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->pull();
}
void modify(node *now,int l,int r,int ml,int mr,long long v){
    if(r<ml || mr<l)return;
    if(ml<=l && r<=mr){
        now->tag+=v;
        now->val+=v*(r-l+1);
        return;
    }
    now->push(r-l+1);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    now->pull();
}
long long query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    if(ql<=l && r<=qr)return now->val;
    now->push(r-l+1);
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

inline bool isanc(int u,int v){ // return if u is anc of v
    return in[u]<=in[v] && out[v]<=out[u];
}

int lca(int u,int v){
    if(isanc(u,v))return u;
    if(isanc(v,u))return v;
    for(int i=17;i>=0;--i){
        if(p[i][u] && !isanc(p[i][u],v))u=p[i][u];
    }
    return p[0][u];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1,1);
    build(root=new node(),1,n);
    int rt=1;
    while(q--){
        int c; cin>>c;
        if(c==1){
            int v; cin>>v;
            rt=v;
        }
        if(c==2){
            int u,v,x; cin>>u>>v>>x;
            int ist=int(isanc(rt,u))+int(isanc(rt,v));
            if(ist==2){
                int uv=lca(u,v);
                if(uv==rt)modify(root,1,n,1,n,x);
                else modify(root,1,n,in[uv],out[uv],x);
            }
            if(ist==1){
                modify(root,1,n,1,n,x);
            }
            if(ist==0){
                int ur=lca(u,rt);
                int vr=lca(v,rt);
                int uv=lca(u,v);
                v=[&](){
                    if(dep[uv]>=dep[ur] && dep[uv]>=dep[vr])return uv;
                    if(dep[ur]>=dep[uv] && dep[ur]>=dep[vr])return ur;
                    return vr;
                }();
                if(v==rt){
                    modify(root,1,n,1,n,x);
                }
                else if(isanc(v,rt)){
                    modify(root,1,n,1,n,x);
                    int urt=rt;
                    for(int i=17;i>=0;--i){
                        if(p[i][urt] && p[i][urt]!=v && isanc(v,p[i][urt]))urt=p[i][urt];
                    }
                    modify(root,1,n,in[urt],out[urt],-x);
                }
                else{
                    modify(root,1,n,in[v],out[v],x);
                }
            }
        }
        if(c==3){
#ifndef WEAK        
#define endl '\n'
#endif 
            int v; cin>>v;
            if(v==rt){
                cout<<root->val<<endl;
            }
            else if(isanc(v,rt)){
                int urt=rt;
                for(int i=17;i>=0;--i){
                    if(p[i][urt] && p[i][urt]!=v && isanc(v,p[i][urt]))urt=p[i][urt];
                }
                cout<<root->val-query(root,1,n,in[urt],out[urt])<<endl;
                // for(int i:G[v])if(isanc(i,rt) && dep[i]>dep[v])PDE(root->val,query(root,1,n,in[i],out[i]));
            }
            else{
                cout<<query(root,1,n,in[v],out[v])<<endl;
            }
        }
    }
}
