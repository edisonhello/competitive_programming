#include<iostream>
#include<vector>
#define m ((l+r)>>1)
using namespace std;

// bool ;
vector<int> ch[100005];
int in[100005],out[100005],T;
struct node{
    node *l,*r;
    bool t;
    node():l(NULL),r(NULL),t(0);
} *root;

void flat(int now){
    in[now]=T++;
    for(int i=0;i<(int)ch[now].size();++i)flat(ch[now][i]);
    out[now]=T++;
}

void init(node *now,int l,int r){
    if(l==r)return;
    now->l=new node();
    now->r=new node();
    init(now->l,l,m);
    init(now->r,m+1,r);
    return;
}
void modify(node *now,int l,int r,int ml,int mr){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr)now->t^=1;
    else{
        modify(now->l,l,m,ml,mr);
        modify(now->r,m+1,r,ml,mr);
    }
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=1,k;i<=n;++i){
        cin>>k;
        ch[i].resize(k);
        for(int j=0;j<k;++j){
            cin>>ch[i][j];
        }
    }
    flat(1);
    root=new node();
    init(root,0,T-1);
    int a,b;
    while(m--){
        cin>>a>>b;
        if(a==0)tag[b]^=1;
        else dfs(1,b);
    }
}
