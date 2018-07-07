#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int mx,val,tag;
    node():l(0),r(0),mx(0),val(0),tag(0){}
} *root;

void clear(node *now){
    if(!now)return;
    clear(now->l);
    clear(now->r);
    delete now;
}

#define mid ((l+r)>>1)

void push(node *now,int l,int r){
    if(!now)return;
    if(!now->tag)return;
    if(!now->l)now->l=new node();
    if(!now->r)now->r=new node();
    now->l->tag=1;
    now->l->mx=1;
    now->l->val=mid-l+1;
    now->r->tag=1;
    now->r->mx=1;
    now->r->val=r-mid;
    now->tag=0;
}
void pull(node *now){
    now->val=(now->l?now->l->val:0)+(now->r?now->r->val:0);
}

void modify(node *&now,int l,int r,int ml,int mr,int v){
    if(r<ml || mr<l)return;
    if(!now)now=new node();
    if(ml<=l && r<=mr){
        now->tag=1;
        now->val=r-l+1;
        now->mx=1;
        return;
    }
    push(now,l,r);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    pull(now);
}

int query(node *now,int l,int r,int ql,int qr){
    if(!now)return 0;
    if(ql<=l && r<=qr)return now->val;
    if(qr<l || r<ql)return 0;
    push(now,l,r);
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

int l[10005],r[10005];

int main(){
    int ts; cin>>ts; while(ts--){
        clear(root),root=0;
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>l[i]>>r[i];
        int ans=0;
        /* set<pair<int,int>> st;
        st.insert({1,0});
        st.insert({10000001,1}); */
        for(int i=n;i>=1;--i){
            // auto it1=st.upper_bound({l[i],-1});
            
            int q=query(root,1,10000000,l[i],r[i]);
            if(q==r[i]-l[i]+1)continue;
            ++ans;
            modify(root,1,10000000,l[i],r[i],1);
        }
        cout<<ans<<endl;
    }
}
