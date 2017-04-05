struct node{
    node *l,*r;
    int val,sz;
    node():l(NULL),r(NULL),val(0),sz(1){};
    node(int v):l(NULL),r(NULL),val(v),sz(1){};
    inline int lz(){return l?l->sz:0;}
    inline int rz(){return r?r->sz:0;}
};
struct meowTree{
    node *root;
    meowTree():root(NULL){};
    void init(){
        clearTree(root);
    }
    void clearTree(node *&now){
        if(!now)return;
        clearTree(now->l), clearTree(now->r);
        delete now; now=0;
    }
    void psz(node *&now){
        if(!now)return;
        now->sz=now->lz()+now->rz()+1;
    }
    void rot(node *&now,bool dir){
        if(!now)return;
        if(dir){
            node *tmp=now->l;
            now->l=tmp->r;
            tmp->r=now;
            now=tmp;
        }
        else{
            node *tmp=now->r;
            now->r=tmp->l;
            tmp->l=now;
            now=tmp;
        }
    }
    void pull(node *&now){
        if(now->lz()>now->rz()+1)rot(now,1);
        else if(now->rz()>now->lz()+1)rot(now,0);
        psz(now->l), psz(now->r), psz(now);
    }
    void insert(node *&now,int val){
        if(!now){
            now=new node(val);
            return;
        }
        if(now->v>val)insert(now->l,val);
        else insert(now->r,val);
        pull(now);
    }
    void remove(node *&now){
        if(!now->l && !now->r){
            delete now; now=0;
            return;
        }
        if(!now->l){
            node *tmp=now;
            now=tmp->r;
            delete tmp;
            return;
        }
        if(!now->r){
            node *tmp=now;
            now=tmp->l;
            delete tmp;
            return;
        }
        bool dir=now->lz()>now->rz();
        rot(now,dir);
        remove(dir?now->r:now->l);
    }
    void remove(node *&now,int val){
        if(!now)return;
        if(now->v>val)remove(now->l,val);
        else if(now->v<val)remove(now->r,val);
        else remove(now);
        pull(now);
    }
};
