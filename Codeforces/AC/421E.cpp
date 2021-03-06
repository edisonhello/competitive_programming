#pragma GCC optimize("no-stack-protector,Ofast")
#include<bits/stdc++.h>
using namespace std;

unsigned int seed=880301;
int rnd(){
    return seed=(seed*880301)^7122;
}

struct node{
    node *l,*r;
    int sz,val,pri;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void psz(){sz=lz()+rz()+1;}
    node(int v=-1):l(0),r(0),sz(1),val(v),pri(rnd()){}
} *root,pool[1000006];

pair<int,int> op[1000006];
bitset<1000006> it;
int npt=1;

node *merge(node *a,node *b){
    if(!(a&&b))return a?:b;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->psz();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->psz();
        return b;
    }
}
void split(node *now,int sz,node *&a,node *&b){
    if(!now){a=b=0; return;}
    if(now->lz()>=sz){
        b=now;
        split(now->l,sz,a,b->l);
        b->psz();
    }
    else{
        a=now;
        split(now->r,sz-1-now->lz(),a->r,b);
        a->psz();
    }
}
void gl(node *now){
    if(!now)return;
    gl(now->l);
    if(now->val!=-1)printf("%d ",now->val);
    else{
        while(it[npt])++npt;
        printf("%d ",npt);
        it[npt]=1;
    }
    gl(now->r);
}

int inp(){
    char c; int x=0;
    while((c=getchar()) && (c<'0' || c>'9'));
    while((x=x*10+c-'0',c=getchar()) && c>='0' && c<='9');
    return x;
}

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n=inp(),m=inp();
    for(int i=1;i<=m;++i){
        op[i].first=inp();
        op[i].second=inp();
        // it[op[i].first]=1;
    }
    for(int i=1;i<=n;++i)root=merge(root,&pool[i]);

    node *a,*b,*c,*d;
    for(int i=m;i>=1;--i){
        split(root,1,a,b);
        if(a->val==-1){
            if(it[op[i].first])exit((cout<<-1<<endl,0));
            a->val=op[i].first;
            it[op[i].first]=1;
        }
        else if(a->val!=op[i].first)exit((cout<<-1<<endl,0));
        split(b,op[i].second-1,c,d);
        root=merge(c,merge(a,d));
    }
    gl(root);
}
