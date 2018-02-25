#include<bits/stdc++.h>
using namespace std;

struct Q{
    int l,r,lb,i;
} qs[1000006];

int a[1000006],ans[1000006],nans,cnt[1000006];

void add(int v){
    ++cnt[v];
    if(cnt[v]==1)++nans;
    else if(cnt[v]==2)--nans;
}
void sub(int v){
    --cnt[v];
    if(cnt[v]==1)++nans;
    else if(cnt[v]==0)--nans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int size=sqrt(n);
    vector<int> num;
    for(int i=1;i<=n;++i)cin>>a[i],num.push_back(a[i]);
    sort(num.begin(),num.end()); num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=1;i<=n;++i)a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin();
    int q; cin>>q;
    for(int i=0;i<q;++i){
        int l,r; cin>>l>>r;
        qs[i]={l,r,l/size,i};
    }
    sort(qs,qs+q,[](const Q &a,const Q &b){return a.lb==b.lb?a.r<b.r:a.lb<b.lb;});
    int L=1,R=0;
    for(int i=0;i<q;++i){
        while(R<qs[i].r)add(a[++R]);
        while(L>qs[i].l)add(a[--L]);
        while(R>qs[i].r)sub(a[R--]);
        while(L<qs[i].l)sub(a[L++]);
        ans[qs[i].i]=nans;
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
