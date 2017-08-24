#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
#define mid (l+r)/2
using namespace std;

struct node{
    node *l,*r;
    int v;
    node(){
        v=0;
    }
} *root;
const int MX=1e8+5;
int n,q,a[MX],v[MX];

void build(node *now,int l,int r){
    if(l==r){
        now->v=v[l];
        return ;
    }
    now->l=new node();
    now->r=new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);

    now->v=max(now->l->v,now->r->v);
    return ;
}

int query(node *now,int l,int r,int fl,int fr){
    if(l>fr||r<fl){
        return 0;
    }
    if(fl<=l&&r<=fr){
        return now->v;
    }
    return max(query(now->l,l,mid,fl,fr),query(now->r,mid+1,r,fl,fr));
}

int qr(int l,int r){
    int ans=0;
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            ans+=query(root,0,n-2,i,j-1);
            printf("query %d %d,ans=%d \n",i,j,ans);
        }
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i)v[i]=a[i]-a[i-1];
    }

    root=new node();
    build(root,0,n-2);
    
    for(int i=0;i<q;i++){
        int l,r;scanf("%d%d",&l,&r);
        int ans=qr(l,r);
        printf("%d\n",ans);
    }
}
