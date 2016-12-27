#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct _{int i,v;} a[1000006];
bool cmp_v(const _ &a,const _ &b){return a.v==b.v?a.i>b.i:a.v>b.v;}

struct node{
    node *l,*r;
    int v,rd;
    node():l(NULL),r(NULL),v(0){rd=rand();};
    node(int v):l(NULL),r(NULL),v(v){rd=rand();};
} *root;

bool insert(node *&now,int x){
    if(!now){
        now=new node(x);
    }
    else{
        if(now->v>x){
            insert(now->l,x);
            if(now->l->rd>now->rd){
                node *tmp=now->l;
                now->l=now->l->r;
                tmp->r=now;
                now=tmp;
            }
        }
        else{
            insert(now->r,x);
            if(now->r->rd>now->rd){
                node *tmp=now->r;
                now->r=now->r->l;
                tmp->l=now;
                now=tmp;
            }
        }
    }
}
int UB(node *now,int x){
    if(now->v<=x){
        if(!now->r)return -1;
        return UB(now->r,x);
    }
    else{
        if(!now->l)return now->v;
        int rt=UB(now->l,x);
        if(rt==-1)return now->v;
        else return rt;
    }
}

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i].v);
        a[i].i=i;
    }
    sort(a,a+n,cmp_v);
    insert(root,n);
    for(int i=0;i<n;++i){
        int rt=UB(root,a[i].i);
        if(rt==n)a[a[i].i].v=n-1-a[i].i;
        else a[a[i].i].v=rt-a[i].i;
        insert(root,a[i].i);
    }
    a[n-1].v=0;
    for(int i=0;i<n;++i){
        printf("%d\n",a[i].v);
    }
}
