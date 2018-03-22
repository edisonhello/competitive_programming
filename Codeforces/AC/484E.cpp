#include<bits/stdc++.h>
using namespace std;

// #include"/home/edison/Coding/cpp/template/debug.cpp"
#define PDE(...) ;

struct sol{
    int la,ra,ans,len;
    sol():la(0),ra(0),ans(0),len(0){}
    int set(int v){la=ra=ans=v;}
};
sol operator+(const sol &a,const sol &b){
    sol rt;
    rt.ans=max(a.ans,b.ans);
    rt.la=a.la;
    if(a.la==a.len)rt.la+=b.la;
    rt.ra=b.ra;
    if(b.ra==b.len)rt.ra+=a.ra;
    rt.len=a.len+b.len;
    rt.ans=max(rt.ans,max(rt.la,rt.ra));
    rt.ans=max(rt.ans,a.ra+b.la);
    return rt;
}
struct node{
    node *l,*r;
    sol ans;
    node():l(0),r(0){}
} *root;

#define mid ((l+r)>>1)
void pull(node *now){
    now->ans=now->l->ans+now->r->ans;
}
void build(node *now,int l,int r){
    if(l==r){
        now->ans.len=1;
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->ans.len=r-l+1;
}
void add(node *now,int l,int r,int x){
    if(l==r){
        now->ans.set(1);
        return;
    }
    if(x<=mid)add(now->l,l,mid,x);
    else add(now->r,mid+1,r,x);
    pull(now);
}
void remove(node *now,int l,int r,int x){
    if(l==r){
        now->ans.set(0);
        return;
    }
    if(x<=mid)remove(now->l,l,mid,x);
    else remove(now->r,mid+1,r,x);
    pull(now);
}
sol query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return sol();
    if(ql<=l&&r<=qr)return now->ans;
    auto la=query(now->l,l,mid,ql,qr),ra=query(now->r,mid+1,r,ql,qr);
    return la+ra;
}

struct Q{
    int l,r,w,i;
};
int n;
int h[100005],ans[100005];
vector<pair<int,int>> num;

void what(int l,int r,vector<Q> &qs){
    if(l>r)return;
    PDE("what",l,r);
    int m=(l+r)>>1;
    for(int i=l;i<=m;++i){
        PDE("add",num[i]);
        add(root,1,n,num[i].second);
    }
    vector<Q> lq,rq;
    for(auto q:qs){
        PDE("doq ",q.l,q.r,q.w,query(root,1,n,q.l,q.r).ans);
        if(query(root,1,n,q.l,q.r).ans>=q.w)ans[q.i]=num[m].first,lq.push_back(q);
        else rq.push_back(q);
    }
    for(int i=l;i<=m;++i){
        PDE("remove",num[i]);
        remove(root,1,n,num[i].second);
    }
    if(m!=r)what(l,m,lq);
    for(int i=l;i<=m;++i){
        PDE("add",num[i]);
        add(root,1,n,num[i].second);
    }
    if(m!=r)what(m+1,r,rq);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n; 
    for(int i=1;i<=n;++i)cin>>h[i],num.emplace_back(h[i],i);
    sort(num.begin(),num.end()); reverse(num.begin(),num.end());
    int m; cin>>m;
    build(root=new node(),1,n);
    vector<Q> qs(m);
    for(int i=0;i<m;++i){
        int l,r,w; cin>>l>>r>>w;
        qs[i]={l,r,w,i};
    }
    what(0,n-1,qs);
    for(int i=0;i<m;++i){
        cout<<ans[i]<<endl;
    }
}
