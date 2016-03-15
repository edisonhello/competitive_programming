#include<bits/stdc++.h>
using namespace std;

struct node{
    int bits[20];
    int tot;
//    change tag;
};
struct change{
    int l,r,x;
};

#define ull unsigned long long

int *a;
node *tree;
node build   (int l,int r,int id);
ull  que     (int l,int r,int id,int fl,int fr);
void update  (int l,int r,int id,change t);
//void mkchange

vector<change> cg;
int cnt;
int main(){
    ios_base::sync_with_stdio(0);
cnt=0;
    int n;
    scanf("%d",&n);
    a = new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    tree = new node[4*n];
    build(0,n-1,1);

    int q;cin>>q;
    for(int i=0;i<q;i++){
        int com;cin>>com;
        if(com == 1){
            int l,r;cin>>l>>r;
            ull res = que(0,n-1,1,l-1,r-1);
            cout<<res<<endl;
        }
        if(com == 2){
    //cout<<"got com2 ";
            int tl,tr,tx;cin>>tl>>tr>>tx;
    //cout<<tl<<" to "<<tr<<" wth "<<tx<<endl;
            change t;
            t.l=tl-1;
            t.r=tr-1;
            t.x=tx;
    //cout<<"call update"<<endl;
            update(0,n-1,1,t);
        }
    }
}

ull que(int l,int r,int id,int fl,int fr){
    if(r< fl || l> fr) return 0;
    if(r<=fr && l>=fl){
        ull t = 0;
        for(int i=0;i<20;i++){
            t += (tree[id].bits[i] << i);
        }
        return t;
    }
    int mid = (l+r)/2;
    ull t1 = que(l,mid,id*2,fl,fr);
    ull t2 = que(mid+1,r,id*2+1,fl,fr);
    return t1 + t2;
    /*bool cgin = false;
    for(int i=0;i<cg.size();i++){
        if(bg[i].l>=)
    }*/
}



void update(int l,int r,int id,change t){
cnt++;
    //cout<<"update in, l-r-id-tl-tr-tx ";
    //printf("%d %d %d %d %d %d\n",l,r,id,t.l,t.r,t.x);
//if(cnt==150)return;
    if(l==t.l && r==t.r){
    //cout<<"range match"<<endl;
        node tmp;
        for(int i=0;i<20;i++){
            tmp.bits[i] = t.x&(1<<i) ? 1 : 0 ;
            if(tmp.bits[i]){
                tree[id].bits[i] = tree[id].tot - tree[id].bits[i];
            }
        }
        if(l == r){
            return;
        }
        int mid = (l+r)/2;
        change t1 = t;t1.r = mid;
        change t2 = t;t2.l = mid+1;
        update(l,mid,id*2,t1);
        update(mid+1,r,id*2+1,t2);
        return;
    }
    int mid = (l+r)/2;
    if(mid<t.l){
        update(mid+1,r,id*2+1,t);
        for(int i=0;i<20;i++){
            tree[id].bits[i] = tree[id*2].bits[i] + tree[id*2+1].bits[i];
        }
        return;
    }
    if(mid>=t.r){
        update(l,mid,id*2,t);
        for(int i=0;i<20;i++){
            tree[id].bits[i] = tree[id*2].bits[i] + tree[id*2+1].bits[i];
        }
        return;
    }
    change t1 = t;t1.r = mid;
    change t2 = t;t2.l = mid+1;
    update(l,mid,id*2,t1);
    update(mid+1,r,id*2+1,t2);
    for(int i=0;i<20;i++){
        tree[id].bits[i] = tree[id*2].bits[i] + tree[id*2+1].bits[i];
    }
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
