#include<bits/stdc++.h>
using namespace std;
#define lb(x) ((x)&-(x))

int a[200005],rbit[600005],lbit[600005],rlen[200005],llen[200005];

void add(int *bit,int x,int v){
    for(;x<600005;x+=lb(x))bit[x]=max(bit[x],v);
}
int query(int *bit,int x,int v=0){
    for(;x;x-=lb(x))v=max(v,bit[x]);
    return v;
}

int main(){
    int n; cin>>n;
    vector<int> num;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        num.push_back(a[i]-i);
        num.push_back(a[i]-i+1);
        num.push_back(a[i]-i-1);
    }
    sort(num.begin(),num.end());
    auto get=[&](int x){return lower_bound(num.begin(),num.end(),x)-num.begin();};
    for(int i=n;i>=1;--i){
        int x=get(a[i]-(i-1));
        int v=query(rbit,600003-x);
        rlen[i]=v+1;
        add(rbit,600003-x,v+1);
    }
    for(int i=1;i<=n;++i){
        int x=get(a[i]-i);
        int v=query(lbit,x);
        llen[i]=v+1;
        add(lbit,x,v+1);
    }
    int mn=1<<30;
    // for(int i=1;i<=n;++i)cout<<llen[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;++i)cout<<rlen[i]<<" "; cout<<endl;
    for(int i=1;i<=n;++i)mn=min(mn,(n-1)-(llen[i-1]+rlen[i+1]-(i>1 && i<n && a[i+1]-i<a[i-1]-(i-1))));
    cout<<mn<<endl;
}
