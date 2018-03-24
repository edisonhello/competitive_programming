#pragma GCC optimize("no-stack-protector,Ofast")
#include<cstdio>

using namespace std;
#define lb(x) ((x)&-(x))
#define getchar getchar_unlocked

#define int unsigned int

const int maxn=20005;

int a[maxn],k,n,nowleaf,ans,ptr;
bool no;

void dfs(int lb,int ub){
    if(no || nowleaf>k){return;}
    if(nowleaf==k)++ans;
    int val=a[ptr]; ++ptr;
    if(ptr>n)return;
    if(a[ptr]<lb){no=1; return;}
    if(a[ptr]>ub)return;
    bool subed=0;
    if(a[ptr]<val){
        subed=1;
        dfs(lb,val);
    }

    if(nowleaf>k)return;
    if(ptr>n)return;
    if(a[ptr]<lb){no=1; return;}
    if(a[ptr]>ub)return;
    if(a[ptr]>val){
        if(subed)++nowleaf;
        dfs(val,ub);
    }
    else no=1;
}

inline int gint(){
    register char c; register int x=0;
    while((c=getchar()) && (c<'0' || c>'9'));
    do x=x*10+(c&15); while((c=getchar())>='0' && c<='9');
    return x;
}

struct node{
    node *l,*r;
    int mn,mx;
    node(int v=0):l(0),r(0),mx(v),mn(v){}
} *root;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        now->mx=now->mn=v;
    }
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
    now->mx=max(now->l->mx,now->r->mx);
    now->mn=min(now->l->mn,now->r->mn);
}
int qmax(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return -(1<<30);
    if(ql<=l && r<=qr)return now->mx;
    return max(qmax(now->l,l,mid,ql,qr),qmax(now->r,mid+1,r,ql,qr));
}
int qmin(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 1<<30;
    if(ql<=l && r<=qr)return now->mn;
    return min(qmin(now->l,l,mid,ql,qr),qmin(now->r,mid+1,r,ql,qr));
}

void special(int n){
    int r=n;
    long long ans=1;
    build(root,1,n);
    modify(root,1,n,n,a[n]);
    for(int i=n-1;i>=1;--i){
        if(a[i+1]>a[i]){
            int mn=qmin(root,1,n,i+1,r);
            if(mn)
        }
    }
}

main(){
    n=gint(); k=gint();
    for(int i=1;i<=n;++i){
        a[i]=gint();
    }
    if(k==1)special(n);
    for(int i=1;i+k-1<=n;++i){
        nowleaf=1;
        no=0;
        ptr=i;
        dfs(0,1<<30);
    }
    printf("%u\n",ans);

}

