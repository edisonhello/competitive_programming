#include <bits/stdc++.h>
#define ll long long
#define norm(x) (((x)%mod+mod)%mod)

const ll mod=1000000000;
using namespace std;

vector<int> a;

ll fac[45];
void initfac(){
    fac[0]=1;
    for(int i=1;i<40;++i)fac[i]=fac[i-1]*i%mod;
}
struct node{
    node *l,*r;
    ll val;
    int cnt[40],tag,v;
    node(){
        l=r=0; val=0; tag=0;
        memset(cnt,0,sizeof(cnt));
    }
} *root;

void pull(node *now){
    now->val=(now->l->val+now->r->val)%mod;
    for(int i=0;i<40;++i)now->cnt[i]=now->l->cnt[i]+now->r->cnt[i];
}
#define m ((l+r)>>1)
void build(node *now,int l,int r){
    // cout<<"split interval "<<l<<" "<<r<<endl;
    if(l==r){
        now->v=a[l];
        if(a[l]>=40);
        else now->val=fac[a[l]],++now->cnt[a[l]];
        return;
    }
    build(now->l=new node(),l,m);
    build(now->r=new node(),m+1,r);
    pull(now);
    // cout<<"val for itv "<<l<<" "<<r<<" is "<<now->val<<endl;
}

void domove(node *now,int x,bool print_de=0){
    now->tag+=x; now->v+=x;
    for(int i=39;i>=0;--i){
        now->val=norm(now->val-fac[i]*now->cnt[i]+(i+x>40?0:fac[i+x])*now->cnt[i]);
        if(i+x<40)now->cnt[i+x]=now->cnt[i];
    }
    for(int i=0;i<min(40,x);++i)now->cnt[i]=0;
    /* if(print_de){
        cout<<now->cnt[1]<<" "<<now->cnt[2]<<" "<<now->cnt[3]<<" "<<now->cnt[15]<<endl;
    } */
}
void modify(node *now,int l,int r,int ml,int mr){
    if(ml<=l&&r<=mr){
        ++now->tag; ++now->v;
        for(int i=39;i>=0;--i){
            now->val=norm(now->val-fac[i]*now->cnt[i]+fac[i+1]*now->cnt[i]);
            if(i<39)now->cnt[i+1]=now->cnt[i];
        } now->cnt[0]=0;
        return;
    }
    if(r<ml || mr<l)return;
    if(now->tag){
        domove(now->l,now->tag);
        domove(now->r,now->tag);
        now->tag=0;
    }
    modify(now->l,l,m,ml,mr);
    modify(now->r,m+1,r,ml,mr);
    pull(now);
}
void modifyi(node *now,int l,int r,int x,int v){
    if(x<l || r<x)return;
    if(l==r){
        if(now->v<40)--now->cnt[now->v],now->val-=fac[now->v];
        now->v=v;
        if(now->v<40)++now->cnt[now->v],now->val+=fac[now->v];
        // cout<<l<<" "<<r<<" "<<now->val<<endl;
        return;
    }
    if(now->tag){
        bool print_de=(l==1 && r==2);
        domove(now->l,now->tag,print_de);
        domove(now->r,now->tag,print_de);
        now->tag=0;
    }
    modifyi(now->l,l,m,x,v);
    modifyi(now->r,m+1,r,x,v);
    pull(now);
    // cout<<l<<" "<<r<<" "<<now->val<<endl;
}
ll query(node *now,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return now->val;
    if(r<ql || qr<l)return 0;
    if(now->tag){
        domove(now->l,now->tag);
        domove(now->r,now->tag);
        now->tag=0;
    }
    return (query(now->l,l,m,ql,qr)+query(now->r,m+1,r,ql,qr))%mod;
}
#undef m

void solve(int n,int m){
    initfac();
    build(root=new node(),1,n);
    while(m--){
        int t,x,y; cin>>t>>x>>y;
        if(t==1){
            modify(root,1,n,x,y);
        }
        if(t==2){
            cout<<query(root,1,n,x,y)<<endl;
        }
        if(t==3){
            modifyi(root,1,n,x,y);
        }
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    a.resize(n+5);
    for(int A_i = 1; A_i <= n; A_i++){
       cin >> a[A_i];
    }
    solve(n,m);
    return 0;
}

