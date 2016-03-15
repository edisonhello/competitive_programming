#include<bits/stdc++.h>
using namespace std;

struct node{
    int bits[20];
    int tot;
    bool tag[20];
};
struct change{
    int l,r,x;
};

#define ull unsigned long long

int *a;
node *tree;

void push(int id){
    for(int i=0;i<20;i++){
        if(tree[id].tag[i]){
            tree[id*2].bits[i] = tree[id*2].tot - tree[id*2].bits[i];
            tree[id*2+1].bits[i] = tree[id*2+1].tot - tree[id*2+1].bits[i];
            tree[id*2].tag[i] = !tree[id*2].tag[i];
            tree[id*2+1].tag[i] = !tree[id*2+1].tag[i];
        }
        tree[id].tag[i] = 0;
    }
}

void pull(int id){
    for(int i=0;i<20;i++){
        tree[id].bits[i] = tree[id*2].bits[i] + tree[id*2+1].bits[i];
    }
}

ull que(int l,int r,int id,int fl,int fr){
    //printf("que %d %d %d %d %d\n",l,r,id,fl,fr);
    if(fl>r || fr<l)return 0;
    if(fl<=l&&r<=fr){/*add tag check*/
        /*bool tag = false;
        for(int i=0;i<20;i++){
            if(tree[id].tag[i]){
                tag = true;
                break;
            }
        }
        if(tag){
            push(id);
            pull(id);
        }*/
        ull tot = 0;
        for(int i=0;i<20;i++){
            tot += ((ull)tree[id].bits[i] << i);
        }
        return tot;
    }
    push(id);
    int mid = (l+r)/2;
    ull t1 = que(l,mid,id*2,fl,fr);
    ull t2 = que(mid+1,r,id*2+1,fl,fr);
    pull(id);
    return t1 + t2;
}

void update(int l,int r,int id,change t){
    //printf("update %d %d %d %d %d %d\n",l,r,id,t.l,t.r,t.x);
    if(t.l>r || t.r<l)return;
    if(l>=t.l&&t.r>=r){
    //printf("inchange ");
        bool tmp[20];
    //for(int tst=0;tst<20;tst++)cout<<tree[id].bits[tst]<<" ";cout<<endl;
        for(int i=0;i<20;i++){
            tmp[i] = t.x & (1<<i) ? 1 : 0;
            if(tmp[i]){
                tree[id].bits[i] = tree[id].tot - tree[id].bits[i];
                tree[id].tag[i] = !tree[id].tag[i];
            }
        }
    //cout<<"         ";for(int tst=0;tst<20;tst++)cout<<tree[id].bits[tst]<<" ";cout<<endl;
        return;
    }

    push(id);
    int mid = (l+r)/2;
    update(l,mid,id*2,t);
    update(mid+1,r,id*2+1,t);
    pull(id);
}


node build(int l,int r,int id){
    if(l==r){
        node t;
        for(int i=0;i<20;i++){
            t.bits[i] = a[l]&(1<<i) ? 1 : 0 ;
            t.tot = 1;
        }
        return tree[id] = t;
    }

    int mid = (l+r)/2;
    node *t,t1,t2;
    t  = new node();
    t1 = build(l,mid,id*2);
    t2 = build(mid+1,r,id*2+1);
    for(int i=0;i<20;i++){
        t->bits[i] = t1.bits[i] + t2.bits[i];
    }
    t->tot = t1.tot + t2.tot;
    return tree[id] = *t;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    a = new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    tree = new node[4*n];
    memset(tree, 0, sizeof(tree));
    build(0,n-1,1);

    int q;cin>>q;
    for(int i=0;i<q;i++){
        int com;cin>>com;
        if(com == 1){
    //cout<<"com1"<<endl;
            int l,r;cin>>l>>r;
            ull res = que(0,n-1,1,l-1,r-1);
            cout<<res<<endl;
        }
        if(com == 2){
    //cout<<"com2"<<endl;
            int tl,tr,tx;cin>>tl>>tr>>tx;
            change t;
            t.l=tl-1;
            t.r=tr-1;
            t.x=tx;
            update(0,n-1,1,t);
        }
    }
}
