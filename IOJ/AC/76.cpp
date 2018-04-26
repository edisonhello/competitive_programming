#include<bits/stdc++.h>
using namespace std;

struct Q{
    int l,lb,r,k,i;
} qs[100005];

const int bsz=350;

int n,a[100005],cnt[100005],bnum[350],cnum[100005],ans[100005];


void add(int x){
    ++cnt[x];
    int c=cnt[x];
    int ada=1ll*x*c%n;
    ++bnum[ada/bsz]; ++cnum[ada];
}
void sub(int x){
    int c=cnt[x];
    --cnt[x];
    int sba=1ll*c*x%n;
    --bnum[sba/bsz]; --cnum[sba];
}
int getans(int k){
    int pre=0;
    for(int i=0;;++i){
        if(pre+bnum[i]>=k){
            for(int j=i*bsz;;++j){
                pre+=cnum[j];
                if(pre>=k)return j;
            }
        }
        pre+=bnum[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],a[i]=(a[i]==n?0:a[i]);
    int q; cin>>q;
    for(int i=0;i<q;++i){
        int l,r,k; cin>>l>>r>>k;
        qs[i]={l,l/bsz,r,r-l+2-k,i};
    }
    sort(qs,qs+q,[](const Q &a,const Q &b){return tie(a.lb,a.r)<tie(b.lb,b.r);});
    int L=1,R=0;
    for(int i=0;i<q;++i){
        while(R<qs[i].r)add(a[++R]);
        while(L>qs[i].l)add(a[--L]);
        while(R>qs[i].r)sub(a[R--]);
        while(L<qs[i].l)sub(a[L++]);
        ans[qs[i].i]=getans(qs[i].k);
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
