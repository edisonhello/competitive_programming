#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long

struct Q{int l,r,i,b;} Qs[100005];
bool operator<(const Q &a,const Q &b){return a.b==b.b?a.r<b.r:a.b<b.b;}
ll a[100005];
int ans[100005];

int cnt[100005],ptr;
void add(int v){
    // cout<<"add "<<v<<endl;
    if(v>100003)return;
    ++cnt[v];
    while(cnt[ptr])++ptr;
}
void rmv(int v){
    // cout<<"rmv "<<v<<endl;
    if(v>100003)return;
    --cnt[v];
    if(!cnt[v] && v<ptr)ptr=v;
}
int getans(){
    return ptr;
}

int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        int n,m;cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(cnt));ptr=0;
        for(int i=1;i<=n;++i)cin>>a[i];
        ll lim=1+(ll)sqrt(n);
        for(int i=0;i<m;++i){
            cin>>Qs[i].l>>Qs[i].r;
            Qs[i].i=i;Qs[i].b=Qs[i].l/lim;
        }
        sort(Qs,Qs+m);
        // cout<<"Qs: ";for(int i=0;i<m;++i)cout<<"("<<Qs[i].l<<","<<Qs[i].r<<") ";cout<<endl;
        for(int i=0,L=1,R=0;i<m;++i){
            Q &c=Qs[i];
            while(c.r>R)add(a[++R]);
            while(c.r<R)rmv(a[R--]);
            while(c.l<L)add(a[--L]);
            while(c.l>L)rmv(a[L++]);
            ans[c.i]=getans();
            // cout<<"("<<Qs[i].l<<","<<Qs[i].r<<") ans="<<ans[c.i]<<endl;
        }
        for(int i=0;i<m;++i)cout<<ans[i]<<endl;
    }
}
