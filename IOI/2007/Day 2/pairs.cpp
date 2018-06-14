#include<bits/stdc++.h>
using namespace std;

int b,n,d,m;
struct point{
    int x,y,z;
} p[100005];

namespace three_dim{

int pre[77][155][155];

int get(int z,int xl,int xr,int yl,int yr){
    int rt=pre[z][xr][yr];
    if(xl)rt-=pre[z][xl-1][yr];
    if(yl)rt-=pre[z][xr][yl-1];
    if(xl&&yl)rt+=pre[z][xl-1][yl-1];
    return rt;
} 

void solve(){
    int mnx=7575757,mny=7575757,mxx=-7575757,mxy=-7575757;
    for(int i=1;i<=n;++i){
        tie(p[i].x,p[i].y)=make_pair(p[i].x+p[i].y,p[i].x-p[i].y);
        mnx=min(mnx,p[i].x);
        mny=min(mny,p[i].y);
        mxx=max(mxx,p[i].x);
        mxy=max(mxy,p[i].y);
    }
    for(int i=1;i<=n;++i){
        p[i].x-=mnx;
        p[i].y-=mny;
    }
    mxx-=mnx; mxy-=mny;
    mnx=mny=0;
    for(int i=1;i<=n;++i){
        ++pre[p[i].z][p[i].x][p[i].y];
    }
    for(int z=1;z<=75;++z){
        for(int i=0;i<155;++i){
            for(int j=0;j<155;++j){
                if(i)pre[z][i][j]+=pre[z][i-1][j];
                if(j)pre[z][i][j]+=pre[z][i][j-1];
                if(i&&j)pre[z][i][j]-=pre[z][i-1][j-1];
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        for(int z=1;z<=75;++z){
            if(abs(z-p[i].z)>d)continue;
            int dd=d-abs(z-p[i].z);
            int xl=p[i].x-dd,xr=p[i].x+dd;
            int yl=p[i].y-dd,yr=p[i].y+dd;
            if(xl<0)xl=0; if(yl<0)yl=0;
            if(xr>150)xr=150; if(yr>150)yr=150;
            ans+=get(z,xl,xr,yl,yr);
            // cout<<i<<" "<<ans<<endl;
        }
    }
    // cout<<"ori ans: "<<ans<<endl;
    cout<<(ans-n)/2<<endl;
}}

namespace two_dim{ 
struct node{
    node *l,*r;
    int tot;
    node():l(0),r(0),tot(0){}
} *root;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int x,int v){
    now->tot+=v;
    if(l==r)return;
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
}
int query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(ql<=l&&r<=qr)return now->tot;
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

void solve(){
    int mnx=7575757,mny=7575757,mxx=-7575757,mxy=-7575757;
    for(int i=1;i<=n;++i){
        tie(p[i].x,p[i].y)=make_pair(p[i].x+p[i].y,p[i].x-p[i].y);
        mnx=min(mnx,p[i].x);
        mny=min(mny,p[i].y);
        mxx=max(mxx,p[i].x);
        mxy=max(mxy,p[i].y);
    }
    for(int i=1;i<=n;++i){
        p[i].x-=mnx;
        p[i].y-=mny;
        // cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    sort(p+1,p+1+n,[](const point &a,point &b){ return a.x<b.x; });
    // for(int i=1;i<=n;++i)cout<<p[i].x<<" "<<p[i].y<<endl;
    mxx-=mnx; mxy-=mny;
    mnx=mny=0;
    long long ans=0;
    build(root=new node(),0,mxy);
    for(int i=1,lptr=1,rptr=0;i<=n;++i){
        while(rptr<n && p[rptr+1].x-p[i].x<=d){
            ++rptr;
            modify(root,0,mxy,p[rptr].y,1);
        }
        while(p[i].x-p[lptr].x>d){
            modify(root,0,mxy,p[lptr].y,-1);
            ++lptr;
        }
        ans+=query(root,0,mxy,p[i].y-d,p[i].y+d);
    }
    cout<<(ans-n)/2<<endl;
}}

int gd(int i,int j){
    return abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)+abs(p[i].z-p[j].z);
}

int main(){
    cin>>b>>n>>d>>m;
    for(int i=1;i<=n;++i){
        if(b>=1)cin>>p[i].x;
        if(b>=2)cin>>p[i].y;
        if(b>=3)cin>>p[i].z;
    }
    /* if(n<=1000){
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(gd(i,j)<=d)++ans;
            }
        }
        cout<<ans<<endl;
        return 0;
    } */
    if(b==1){
        vector<int> x;
        for(int i=1;i<=n;++i)x.push_back(p[i].x);
        sort(x.begin(),x.end());
        long long ans=0;
        for(int i=0;i<x.size();++i){
            auto it=upper_bound(x.begin(),x.end(),x[i]+d);
            ans+=it-x.begin()-i-1;
        }
        cout<<ans<<endl;
    }
    if(b==2)two_dim::solve();
    if(b==3)three_dim::solve();
}
// in virtual 47
// in virtual 62
// in virtual 70
// in virtual AC
