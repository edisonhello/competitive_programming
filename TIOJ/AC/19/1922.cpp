#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

struct Query{
    int l,r,i,block;
    inline bool operator < (const Query &a) const {
        return this->block==a.block?this->r<a.r:this->block<a.block;
    }
};

const int Z=1e9+7;
int n,m,lim,now,a[40004],idl[40004],ans[400005],in[400005];
Query q[400005];
map<int,int> mp;

int gid(int in){
    auto it=mp.find(in);
    if(it==mp.end()){
        mp[in]=mp.size();
    }
    return mp[in];
}

void add(int idx){
    int x=a[idx];
    int id=idl[idx];
    int c=++in[id];
    now+=x*((c<<1)-1);
    now%=Z;
}
void rmv(int idx){
    int x=a[idx];
    int id=idl[idx];
    int c=--in[id];
    now-=x*((c<<1)+1);
    now%=Z;
    while(now<0)now+=Z;
}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,id;i<n;++i){
        cin>>a[i];
        id=gid(a[i]);
        idl[i]=id;
    }
    lim=1+(int)sqrt(n);
    for(int i=0;i<m;++i){
        cin>>q[i].l>>q[i].r;
        --q[i].r;
        q[i].block=q[i].l/lim;
        q[i].i=i;
    }
    sort(q,q+m);
    for(int i=0,l=0,r=-1;i<m;++i){
        while(r<q[i].r)add(++r);
        while(r>q[i].r)rmv(r--);
        while(l>q[i].l)add(--l);
        while(l<q[i].l)rmv(l++);
        ans[q[i].i]=now%Z;
    }
    for(int i=0;i<m;++i){
        cout<<ans[i]<<endl;
    }
}
