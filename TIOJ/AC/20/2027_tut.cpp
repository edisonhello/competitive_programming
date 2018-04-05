#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    node *ch[2];
    int sz;
    node():sz(0){
        ch[0]=ch[1]=0;
    }
} *root,pool[333333],*_ptr=pool;

void ins(node *&now,int val,int ptr){
    if(!now)now=new (++_ptr) node();
    ++now->sz;
    if(ptr<0)return;
    ins(now->ch[!!(val&(1<<ptr))],val,ptr-1);
}
int query(node *now,int nval,int nmx,int ptr){
    if(!now)return 0;
    if(ptr<0)return now->sz;
    if((nval&(1<<ptr)) && (nmx&(1<<ptr))){
        return query(now->ch[0],nval,nmx,ptr-1);
    }
    else if((nval&(1<<ptr))){
        return query(now->ch[1],nval,nmx,ptr-1)+(now->ch[0]?now->ch[0]->sz:0);
    }
    else if((nmx&(1<<ptr))){
        return query(now->ch[1],nval,nmx,ptr-1);
    }
    else{
        return query(now->ch[0],nval,nmx,ptr-1)+(now->ch[1]?now->ch[1]->sz:0);
    }
}
void del(node *now){
    if(!now)return;
    del(now->ch[0]);
    del(now->ch[1]);
    delete now;
}

int a[300005];

ll go(int l,int r){
    if(l==r)return 0;
    int mid=(l+r)>>1;
    ll rt=0;

    int nmx=0,lptr=mid+1,rptr=mid;
    _ptr=pool;
    root=new (++_ptr) node();
    for(int i=mid+1;i<=r;++i){
        nmx=max(nmx,a[i]);
        while(lptr>l && a[lptr-1]<nmx)ins(root,a[--lptr],24);
        rt+=query(root,a[i],nmx,24);
    }
    nmx=0;
    _ptr=pool;
    root=new (++_ptr) node();
    for(int i=mid;i>=l;--i){
        nmx=max(nmx,a[i]);
        while(rptr<r && a[rptr+1]<=nmx)ins(root,a[++rptr],24);
        rt+=query(root,a[i],nmx,24);
        // cout<<i<<" "<<rt<<" "<<root->sz<<endl;
    }
    
    // cout<<l<<" "<<r<<" "<<rt<<endl;

    return go(l,mid)+go(mid+1,r)+rt;
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cout<<go(1,n)<<endl;
}
