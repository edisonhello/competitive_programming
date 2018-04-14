#include<vector>
#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;

int n,a[100000],djs[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

struct node{
    vector<node*> ch;
    int val,sz;
    node(int v=0):val(v),sz(1){}
};

struct heap{
    vector<node*> root;
    int sz,mx;
    node *merge(node *a,node *b){
        if(a->val>b->val){
            a->ch.push_back(b);
            return a;
        }
        else{
            b->ch.push_back(a);
            return b;
        }
    }
    vector<node*> merge(vector<node*> &a,vector<node*> &b){
        node *tmp=0;
        vector<node*> rt;
        for(int i=0;i<18;++i)rt.push_back(0);
        for(int i=0;i<18;++i){
            if(tmp && a.size()>i && a[i] && b.size()>i && b[i])rt[i]=tmp,tmp=merge(a[i],b[i]);
            else if(a.size()>i && a[i] && b.size()>i && b[i])rt[i]=merge(a[i],b[i]);
            else if(a.size()>i && a[i] && tmp)rt[i]=merge(a[i],tmp);
            else if(b.size()>i && b[i] && tmp)rt[i]=merge(b[i],tmp);
            else if(a.size()>i && a[i])rt[i]=a[i];
            else if(b.size()>i && b[i])rt[i]=b[i];
            else if(tmp)rt[i]=tmp;
        }
        while(rt.back()==0)rt.pop_back();
        return rt;
    }
    void pop(){
        --sz;
        int idx=0;
        for(int i=0;i<root.size();++i)if(root[i] && root[i]->val==mx){idx=i; break;}
        vector<node*> son=root[idx]->ch;
        // while(son.size()<18)son.push_back(0);
        root[idx]=0;
        root=merge(root,son);
        mx=0;
        for(int i=0;i<root.size();++i)if(root[i])mx=max(mx,root[i]->val);
    }
    void merge(heap &ano){
        sz+=ano.sz;
        mx=max(mx,ano.mx);
        root=merge(root,ano.root);
    }
    void insert(int val){
        heap tmp(val);
        merge(tmp);
    }
    int get_sz(){return sz;}
    int get_val(){return mx;}
    heap(int val):sz(1){
        root.resize(1);
        root[0]=new node(val);
        mx=val;
    }
} *mk[100005];

int main(){
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            djs[i]=i;
            if(mk[i])delete mk[i];
            mk[i]=new heap(a[i]);
        }
        int m,u,v,umx,vmx; scanf("%d",&m); while(m--){
            scanf("%d%d",&u,&v);
            u=F(u), v=F(v);
            if(u==v){puts("-1"); continue;}
            umx=mk[u]->get_val(),vmx=mk[v]->get_val();
            mk[u]->pop(); mk[v]->pop();
            umx/=2; vmx/=2;
            djs[v]=u;
            mk[u]->merge(*mk[v]);
            mk[u]->insert(umx);
            mk[u]->insert(vmx);
            delete mk[v];
            mk[v]=0;
            printf("%d\n",mk[u]->get_val());
        }
    }
}
