#include<bits/stdc++.h>
using namespace std;

int dis[222],dp[812][812];

struct node{
    node *l,*r;
    int mx;
    node():l(0),r(0),mx(0){}
};
struct nodex{
    node *y;
    nodex *l,*r;
    nodex():l(0),r(0),y(0){}
} *root;

#define m ((l+r)>>1)

int qry(node *now,int l,int r,int x1,int x2){
    if(x1<=l && r<=x2)return now->mx;
    if(r<x1  ||  x2<l)return 0;
    return max(qry(now->l,l,m,x1,x2),qry(now->r,m+1,r,x1,x2));
}
int qry(nodex *now,int l,int r,int x1,int x2,int y1,int y2){
    if(x1<=l && r<=x2)return qry(now->y,1,804,y1,y2);
    if(r<x1  ||  x2<l)return 0;
    return max(qry(now->l,l,m,x1,x2,y1,y2),qry(now->r,m+1,r,x1,x2,y1,y2));
}
int qry(int x1,int x2,int y1,int y2){
    if(x2<x1 || y2<y1)return 0;
    return qry(root,1,804,x1,x2,y1,y2);
}
void upd(node *now,int l,int r,int x,int v){
    if(x<l || r<x)return;
    if(l==r)now->mx=max(now->mx,v);
    else upd(now->l,l,m,x,v),upd(now->r,m+1,r,x,v),now->mx=max(now->l->mx,now->r->mx);
}
void upd(nodex *now,int l,int r,int x,int y,int v){
    if(x<l || r<x)return;
    upd(now->y,1,804,y,v);
    if(l==r)return;
    upd(now->l,l,m,x,y,v);
    upd(now->r,m+1,r,x,y,v);
}
void add(int x,int y,int v){
    upd(root,1,804,x,y,v);
}
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,m);
    build(now->r=new node(),m+1,r);
}
void build(nodex *now,int l,int r){
    build(now->y=new node(),1,804);
    if(l==r)return;
    build(now->l=new nodex(),l,m);
    build(now->r=new nodex(),m+1,r);
}
void clear(node *now){
    if(!now)return;
    clear(now->l);
    clear(now->r);
    delete now;
}
void clear(nodex *now){
    if(!now)return;
    clear(now->l);
    clear(now->r);
    clear(now->y);
    delete now;
}

int main(){
    string a,b; cin>>a>>b; a="#"+a; b="$"+b;
    int k; cin>>k; while(k--){
        root=0; build(root=new nodex(),1,804);
        memset(dis,0x3f,sizeof(dis));
        string s; while(cin>>s && s!="$"){
            int ddd; cin>>ddd; dis[s[0]]=ddd;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<a.size();++i){
            for(int j=1;j<b.size();++j){
                // cout<<i<<" "<<j<<endl;
                if(a[i]==b[j]){ 
                    dp[i][j]=qry(max(1,i-dis[a[i]]-1),i-1,max(1,j-dis[b[j]]-1),j-1)+1;
                    add(i,j,dp[i][j]);
                }
            }
        }
        cout<<qry(1,804,1,804)<<" ";
        clear(root);
    } cout<<endl;
}
