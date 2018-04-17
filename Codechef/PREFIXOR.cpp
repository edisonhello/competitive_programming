#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    long long v;
    node():l(0),r(0),v(0){}
} *root[400005],pool[3000005];
int _ptr=-1;
node *gnode(){
    return &pool[++_ptr];
}
node *gnode(node *ref){
    ++_ptr;
    pool[_ptr]=*ref;
    return &pool[_ptr];
}


int a[400005],to[400005],jto[400005];
vector<pair<int,int>> ev[400005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=gnode(),l,mid);
    build(now->r=gnode(),mid+1,r);
}
void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        now->v+=v;
        return;
    }
    if(x<=mid)modify(now->l=gnode(now->l),l,mid,x,v);
    else modify(now->r=gnode(now->r),mid+1,r,x,v);
    now->v=now->l->v+now->r->v;
}
long long query(node *now,int l,int r,int ql,int qr){
    // cout<<now<<" "<<l<<" "<<r<<endl;
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return now->v;
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

int main(){
    srand(7122);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],jto[i]=i;
    // for(int i=1;i<=n;++i)a[i]=rand()&65535?0:rand(),jto[i]=i;
    for(int i=n-1;i>=1;--i)if(a[i]==0 && a[i+1]==0)jto[i]=jto[i+1];
    for(int i=1;i<=n;++i){
        int now=a[i];
        to[i]=i;
        while(to[i]<n && (now^a[to[i]+1])>=now){
            ++to[i];
            now^=a[to[i]];
            if(jto[to[i]]!=to[i]){
                to[i]=jto[to[i]];
            }
            // cout<<i<<" "<<now<<endl;
        }
        ev[to[i]].emplace_back(i,to[i]-i+1);
        // cout<<i<<" to "<<to[i]<<endl;
    }
    build(root[0]=gnode(),1,n);
    for(int i=1;i<=n;++i){
        root[i]=gnode(root[i-1]);
        for(auto &p:ev[i]){
            modify(root[i],1,n,p.first,p.second);
        }
    }
    long long last=0;
    exit(0);
    int l,r,q; cin>>q;
    while(q--){
        cin>>l>>r;
        l=(l+last)%n+1;
        r=(r+last)%n+1;
        // cout<<"q "<<l<<" "<<r<<endl;
        cout<<(last=query(root[r],1,n,l,r))<<endl;
    }
}
