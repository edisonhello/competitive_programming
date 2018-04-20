#include<bits/stdc++.h>
#define mid ((l+r)>>1)

using namespace std;
struct node{
    int pr,l,r;
    node() : pr(0),l(0),r(0){}
} tree[4000006];
string input;

inline void pull(int id){
    if(tree[(id<<1)].r > tree[(id<<1)+1].l){
        tree[id].pr += (tree[(id<<1)+1].l+tree[(id<<1)].pr+tree[(id<<1)+1].pr);
        tree[id].r = tree[(id<<1)+1].r + tree[(id<<1)].r - tree[(id<<1)+1].l;
        tree[id].l = tree[(id<<1)].l;
    }
    else if(tree[(id<<1)].r < tree[(id<<1)+1].l){
        tree[id].pr += (tree[(id<<1)].r+tree[(id<<1)].pr+tree[(id<<1)+1].pr);
        tree[id].l = tree[(id<<1)].l +tree[(id<<1)+1].l - tree[(id<<1)].r;
        tree[id].r = tree[(id<<1)+1].r;
    }
    else if(tree[(id<<1)].r == tree[(id<<1)+1].l){
        tree[id].pr += (tree[(id<<1)].r+tree[(id<<1)].pr+tree[(id<<1)+1].pr);
        tree[id].l = tree[(id<<1)].l;
        tree[id].r = tree[(id<<1)+1].r;
    }
}

void build(int l,int r,int id){
        //cout<<"build "<<l<<" "<<r<<"("<<id<<")"<<endl;
    if(l==r){
        input[l] == ')' ? tree[id].l=1 : tree[id].r=1;
        tree[id].pr = 0;
        return;
    }
    build(l,mid,(id<<1));
    build(mid+1,r,(id<<1)+1);
    pull(id);


    //cout<<"tree l r pr l r "<<l<<" "<<r<<" "<<tree[id].pr<<" "<<tree[id].l<<" "<<tree[id].r<<endl;

    return;
}

node que(int l,int r,int id,int fl,int fr){
        //cout<<"que "<<l<<" "<<r<<" "<<fl<<" "<<fr<<" ";//<<endl;
    if(r<fl || fr<l){//cout<<"jizz"<<endl;
        node ret;
        return ret;
    }
    if(fl<=l&&r<=fr){//cout<<"comp in"<<endl;
        return tree[id];
    }               //cout<<"split"<<endl;
    node t1 = que(l,mid,(id<<1),fl,fr);
    node t2 = que(mid+1,r,(id<<1)+1,fl,fr);
    node t;
    if(t1.r > t2.l){
        t.pr += (t2.l+t1.pr+t2.pr);
        t.r = t2.r + t1.r - t2.l;
        t.l = t1.l;
    }
    else if(t1.r < t2.l){
        t.pr += (t1.r+t1.pr+t2.pr);
        t.l = t1.l +t2.l - t1.r;
        t.r = t2.r;
    }
    else if(t1.r == t2.l){
        t.pr += (t1.r+t1.pr+t2.pr);
        t.l = t1.l;
        t.r = t2.r;
    }
    return t;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>input;

    build(0,input.length()-1,1);

    int q; cin>>q;
    int n = input.length();

    while(q--){
        int l,r; cin>>l>>r;
        node res = que(0,n-1,1,l-1,r-1);
        cout<<res.pr * 2<<endl;
    }
}
