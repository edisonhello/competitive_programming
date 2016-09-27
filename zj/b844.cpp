#include<bits/stdc++.h>
#define m (l+r)/2
using namespace std;
bitset<500005> ans,upd;

struct node{
    bool cur;
    node *l,*r;
    node():cur(0),l(NULL),r(NULL){};
} *root;

void bu(node *now,int l,int r){
    // cout<<"bu:"<<l<<" "<<r<<endl;
    if(l==r) return;
    bu(now->l=new node(),l,m);
    bu(now->r=new node(),m+1,r);
    return;
}

void sw(node *now,int n,int l,int r){
    if(r<n){
        return;
    }
    // cout<<"sw:n="<<n<<", l="<<l<<", r="<<r<<endl;
    if(n<=l){
        now->cur=!now->cur;
        // cout<<"cur switched. now,="<<now->cur<<endl;
        return;
    }
    if(now->cur){
        now->cur=0;
        now->l->cur=!now->l->cur;
        now->r->cur=!now->r->cur;
    }
    sw(now->l,n,l,m);
    sw(now->r,n,m+1,r);
    return;
}

void qu(node *now,int n,int l,int r){
    if(r<n || n<l){
        return;
    }
    if(l==r){
        if(!now->cur){
            upd[n]=1;
            cout<<"0\n";
        }
        else{
            upd[n]=1;
            ans[n]=1;
            cout<<"1\n";
        }
        return;
    }
    if(now->cur){
        now->cur=0;
        now->l->cur=!now->l->cur;
        now->r->cur=!now->r->cur;
    }
    qu(now->l,n,l,m);
    qu(now->r,n,m+1,r);
}

void cl(node *now){
    if(now->l)cl(now->l);
    if(now->r)cl(now->r);
    delete now;
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,q,a;
    while(cin>>n>>q){
        if(root)cl(root);
        root=new node();
        ans.reset();
        upd.reset();
        bu(root,1,500005);
        // cout<<"tree building finished.\n";
        while(n--){
            cin>>a;
            sw(root,a,0,500005);
        }
        while(q--){
            cin>>a;
            if(upd[a]){
                cout<<ans[a]<<'\n';
            }
            else{
                qu(root,a,0,500005);
            }
        }
    }
}
