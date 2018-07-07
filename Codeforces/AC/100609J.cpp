#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[100005];
int bit[100005];

int query(int x,int v=0){
    for(;x<100005;x+=x&-x)v+=bit[x];
    return v;
}
void add(int x,int v){
    for(;x;x-=x&-x)bit[x]+=v;
}

int main(){
    freopen("john.in","r",stdin);
    freopen("john.out","w",stdout);
    int n; cin>>n;
    vector<int> num;
    for(int i=0;i<n;++i)cin>>a[i].first>>a[i].second;
    for(int i=0;i<n;++i)num.push_back(a[i].second);
    sort(num.begin(),num.end());
    sort(a,a+n);
    long long ans=0;
    for(int i=0;i<n;++i){
        int v=lower_bound(num.begin(),num.end(),a[i].second)-num.begin()+2;
        ans+=query(v+1);
        add(v,1);
        // cout<<ans<<" "<<v<<endl;
    }
    cout<<ans<<endl;
}
