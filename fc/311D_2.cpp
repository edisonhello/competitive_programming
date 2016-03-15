#include<bits/stdc++.h>
#define mid (l+r)/2
#define ull unsigned long long
#define imnot guagua

using namespace std;
const int mxn = 100000+10;
const int mod = 95542721;

struct node{
    ull v;
    int flg;
    bool last;
    node() : flg(0),last(1){}
};

inline int rit(){
int a;scanf("%d",&a);return a;
}

inline ull rll(){
ull a;scanf("%I64d",&a);return a;
}

int a[mxn];
node tree[mxn*4];

void build(int l,int r,int id){
    if(l==r){
        tree[id].v = a[l];
        return;
    }
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);

    tree[id].v = tree[id*2].v + tree[id*2+1].v;
}

void update(int id,int l,int r){
        //cout<<"go update "<<l<<" "<<r<<endl;
    if(l==r){
            //cout<<"trip "<<l<<endl;
        tree[id].v = ((((tree[id].v%mod)*tree[id].v)%mod)*tree[id].v)%mod;
        return;
    }
    tree[id*2].flg  ++;
    tree[id*2+1].flg++;
    tree[id].last = 0;
    while(id!=1){
        id/=2;
        tree[id].last = 0;
    }
    return;
}

ull qry(int l,int r,int id,int fl,int fr){
        //cout<<"qry "<<l<<" "<<r<<" val= "<<tree[id].v<<", flg= "<<tree[id].flg<<" ("<<fl<<" "<<fr<<" ("<<id<<")\n";
    if(r<fl || fr<l){
        return 0;
    }

    while(tree[id].flg>0){
        update(id,l,r);
        tree[id].flg--;
    }           //我覺得邏輯比較對的

    if(fl<=l&&r<=fr){
        if(tree[id].last){
            return tree[id].v;
        }
        ull t1 = qry(l,mid,id*2,l,mid);
        ull t2 = qry(mid+1,r,id*2+1,mid+1,r);
        //tree[id].last = 1;
        return tree[id].v = (t1 + t2) % mod;
    }

    ull t1 = qry(l,mid,id*2,fl,fr);
    ull t2 = qry(mid+1,r,id*2+1,fl,fr);
    return (t1 + t2)%mod;
}

void mkflg(int l,int r,int id,int fl,int fr){
    if(r<fl || fr<l){
        return;
    }
    if(fl<=l&&r<=fr){
        tree[id].flg++;
        return;
    }
    mkflg(l,mid,id*2,fl,fr);
    mkflg(mid+1,r,id*2+1,fl,fr);
    //tree[id].flg++;
    return;
}

int main(){
    int n=rit();
    for(int i=0;i<n;i++){
        a[i]=rll();
    }

    build(0,n-1,1);

    int q=rit();
    for(int i=0;i<q;i++){
        int c=rit(),l=rit(),r=rit();
        if(c==1){
            ull ans = qry(0,n-1,1,l-1,r-1);
            printf("%I64d\n",ans);
        }
        if(c==2){
            //tri
            mkflg(0,n-1,1,l-1,r-1);
        }
    }
}
