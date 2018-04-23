#include<bits/stdc++.h>
using namespace std;

int ans[200005];
int a[200005],per[200005],bit[200005];
vector<int> num;

void add(int x,int v=1){
    for(;x<200005;x+=x&-x)bit[x]+=v;
}
int query(int x,int v=0){
    for(;x;x-=x&-x)v+=bit[x];
    return v;
}

struct Q{
    int l,r,v,i;
};
vector<Q> qs;

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],num.push_back(a[i]);
    sort(num.begin(),num.end());
    for(int i=1;i<=n;++i)a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=n;++j){
            long long l=1ll*i*(j-1)+2,r=i*j+1;
            r=min((long long)n,r);
            if(l>r)break;
            // cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
            qs.push_back({l,r,a[j],i});
        }
    }
    for(int i=1;i<=n;++i)per[i]=i;
    sort(per+1,per+1+n,[&](const int &aa,const int &b){return a[aa]<a[b];});
    // for(int i=1;i<=n;++i)cout<<per[i]<<endl;
    sort(qs.begin(),qs.end(),[](const Q &a,const Q &b){return a.v<b.v;});
    int ptr=1;
    for(Q q:qs){
        while(ptr<=n && a[per[ptr]]<q.v)add(per[ptr],1),++ptr;
        ans[q.i]+=query(q.r)-query(q.l-1);
    }
    for(int i=1;i<=n-1;++i)cout<<ans[i]<<" ";

}
