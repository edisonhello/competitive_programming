#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[50005];
int mn[50005];

struct node{
    node *l,*r;
    int mn;
    node():l(0),r(0),mn(1<<28){}
} *root;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        now->mn=v;
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
    now->mn=min(now->l->mn,now->r->mn);
}
int query(node *now,int l,int r,int x){
    if(l==r)return l;
    if(now->l->mn<x)return query(now->l,l,mid,x);
    else return query(now->r,mid+1,r,x);
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    long long ans=0;

    build(root=new node(),1,n+1);
    modify(root,1,n+1,n+1,0);
    
    deque<int> dq;

    for(int i=n;i>=1;--i){
        int pos=query(root,1,n+1,a[i]);
        modify(root,1,n+1,i,a[i]);
        // cout<<"pos: "<<pos<<endl;
        while(dq.size() && a[dq.front()]<a[i])dq.pop_front();
        dq.push_front(i);
        int L=0,R=dq.size()-1;
        while(R>L){
            int M=(L+R+1)>>1;
            if(dq[M]>pos)R=M-1;
            else L=M;
        }
        ans+=L+1;
        // cout<<"i "<<i<<" L "<<L<<endl;

        mn[i]=min(mn[i+1],a[i]);
    }
    cout<<ans<<endl;
}
