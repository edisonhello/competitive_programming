#include<cstddef>

template<typename T>
class node{
public:
    node<T> *l,*r;
    T val;
    std::size_t sz;

    node():l(NULL),r(NULL),sz(1){};
    node(T v):l(NULL),r(NULL),val(v),sz(1){};
    void rotL(){
        node *tmp=this->r;
        this->r=tmp->l;
        tmp->l=this;
        this=tmp;
    }
    void rotR(){
        node *tmp=this->l;
        this->l=tmp->r;
        tmp->r=this;
        this=tmp;
    }
    size_t lz(){return this->l?this->l->sz:0;}
    size_t rz(){return this->r?this->r->sz:0;}
    size_t pull(){
        if(this->lz()>this->rz())this->rotR();
        else if(this->rz()>this->lz())this->rotL();
        return this->sz=this->lz()+this->rz()+1;
    }
};

template<typename T,typename cmp> // not use cmp
class PQ{
public:
    void insert(T val){return this->_insert(root,val);}
    T top(){return this->_top(root);}
    T back(){return this->_back(root);}
    T pop_top(){return this->_pop_top(root);}
    T pop_back(){return this->_pop_back(root);}
    void Pop_top(){return this->_Pop_top(root);}
    void Pop_back(){return this->_Pop_back(root);}
    size_t size(){return root?root->sz:0;}
    bool clear(){_clear(root);}
    bool empty(){return root?1:0;}
private:
    node<T> *root;
    bool _insert(node<T> *&now,T val){
        if(!now)now = new node<T>(val);
        else if(now->val<val)_insert(now->l,val);
        else _insert(now->r,val);
    }
    T _top(node<T> *now){
        while(now && now->r)now=now->r;
        if(now)return now->val;
    }
    T _back(node<T> *now){
        while(now && now->l)now=now->l;
        if(now)return now->val;
    }
    T _pop_top(node<T> *now){
        if(!now)return (T)0;
        node<T> *rc=now->r;
        while(rc->r){now=rc;rc=rc->r;}
        T rt=rc->val;
        now->r=NULL;
        delete rc;
        return rt;
    }
    T _pop_back(node<T> *now){
        if(!now)return (T)0;
        node<T> *lc=now->l;
        while(lc->l){now=lc;lc=lc->l;}
        T rt=lc->val;
        now->l=NULL;
        delete lc;
        return rt;
    }
    void _Pop_top(node<T> *now){
        if(!now)return (T)0;
        node<T> *rc=now->r;
        while(rc->r){now=rc;rc=rc->r;}
        now->r=NULL;
        delete rc;
    }
    void _Pop_back(node<T> *now){
        if(!now)return (T)0;
        node<T> *lc=now->l;
        while(lc->l){now=lc;lc=lc->l;}
        now->l=NULL;
        delete lc;
    }
    void clear(node<T> *now){
        if(!now)return;
        clear(now->l),clear(now->r);
        delete now;
    }
};

#include<functional>
using namespace std;
int main(){
    PQ<int,greater<int>> pq;
}
