#include<bits/stdc++.h>
using namespace std;

int a[100005],cnt[100005],aa[200005],diff,inrange;
int nxt[200005],prv[200005],front,back;
bitset<200005> used;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,m; cin>>n>>k>>m;
    int nn=n<<1;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=nn;++i)aa[i]=a[i>n?i-n:i];
    front=1, back=nn;
    for(int i=1;i<=nn;++i)nxt[i]=i+1,prv[i]=i-1;
    nxt[nn]=-1; prv[1]=-1;
    int L=1,R=1;
    for(;R<=nn;++R){
        ++inrange;
        ++cnt[aa[R]];
        if(cnt[aa[R]]==1)++diff;
        if(R-L+1>k){
            
        }
    }
}
