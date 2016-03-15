#include<bits/stdc++.h>
using namespace std;

struct node{
    bool bits[60];
    node *l,*r;
};
struct bt{
    bool bits[60];
};
#define ull unsigned long long
#define ll long long
#define mid (l+r)/2

ull *a;

void build(int l,int r,node* pnt){
            //cout<<"build "<<l<<" "<<r<<endl;
    if(l==r){//cout<<"l==r"<<endl;
        for(int i=0;i<60;i++){
            pnt->bits[i] = a[l] & ((ull)1<<i);
        }
        return;
    }       //cout<<"split"<<endl;
    pnt->l = new node();
    pnt->r = new node();
    build(l,mid,pnt->l);
    build(mid+1,r,pnt->r);
    for(int i=0;i<60;i++){
        pnt->bits[i] = pnt->l->bits[i] ^ pnt->r->bits[i];
            //cout<<pnt->bits[i]<<" ";
    }       //cout<<endl;
}

bt que(int l,int r,node *pnt,int fl,int fr){
                //cout<<"que "<<l<<" "<<r<<" "<<fl<<" "<<fr<<endl;
    if(r<fl || l>fr){//cout<<"out"<<endl;
        bt rt;
        memset(&rt,0,sizeof(rt));
        return rt;
    }
    if(fl<=l&&r<=fr){//cout<<"all in"<<endl;
        bt rt;
        for(int i=0;i<60;i++){
            rt.bits[i] = pnt->bits[i];
        }
        return rt;
    }               //cout<<"split"<<endl;
    bt bt1 = que(l,mid,pnt->l,fl,fr);
    bt bt2 = que(mid+1,r,pnt->r,fl,fr);
    bt rt;
    for(int i=0;i<60;i++){
        rt.bits[i] = bt1.bits[i] ^ bt2.bits[i];
    }
    return rt;
}

int main(){
    int n,q;cin>>n>>q;
    a = new ull[n];
    node fst;
    for(int i=0;i<n;i++){
        scanf("%llu",&a[i]);
    }

    build(0,n-1,&fst);/**//**//**/

    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        bt rs = que(0,n-1,&fst,l-1,r-1);/**//**//**/
        ull res = 0;
        for(int i=0;i<60;i++){
            if(rs.bits[i]){
                res += ((ull)1<<i);
            }
        }
        printf("%llu\n",res);
    }
}
