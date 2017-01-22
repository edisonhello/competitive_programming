// WA
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    node *l,*r;
    int val,sz;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    node():l(NULL),r(NULL),val(0),sz(1){};
    node(int v):l(NULL),r(NULL),val(v),sz(1){};
} *lt,*rt;
void plsz(node *&now){
    now->sz=now->lz()+now->rz()+1;
}
void rotL(node *&now){
    node *tmp=now->r;
    now->r=tmp->l;
    tmp->l=now;
    now=tmp;

}
void rotR(node *&now){
    node *tmp=now->l;
    now->l=tmp->r;
    tmp->r=now;
    now=tmp;
}
void pull(node *&now){
    if(now->rz()>now->lz()){rotL(now);plsz(now->l);}
    if(now->lz()>now->rz()){rotR(now);plsz(now->r);}
    plsz(now);
}
node *merge(node *&a,node *b){
    if(!a)return b;
    if(!b)return a;
    if(a->val>b->val){
        a->r=merge(a->r,b);
        pull(a);
        return a;
    }
    else{
        b->l=merge(a,b->l);
        pull(b);
        return b;
    }
}
void split(node *now,int k,node *&a,node *&b){
    if(!now)a=b=NULL;
    else if(now->val<k){
        a=now;
        split(now->r,k,a->r,b);
        pull(a);
    }
    else{
        b=now;
        split(now->l,k,a,b->l);
        pull(b);
    }
}
int getK(node *&now,int k){
    // cout<<"in getK: val:"<<now->val<<" k:"<<k<<endl;
    if(!now)return 999999; // || k>now->size
    if(k==now->lz()+1)return now->val;
    if(k<=now->lz())return getK(now->l,k);
    return getK(now->r,k-1-now->lz());
}
void goTree(node *&now){
    if(!now)return;
    if(now->l){cout<<"(";goTree(now->l);cout<<")";}
    cout<<now->val<<" ";
    if(now->r){cout<<"(";goTree(now->r);cout<<")";}
}

int a[1000006],br[1000006],bot;
bool us[1000006];

int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    node *sm,*it,*gt,*tmp;
    for(int i=0;i<n;++i){
        cin>>a[i];
        rt=merge(rt,new node(i));
    }
    // goTree(rt);cout<<endl;
    for(int i=0;i<n;++i){
        us[a[i]]=1;
        while(us[bot])++bot;
        // cout<<"processing i="<<i<<endl;
        // cout<<"now rt:";goTree(rt);cout<<endl;
        // cout<<"now lt:";goTree(lt);cout<<endl;
        split(rt,a[i],sm,tmp);
        split(tmp,a[i]+1,it,gt);
        // cout<<"rt gt:";goTree(gt);cout<<", gt sz="<<(gt?gt->sz:0)<<", want sz="<<(gt?(((gt->sz-1)>>1)+1):0)<<endl;
        int R=getK(gt,gt?(((gt->sz-1)>>1)+1):0);
        // cout<<"get R="<<R<<endl;
        if(bot>a[i])rt=gt;
        else rt=merge(sm,gt);
        split(lt,a[i],sm,gt);
        // cout<<"lt gt:";goTree(gt);cout<<", gt sz="<<(gt?gt->sz:0)<<", want sz="<<(gt?(((gt->sz-1)>>1)+1):0)<<endl;
        int L=getK(gt,gt?(((gt->sz-1)>>1)+1):0);
        // cout<<"get L="<<L<<endl;
        if(bot>a[i])lt=gt;
        else{
            tmp=merge(sm,it);
            lt=merge(tmp,gt);
        }
        int num=min(L,R);
        // cout<<endl;
        if(num==999999)continue;
        ++br[a[i]];++br[num];
    }
    int ans=0;
    for(int i=0;i<n;++i)ans=max(ans,br[i]);
    cout<<ans<<endl;
}
