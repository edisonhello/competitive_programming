#include<bits/stdc++.h>
using namespace std;

struct Q{
    int l,r,k,i;
};
vector<Q> qs;
vector<int> pos[50005];

int a[50005],ans[50005],bit[50005];

void add(int x,int v){
    for(;x<50005;x+=x&-x)bit[x]+=v;
}
int query(int x,int v=0){
    for(;x;x-=x&-x)v+=bit[x];
    return v;
}

void bs(int l,int r,vector<Q> &qs){
    // cout<<"bs: "<<l<<" "<<r<<endl;
    int mid=(l+r)>>1;
    vector<int> apos,bit_ops;
    for(int i=l;i<=mid;++i){
        for(int j:pos[i])apos.push_back(j);
    }
    sort(apos.begin(),apos.end());
    int c_inbit=0,apos_ptr=0;
    vector<Q> lq,rq;
    for(auto &q:qs){
        while(apos_ptr<apos.size() && apos[apos_ptr]<=q.r){
            ++c_inbit;
            add(apos[apos_ptr],1);
            bit_ops.push_back(apos[apos_ptr]);
            ++apos_ptr;
        }
        int inr=c_inbit-query(q.l-1);
        if(inr>=q.k){
            ans[q.i]=mid;
            lq.push_back(q);
        }
        else{
            q.k-=inr;
            rq.push_back(q);
        }
    }
    for(int i:bit_ops)add(i,-1);
    if(l==r)return;
    bs(l,mid,lq);
    bs(mid+1,r,rq);
}

vector<int> num;

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        num.push_back(a[i]);
    }
    sort(num.begin(),num.end());
    for(int i=1;i<=n;++i){
        a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin();
        pos[a[i]].push_back(i);
    }
    int q; cin>>q;
    for(int i=0;i<q;++i){
        int l,r,k; cin>>l>>r>>k;
        ++l, ++r; k=r-l-k+2;
        qs.push_back({l,r,k,i});
    }
    sort(qs.begin(),qs.end(),[](const Q &a,const Q &b){return a.r<b.r;});
    bs(0,n-1,qs);
    for(int i=0;i<q;++i)cout<<num[ans[i]]<<'\n';
}
