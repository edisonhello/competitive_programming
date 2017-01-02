#include<cstdio>
#include<vector>
#include<assert.h>
#define mid ((l+r)>>1)
using namespace std;

// bool ;
vector<int> ch[100005];
int in[100005],out[100005],T;
struct node{
    node *l,*r;
    bool t;
    node():l(NULL),r(NULL),t(0){};
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
    init(now->l,l,mid);
    init(now->r,mid+1,r);
    return;
}
void modify(node *now,int l,int r,int &ml,int &mr){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr)now->t^=1;
    else{
        modify(now->l,l,mid,ml,mr);
        modify(now->r,mid+1,r,ml,mr);
    }
}
bool query(node *now,int l,int r,int &q){
    if(l==q&&q==r)return now->t;
    if(now->t){
        now->l->t^=1;
        now->r->t^=1;
        now->t=0;
    }
    if(q<=mid)return query(now->l,l,mid,q);
    else return query(now->r,mid+1,r,q);
}

int main(){
    int n,m,a,b,i,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        ch[i].resize(k);
        for(int j=0;j<k;++j){
            scanf("%d",&ch[i][j]);
        }
    }
    flat(1);
    root=new node();
    init(root,0,T-1);
    while(m--){
        scanf("%d%d",&a,&b);
        if(!a)modify(root,0,T-1,in[b],out[b]);
        else printf("%d\n",query(root,0,T-1,in[b]));
    }
}
