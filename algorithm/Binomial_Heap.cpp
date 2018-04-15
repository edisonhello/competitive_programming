
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
        }
        return rt;
    }
    void pop(){
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
