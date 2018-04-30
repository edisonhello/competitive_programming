#include<bits/stdc++.h>
using namespace std;

struct Q{
    int l,lb,r,i;
} qs[50005];

long long ans[155555],na;
int k,a[55555],bit[155555],up[55555],dn[55555];
vector<int> num;

void insert(int x){
    for(;x<155555;x+=x&-x)++bit[x];
}
void remove(int x){
    for(;x<155555;x+=x&-x)--bit[x];
}
int get(int l,int r){
    int rt=0;
    for(;r;r-=r&-r)rt+=bit[r];
    for(;l;l-=l&-l)rt-=bit[l];
    return rt;
}

void add(int idx){
    // cout<<"add "<<val<<" in tree"<<endl;
    na+=get(dn[idx]-1,up[idx]);
    // cout<<"na: "<<na<<endl;
    insert(a[idx]);
}
void sub(int idx){
    remove(a[idx]);
    // cout<<"sub "<<val<<" in tree"<<endl;
    na-=get(dn[idx]-1,up[idx]);
    // cout<<"na: "<<na<<endl;
}

int main(){
    int n,q; scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        num.push_back(a[i]);
        num.push_back(a[i]+k);
        num.push_back(a[i]-k);
    }
    sort(num.begin(),num.end());
    for(int i=1;i<=n;++i){
        up[i]=lower_bound(num.begin(),num.end(),a[i]+k)-num.begin()+1;
        dn[i]=lower_bound(num.begin(),num.end(),a[i]-k)-num.begin()+1;
        a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
    }
    for(int i=0,l,r;i<q;++i){
        scanf("%d%d",&l,&r); ++l, ++r;
        qs[i]={l,l/250,r,i};
    }
    sort(qs,qs+q,[](const Q &a,const Q &b){return tie(a.lb,a.r)<tie(b.lb,b.r);});
    int L=1,R=0;
    for(int i=0;i<q;++i){
        // cout<<"qing: "<<qs[i].l<<" "<<qs[i].r<<endl;
        while(R<qs[i].r)add(++R);
        while(L>qs[i].l)add(--L);
        while(R>qs[i].r)sub(R--);
        while(L<qs[i].l)sub(L++);
        ans[qs[i].i]=na;
    }
    for(int i=0;i<q;++i)printf("%lld\n",ans[i]);
}
