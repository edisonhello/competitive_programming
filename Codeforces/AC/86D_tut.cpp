#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Q{
    int l,r,lb,i;
} qs[200005];

int a[200005],cnt[1000006];
long long na,ans[200005];

void add(int v){
    na-=1ll*v*cnt[v]*cnt[v];
    ++cnt[v];
    na+=1ll*v*cnt[v]*cnt[v];
}
void sub(int v){
    na-=1ll*v*cnt[v]*cnt[v];
    --cnt[v];
    na+=1ll*v*cnt[v]*cnt[v];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,bsz=450; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=0,l,r;i<q;++i){
        cin>>l>>r;
        qs[i]={l,r,l/bsz,i};
    }
    sort(qs,qs+q,[](const Q &a,const Q &b){return a.lb==b.lb?a.r<b.r:a.lb<b.lb;});
    int L=1,R=0;
    for(int i=0;i<q;++i){
        while(L>qs[i].l)add(a[--L]);
        while(R<qs[i].r)add(a[++R]);
        while(R>qs[i].r)sub(a[R]),--R;
        while(L<qs[i].l)sub(a[L]),++L;
        ans[qs[i].i]=na;
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
