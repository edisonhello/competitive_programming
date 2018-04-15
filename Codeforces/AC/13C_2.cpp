#include<vector>
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int n,a[5222];
long long ans=1ll<<60;

struct node{
    vector<node*> ch;
    int val,dg;
    node(int v=0):val(v),dg(0){ch.resize(15);}
};

struct heap{
    vector<node*> root;
    int sz,mx;
    node *merge(node *a,node *b){
        if(a->val>b->val){
            a->ch[a->dg++]=b;
            return a;
        }
        else{
            b->ch[b->dg++]=a;
            return b;
        }
    }
    vector<node*> merge(vector<node*> &a,vector<node*> &b){
        node *tmp=0;
        vector<node*> rt;
        for(int i=0;i<15;++i)rt.push_back(0);
        for(int i=0;i<15;++i){
            if(tmp && a[i] && b[i])rt[i]=tmp,tmp=merge(a[i],b[i]);
            else if(a[i] && b[i])tmp=merge(a[i],b[i]);
            else if(a[i] && tmp)tmp=merge(a[i],tmp);
            else if(b[i] && tmp)tmp=merge(b[i],tmp);
            else if(a[i])rt[i]=a[i];
            else if(b[i])rt[i]=b[i];
            else if(tmp)rt[i]=tmp,tmp=0;
            // if(rt[i])cout<<"rt["<<i<<"] dg: "<<rt[i]->dg<<endl;
        }
        return rt;
    }
    void pop(){
        // cout<<"popping"<<endl;
        --sz;
        int idx=0;
        for(int i=0;i<15;++i)if(root[i] && root[i]->val==mx){idx=i; break;}
        vector<node*> son=root[idx]->ch;
        while(son.size()<15)son.push_back(0);
        root[idx]=0;
        root=merge(root,son);
        mx=-(1<<30);
        for(int i=0;i<15;++i)if(root[i])mx=max(mx,root[i]->val);
    }
    void merge(heap &ano){
        sz+=ano.sz;
        mx=max(mx,ano.mx);
        root=merge(root,ano.root);
    }
    int get_sz(){
        return sz;
    }
    int get_val(){
        return mx;
    }
    heap(int val):sz(1){
        root.resize(15);
        root[0]=new node(val);
        mx=val;
    }
};

struct info{
    int l,r;
    heap hp;
    info(int l,int r,int val):l(l),r(r),hp(val){}
    int val(){
        return hp.get_val();
    }
    void merge(info &ano){
        hp.merge(ano.hp);
        l=min(l,ano.l);
        r=max(r,ano.r);
        while(hp.get_sz()>(r-l+2)/2)hp.pop();
    }
};

void meow(){
    deque<info> dq;
    for(int i=1;i<=n;++i){
        info now(i,i,a[i]);
        // cout<<"i: "<<i<<" , a[i]: "<<a[i]<<endl;
        while(dq.size() && now.val()<dq.back().val()){
            // cout<<"merge! "<<now.val()<<" "<<dq.back().val()<<endl;
            now.merge(dq.back());
            dq.pop_back();
        }
        dq.push_back(now);
    }
    // cout<<"finale dq size: "<<dq.size()<<endl;
    long long cost=0;
    for(int i=0;i<dq.size();++i){
        // cout<<"l,r is "<<dq[i].l<<" "<<dq[i].r<<" with val "<<dq[i].val()<<endl;
        for(int j=dq[i].l;j<=dq[i].r;++j){
            cost+=abs(a[j]-dq[i].val());
        }
    }
    ans=min(ans,cost);
    // cout<<"got cost "<<cost<<endl;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    meow();
    cout<<ans<<endl;
}
