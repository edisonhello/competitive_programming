#include<bits/stdc++.h>
using namespace std;

int lc[6000001],rc[6000001],mx[6000001],mn[6000001],ptr=0;

void addtag(int now,int t,int x){
    if(t==1)mn[now]=max(mn[now],x),mx[now]=max(mx[now],mn[now]);
    else    mx[now]=min(mx[now],x),mn[now]=min(mn[now],mx[now]);
}
void push(int now){
    if(!lc[now])return;
    addtag(lc[now],1,mn[now]);
    addtag(lc[now],2,mx[now]);
    addtag(rc[now],1,mn[now]);
    addtag(rc[now],2,mx[now]);
    mn[now]=0,mx[now]=0x3f3f3f3f;
}

int *ans;

#define mid ((l+r)>>1)
void build(int now,int l,int r){
    if(l==r){ return; }
    build(lc[now]=++ptr,l,mid);
    build(rc[now]=++ptr,mid+1,r);
}
void modify(int now,int l,int r,int ml,int mr,int t,int x){
    if(r<ml || mr<l)return;
    push(now);
    if(ml<=l&&r<=mr){
        addtag(now,t,x);
        return;
    }
    modify(lc[now],l,mid,ml,mr,t,x);
    modify(rc[now],mid+1,r,ml,mr,t,x);
}
void dfs(int now,int l,int r){
    // mn=max(mn,now->mn); mx=max(mx,now->mx);
    push(now);
    if(l==r){
        ans[l]=mn[now];
        return;
    }
    dfs(lc[now],l,mid);
    dfs(rc[now],mid+1,r);
}

void buildWall(int n,int q,int types[],int ls[],int rs[],int hs[],int __ans[]){
    memset(mx,0x3f,sizeof(mx));
    memset(mn,0,sizeof(mn));
    memset(lc,0,sizeof(lc));
    memset(rc,0,sizeof(rc));
    ptr=0;

    ans=__ans;
    build(0,0,n-1);
    for(int i=0;i<q;++i){
        modify(0,0,n-1,ls[i],rs[i],types[i],hs[i]);
    }
    dfs(0,0,n-1);
}

#ifdef WEAK
int __o[500005],__l[500005],__r[500005],__h[500005],__ans[2000005];
int main(){
    int n; cin>>n;
    int q; cin>>q;
    for(int i=0;i<q;++i)cin>>__o[i]>>__l[i]>>__r[i]>>__h[i];
    buildWall(n,q,__o,__l,__r,__h,__ans);
    for(int i=0;i<n;++i)cout<<__ans[i]<<" ";
    cout<<endl;
}
#endif
