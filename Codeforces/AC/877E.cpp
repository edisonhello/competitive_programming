#include<bits/stdc++.h>
using namespace std;

vector<int> ss[200009],iio;
int in[200009],out[200009],tmr;
int lgt[200009];


void dfs(int now,int eff){
    // cout<<"dfs get in "<<now<<endl;
    in[now]=tmr;
    if(eff!=lgt[now]){
        eff^=1;
        iio.push_back(now);
    }
    for(int &i:ss[now]){
        dfs(i,eff);
    }
    out[now]=tmr++;
}

struct node{
    node *l,*r;
    int val,tag;
    node():l(0),r(0),val(0),tag(0){};
} *root;
void atg(node *now,int l,int r){
    int d=r-l+1;
    now->val=d-now->val;
    now->tag^=1;
}
void push(node *now,int l,int r){
    if(!now || !now->tag)return;
    if(now->l)atg(now->l,l,(l+r)>>1);
    if(now->r)atg(now->r,((l+r)>>1)+1,r);
    now->tag=0;
}
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,(l+r)>>1);
    build(now->r=new node(),((l+r)>>1)+1,r);
}
void mdf(node *now,int l,int r,int ml,int mr){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){atg(now,l,r); return;}
    if(now->tag)push(now,l,r);
    mdf(now->l,l,(l+r)>>1,ml,mr);
    mdf(now->r,((l+r)>>1)+1,r,ml,mr);
    now->val=now->l->val+now->r->val;
}
int qry(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return now->val;
    if(now->tag)push(now,l,r);
    return qry(now->l,l,(l+r)>>1,ql,qr)+qry(now->r,((l+r)>>1)+1,r,ql,qr);
}
void mdf(int x){
    // cout<<in[x]<<" "<<out[x]<<endl;
    mdf(root,0,tmr,in[x],out[x]);
}
int qry(int x){
    // cout<<in[x]<<" "<<out[x]<<endl;
    return qry(root,0,tmr,in[x],out[x]);
}
void print(node *now){
    if(!now)return;
    if(now->l)cout<<"(",print(now->l),cout<<")";
    cout<<now->val<<","<<now->tag;
    if(now->r)cout<<"(",print(now->r),cout<<")";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=2,p;i<=n;++i){
        cin>>p;
        ss[p].push_back(i);
    }
    for(int i=1;i<=n;++i){
        cin>>lgt[i];
    }
    dfs(1,0);
    // cout<<"tmr = "<<tmr<<endl;
    build(root=new node(),0,--tmr);
    for(int &i:iio){
        // cout<<"iio: "<<i<<endl;
        mdf(i);
        // print(root);
    }
    int qs; cin>>qs; while(qs--){
        string cmd; cin>>cmd; int num; cin>>num;
        if(cmd[0]=='g'){
            cout<<qry(num)<<endl;
        }
        else{
            mdf(num);
        }
    }
}
