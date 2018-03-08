#include<bits/stdc++.h>
using namespace std;

#ifdef WEAK
#define DEBUG 1
#else
#define DEBUG 0
#endif

struct node{
    node *l,*r,*pa;
    int val,pri,sz;
    node(int v=0):val(v),sz(1),pri(rand()){
        l=r=pa=0;
    }
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void psz(){sz=lz()+rz()+1;}
    void ppa(){l?l->pa=this:0; r?r->pa=this:0;}
};

void split(node *s,int sz,node *&a,node *&b){
    if(!s){a=b=0; return;}
    if(s->lz()>=sz){
        b=s;
        split(s->l,sz,a,b->l);
        b->ppa();
        b->psz();
    }
    else{
        a=s;
        split(s->r,sz-s->lz()-1,a->r,b);
        a->ppa();
        a->psz();
    }
}

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->ppa();
        a->psz();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->ppa();
        b->psz();
        return b;
    }
}

int getroot(node *now,node *&root,int sz=1){
    root=now;
    sz+=now->lz();
    while(now->pa){
        root=now->pa;
        if(root->r==now)sz+=root->lz()+1;
        now=root;
    }
    return sz;
}

void ptree(node *now){
    if(!now)return;
    if(now->l)cout<<"(",ptree(now->l),cout<<")";
    cout<<now->val;
    if(now->r)cout<<"(",ptree(now->r),cout<<")";
}

int a[100005];

node *pos[100005];
bitset<100005> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    int ccs=0;
    for(int i=1;i<=n;++i){
        if(v[i])continue;
        v[i]=1;
        vector<int> cc;
        cc.push_back(i);
        while(a[cc.back()]!=cc[0]){
            cc.push_back(a[cc.back()]);
            v[cc.back()]=1;
        }
        node *root=0;
        for(int i:cc)pos[i]=new node(i);
        for(int i:cc)root=merge(root,pos[i]);
        ++ccs;
    }
    cout<<n-ccs<<endl;
    if(DEBUG){
        for(int i=1;i<=n;++i)cout<<"pos["<<i<<"]: "<<pos[i]<<endl;
        for(int i=1;i<=n;++i){
            if(pos[i]->pa==0){
                cout<<"tree root at "<<i<<" : ";
                ptree(pos[i]);
                cout<<endl;
            }
        }
    }
    while(m--){
        int pu,pv; cin>>pu>>pv;
        int u=a[pu],v=a[pv];
        swap(a[pu],a[pv]);
        node *uroot,*vroot;
        int uat=getroot(pos[u],uroot),vat=getroot(pos[v],vroot);
        if(uroot!=vroot){
            node *ul,*ur,*vl,*vr;
            split(uroot,uat,ul,ur);
            split(vroot,vat,vl,vr);
            if(DEBUG){
                /* cout<<"u v root "<<uroot<<" "<<vroot<<endl;
                cout<<"u v pos "<<pos[u]<<" "<<pos[v]<<endl;
                cout<<"u v at "<<uat<<" "<<vat<<endl;
                ptree(ul),cout<<" ";
                ptree(ur),cout<<" ";
                ptree(vl),cout<<" ";
                ptree(vr),cout<<endl; */
            }
            node *root=merge(merge(ul,vr),merge(vl,ur));
            root->pa=0;
            if(DEBUG){
                cout<<"root after merge: ";
                ptree(root);
                cout<<endl;
            }
            --ccs;
        }
        else{
            if(uat>vat)swap(uat,vat);
            node *root=uroot;
            node *l,*mi,*r,*z;
            split(root,vat,z,r);
            split(z,uat,l,mi);
            if(DEBUG){
                cout<<"u v at "<<uat<<" "<<vat<<endl;
            }
            uroot=merge(l,r);
            vroot=mi;
            uroot->pa=0;
            vroot->pa=0;
            ++ccs;
        }
        cout<<n-ccs<<endl;
        if(DEBUG){
            for(int i=1;i<=n;++i){
                if(pos[i]->pa==0){
                    cout<<"tree root at "<<i<<" : ";
                    ptree(pos[i]);
                    cout<<endl;
                }
            }
        }
    }
}
