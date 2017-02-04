// from CF 558E
#include<iostream>
#include<algorithm>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
#define m ((l+r)>>1)

int n,k,cnt[26];
string s;

struct node{
    node *l,*r;
    int v[26],lz[26];
} *root;

void build(node *&now,int l,int r){
    if(l==r){
        now->v[s[l]-'a']=1;
        for(int i=0;i<26;++i)now->lz[i]=-1;
        return;
    }
    now->l=new node();
    now->r=new node();
    build(now->l,l,m);
    build(now->r,m+1,r);
    for(int i=0;i<26;++i){
        now->v[i]=now->l->v[i]+now->r->v[i];
        now->lz[i]=-1;
    }
}
int query(node *&now,int &t,int l,int r,int &ql,int &qr){
    if(now->lz[t]!=-1){
        now->v[t]=now->lz[t]*(r-l+1);
        if(l!=r){
            now->l->lz[t]=now->lz[t];
            now->r->lz[t]=now->lz[t];
        }
        now->lz[t]=-1;
    }
    if(r<ql || qr<l)return 0;
    if(ql<=l && r<=qr)return now->v[t];
    int rt=query(now->l,t,l,m,ql,qr)+query(now->r,t,m+1,r,ql,qr);
    now->v[t]=now->l->v[t]+now->r->v[t];
    return rt;
}

void modify(node *&now,int &t,int l,int r,int &ml,int mr,int v){
    // cout<<"modify "<<t<<" "<<l<<" "<<r<<" "<<ml<<" "<<mr<<" "<<v<<endl;
    if(now->lz[t]!=-1){
        now->v[t]=now->lz[t]*(r-l+1);
        if(l!=r){
            now->l->lz[t]=now->lz[t];
            now->r->lz[t]=now->lz[t];
        }
        now->lz[t]=-1;
    }
    if(ml<=l && r<=mr){
        // cout<<"cur!\n";
        now->v[t]=v*(r-l+1);
        if(l!=r){
            now->l->lz[t]=v;
            now->r->lz[t]=v;
        }
        now->lz[t]=-1;
        return;
    }
    if(r<ml || mr<l)return;
    modify(now->l,t,l,m,ml,mr,v);
    modify(now->r,t,m+1,r,ml,mr,v);
    now->v[t]=now->l->v[t]+now->r->v[t];
}

void srt(int &l,int &r,int &type){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<26;++i)cnt[i]=query(root,i,0,n-1,l,r);
    // cout<<"cnt:";for(int i=0;i<26;++i)cout<<cnt[i]<<" ";cout<<endl;
    int now=l;
    if(type){
        for(int i=0;i<26;++i){
            modify(root,i,0,n-1,l,r,0);
            if(!cnt[i])continue;
            modify(root,i,0,n-1,now,now+cnt[i]-1,1);
            now+=cnt[i];
        }
    }
    else{
        for(int i=25;i>=0;--i){
            modify(root,i,0,n-1,l,r,0);
            if(!cnt[i])continue;
            modify(root,i,0,n-1,now,now+cnt[i]-1,1);
            now+=cnt[i];
        }
    }
}

void psh(node *&now,int &t,int l,int r){
    if(now->lz[t]!=-1){
        now->v[t]=now->lz[t]*(r-l+1);
        if(l!=r){
            now->l->lz[t]=now->lz[t];
            now->r->lz[t]=now->lz[t];
        }
        now->lz[t]=-1;
    }
    if(!now->v[t])return;
    if(l==r){
        s[l]=t+'a';
        return;
    }
    psh(now->l,t,l,m);
    psh(now->r,t,m+1,r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>s;
    build(root=new node(),0,n-1);
    while(k--){
        int i,j,t;cin>>i>>j>>t;
        srt(--i,--j,t);
    }
    for(int i=0;i<26;++i)psh(root,i,0,n-1);
    cout<<s<<endl;
}
