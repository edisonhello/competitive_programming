#include<bits/stdc++.h>
using namespace std;

struct Q{
    int l,r,lb,rb,t,i;
} qs[100006];
struct M{
    int p,x;
} ms[100006];

int L,R;
int a[100006],cnt[200006],ans[100006],ccnt[100006];

void add(int x){
    --ccnt[cnt[x]];
    ++cnt[x];
    ++ccnt[cnt[x]];
}
void sub(int x){
    --ccnt[cnt[x]];
    --cnt[x];
    ++ccnt[cnt[x]];
}
void dmf(int i){
    // cout<<"dmf "<<i<<" "<<L<<" "<<R<<endl;
    if(L<=ms[i].p && ms[i].p<=R){
        sub(a[ms[i].p]);
        add(ms[i].x);
    }
    swap(a[ms[i].p],ms[i].x);
}
int gans(){
    int rt=1;
    while(ccnt[rt])++rt;
    return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,z; cin>>n>>z;
    int bsize=ceil(pow(n,0.666));
    vector<int> num;
    for(int i=1;i<=n;++i)cin>>a[i],num.push_back(a[i]);
    int m=0,q=0;
    for(int i=0;i<z;++i){
        int c,x,y; cin>>c>>x>>y;
        if(c==1)qs[q]={x,y,x/bsize,y/bsize,m,q},++q;
        else ms[m]={x,y},++m,num.push_back(y);
    }
    sort(num.begin(),num.end()); num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=1;i<=n;++i)a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin();
    for(int i=0;i<m;++i)ms[i].x=lower_bound(num.begin(),num.end(),ms[i].x)-num.begin();
    sort(qs,qs+q,[](const Q &a,const Q &b){return a.lb==b.lb?a.rb==b.rb?a.t<b.t:a.rb<b.rb:a.lb<b.lb;});
    L=1,R=0;
    int t=0;
    for(int i=0;i<q;++i){
        while(R<qs[i].r)add(a[++R]);
        while(L>qs[i].l)add(a[--L]);
        while(R>qs[i].r)sub(a[R]),--R;
        while(L<qs[i].l)sub(a[L]),++L;
        while(t<qs[i].t)dmf(t),++t;
        while(t>qs[i].t)dmf(--t);
        ans[qs[i].i]=gans();
        // cout<<"gans for "<<qs[i].i<<" , "<<ccnt[1]<<" "<<ccnt[2]<<" "<<ccnt[3]<<" "<<ccnt[4]<<endl;
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
