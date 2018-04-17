#include<bits/stdc++.h>
using namespace std;

int bit[400005];
pair<int,int> a[200005];

void add(int x,int v){
    for(;x<400005;x+=x&-x)bit[x]=max(bit[x],v);
}
int query(int x,int v=0){
    for(;x;x-=x&-x)v=max(v,bit[x]);
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> num;
    for(int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        num.push_back(a[i].first+a[i].second);
        num.push_back(a[i].first-a[i].second);
    }
    sort(num.begin(),num.end());
    int ans=1;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        int mip=lower_bound(num.begin(),num.end(),a[i].first-a[i].second)-num.begin()+1;
        int q=query(mip);
        ++q;
        ans=max(ans,q);
        int adp=lower_bound(num.begin(),num.end(),a[i].first+a[i].second)-num.begin()+1;
        add(adp,q);
    }
    cout<<ans<<endl;
}
