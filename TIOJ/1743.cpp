#include<bits/stdc++.h>
using namespace std;

struct seg{
    int l,r,i;
} a[200005];

int bit[400005];

inline void add(int x,int v){
    for(;x<400005;x+=x&-x)bit[x]=max(bit[x],v);
}
inline int qry(int x,int v=0){
    for(;x;x-=x&-x)v=max(v,bit[x]);
    return v;
}

inline void radd(int x,int v){
    for(;x;x-=x&-x)bit[x]=max(bit[x],v);
}
inline int rqry(int x,int v=0){
    for(;x<400005;x+=x&-x)v=max(bit[x],v);
    return v;
}

inline void padd(int x,int v){
    for(;x<400005;x+=x&-x)bit[x]+=v;
}
inline int pqry(int x,int v=0){
    for(;x;x-=x&-x)v+=bit[x];
    return v;
}

int rtl[200005],ltr[200005],pos[200005];
bitset<200005> u;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> num;
    for(int i=1;i<=n;++i)cin>>a[i].l>>a[i].r,a[i].i=i;
    for(int i=1;i<=n;++i)num.push_back(a[i].l),num.push_back(a[i].r);
    sort(num.begin(),num.end());
    num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=1;i<=n;++i)a[i].l=upper_bound(num.begin(),num.end(),a[i].l)-num.begin();
    for(int i=1;i<=n;++i)a[i].r=upper_bound(num.begin(),num.end(),a[i].r)-num.begin();
    // for(int i=1;i<=n;++i)cout<<a[i].l<<" - "<<a[i].r<<endl;
    sort(a+1,a+1+n,[](const seg &a,const seg &b){return a.l>b.l;});
    for(int i=1,v;i<=n;++i){
        rtl[a[i].i]=v=rqry(a[i].r+1)+1;
        radd(a[i].l,v);
        // cout<<"rtl: "<<a[i].l<<" "<<a[i].r<<" "<<a[i].i<<" v: "<<v<<endl;
    }
    sort(a+1,a+1+n,[](const seg &a,const seg &b){return a.r<b.r;});
    memset(bit,0,sizeof(bit));
    for(int i=1,v;i<=n;++i){
        ltr[a[i].i]=v=qry(a[i].l-1)+1;
        add(a[i].r,v);
        // cout<<"ltr: "<<a[i].l<<" "<<a[i].r<<" "<<a[i].i<<" v: "<<v<<endl;
    }
    int mx=0;
    for(int i=1;i<=n;++i)mx=max(mx,rtl[i]+ltr[i]);
    cout<<mx-1<<endl;
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;++i)pos[a[i].i]=i;
    for(int i=1;i<=n;++i){
        if(rtl[i]+ltr[i]!=mx)continue;
        if(u[ltr[i]])continue;
        if(pqry(a[pos[i]].r))continue;
        padd(a[pos[i]].l,1);
        padd(a[pos[i]].r+1,-1);
        u[ltr[i]]=1;
        cout<<i<<" ";
    }
    cout<<endl;
}
