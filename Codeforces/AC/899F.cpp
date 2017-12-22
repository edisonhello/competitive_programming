#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int sz;
    long long ex;
    node():l(0),r(0),sz(0),ex(0){}
} *root;

int _(const char c){
    if(c>='A' && c<='Z')return c-'A';
    if(c>='a' && c<='z')return c-'a'+26;
    return c-'0'+52;
}

string s;

#define m ((l+r)>>1)
void pull(node *now){
    now->ex=now->l->ex|now->r->ex;
    now->sz=now->l->sz+now->r->sz;
}
void build(node *now,int l,int r){
    if(l==r){now->ex=1ll<<_(s[l]); now->sz=1; return;}
    build(now->l=new node(),l,m);
    build(now->r=new node(),m+1,r);
    pull(now);
    // cout<<"build "<<l<<" "<<r<<" "<<now->ex<<endl;
}
void modify(node *now,int l,int r,int lsz,int rsz,char upd){
    // cout<<"modify "<<l<<" "<<r<<" "<<lsz<<" "<<rsz<<" "<<endl;
    if(!(now->ex&(1ll<<upd)))return;
    if(l==r){now->ex=0; now->sz=0; return;}
    // cout<<"modify "<<l<<" "<<r<<" "<<lsz<<" "<<rsz<<" "<<now->l->sz<<" "<<now->r->sz<<endl;
    int tmplsz=now->l->sz;
    if(tmplsz>=lsz)modify(now->l,l,m,lsz,min(rsz,tmplsz),upd);
    if(tmplsz<rsz)modify(now->r,m+1,r,max(1,lsz-tmplsz),rsz-tmplsz,upd);
    pull(now);
    // cout<<"modify "<<l<<" "<<r<<" "<<now->ex<<endl;
}
void output(node *now,int l,int r){
    if(!now->ex)return;
    if(l==r){cout<<s[l]; return;}
    output(now->l,l,m);
    output(now->r,m+1,r);
}

int main(){
    int n,q; cin>>n>>q;
    cin>>s;
    build(root=new node(),0,n-1);
    while(q--){
        int l,r; char c;
        cin>>l>>r>>c;
        modify(root,0,n-1,l,r,_(c));
        // output(root,0,n-1); cout<<endl;
    }
    output(root,0,n-1);
}
