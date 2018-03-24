#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;

// #include"/home/edison/Coding/cpp/template/debug.cpp"
#define PDE(...) ;

struct segtree{
    struct node{
        node *l,*r;
        int val;
        node(int val=0x3f3f3f3f):l(0),r(0),val(val){}
    } *root;
    void pull(node *now){
        now->val=min(now->l->val,now->r->val);
    }
#define mid ((l+r)>>1)
    int l,r;
    void build(node *now,int l,int r){
        if(l==r)return;
        build(now->l=new node(),l,mid);
        build(now->r=new node(),mid+1,r);
    }
    void rebuild(node *now,int l,int r){
        now->val=0x3f3f3f3f;
        if(l==r)return;
        rebuild(now->l,l,mid);
        rebuild(now->r,mid+1,r);
    }
    void modify(node *now,int l,int r,int x,int v){
        if(l==r){
            now->val=min(now->val,v);
            return;
        }
        if(x<=mid)modify(now->l,l,mid,x,v);
        else modify(now->r,mid+1,r,x,v);
        pull(now);
    }
    int query(node *now,int l,int r,int ql,int qr){
        if(qr<l || r<ql)return 0x3f3f3f3f;
        if(ql<=l&&r<=qr)return now->val;
        return min(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
    }
    int query(int ql,int qr){
        return query(root,l,r,ql,qr);
    }
    void modify(int x,int v){
        modify(root,l,r,x,v);
    }
    void rebuild(){
        rebuild(root,l,r);
    }
    segtree(int l,int r):l(l),r(r){
        build(root=new node(),l,r);
    }
    /* void kill(node *now){
        if(now->l)kill(now->l);
        if(now->r)kill(now->r);
        delete now;
    } */
    /* ~segtree(){
        kill(root);
    } */
} tree(0,200005);

struct BIT{
#define lb(x) ((x)&-(x))
    int bit[200005];
    void add(int x,int v){
        for(;x<200005;x+=lb(x))bit[x]=max(bit[x],v);
    }
    int query(int x,int v=0){
        for(;x;x-=lb(x))v=max(v,bit[x]);
        return v;
    }
    void init(){
        memset(bit,0,sizeof(bit));
    }
    BIT(){
        init();
    }
#undef lb
} bit;

#define left lellelel
int w[100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
        int n; cin>>n;
        vector<pair<int,pair<int,int>>> segs(n);
        vector<int> num;
        for(int i=0;i<n;++i){
            cin>>segs[i].second.first>>segs[i].second.second>>w[i]; ++segs[i].second.first;
            num.push_back(segs[i].second.first);
            num.push_back(segs[i].second.second);
            // assert(segs[i].second.first<=segs[i].second.second);
            segs[i].first=i;
        }
        sort(num.begin(),num.end());
        for(int ii=0;ii<n;++ii){
            auto &i=segs[ii];
            i.second.first=lower_bound(num.begin(),num.end(),i.second.first)-num.begin()+1;
            i.second.second=lower_bound(num.begin(),num.end(),i.second.second)-num.begin()+1;
        }
        bit.init();
        segtree tree(0,200005);
        tree.modify(0,0);
        sort(segs.begin(),segs.end(),[](const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){return a.second.second==b.second.second?a.second.first<b.second.first:a.second.second<b.second.second;});
        for(auto seg:segs){
            int left=bit.query(seg.second.first-1);
            bit.add(seg.second.second,seg.second.first);
            int mn=tree.query(left,seg.second.second);
            tree.modify(seg.second.second,mn+w[seg.first]);
            PDE(seg,mn,w[seg.first]);
        }
        cout<<tree.query(bit.query(200002),200004)<<'\n';
    }
}
