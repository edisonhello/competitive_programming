#include<iostream>
#include<algorithm>
#include<assert.h>
#define m (l+r)/2
#define ll long long
using namespace std;

struct node{
    node *l,*r;
    ll v,s;
    node():l(NULL),r(NULL),v(0){}
} *root;

int n,q;
ll a[100005],b[100005];

void build(node *now,int l,int r){
	if(l==r){
		now->s=b[l];
		now->v=abs(now->s);
		return;
	}
	now->l=new node();
	now->r=new node();
	build(now->l,l,m);
	build(now->r,m+1,r);
	now->v=__gcd(now->l->v,now->r->v);
	now->s=now->l->s+now->r->s;
	return;
}

void update(node *now,int l,int r,int up,ll k){
	if(up<l || r<up)return;
	if(l==up&&up==r){
		now->s+=k;
		now->v=abs(now->s);
		return;
	}
	update(now->l,l,m,up,k);
	update(now->r,m+1,r,up,k);
	now->v=__gcd(now->l->v,now->r->v);
	now->s=now->l->s+now->r->s;
	return;
}

ll querySegm(node *now,int l,int r,int ql,int qr){
	if(r<ql || qr<l)return 0;
	if(ql<=l&&r<=qr){
		return now->v;
	}
	ll lc=querySegm(now->l,l,m,ql,qr);
	ll rc=querySegm(now->r,m+1,r,ql,qr);
	if(lc&&rc)return __gcd(lc,rc);
	if(lc)return lc;
	if(rc)return rc;
	return 0;
}
ll queryPres(node *now,int l,int r,int ql,int qr){
	if(r<ql || qr<l)return 0;
	if(ql<=l&&r<=qr){
		return now->s;
	}
	ll lc=queryPres(now->l,l,m,ql,qr);
	ll rc=queryPres(now->r,m+1,r,ql,qr);
	return lc+rc;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    root=new node();
    build(root,1,n);
    for(int i=0,c;i<q;++i){
        cin>>c;
        if(c==1){
            int l,r;ll k;
            cin>>l>>r>>k;
            update(root,1,n,l,k);
            update(root,1,n,r+1,-k);
        }
        else{
            int l,r;
            cin>>l>>r;
            if(l==r)cout<<queryPres(root,1,n,1,l)<<endl;
            else{
                ll seg=querySegm(root,1,n,l+1,r);
                ll pnt=queryPres(root,1,n,1,l);
                // cout<<"seg: "<<seg<<", pnt: "<<pnt<<endl;
                if(seg==0ll)cout<<pnt<<endl;
                else cout<<__gcd(seg,pnt)<<endl;
            }
        }
    }
}
