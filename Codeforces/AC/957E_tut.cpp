#include<bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long

struct frac{
    ll u,d;
    void nrm(){
        ll g=__gcd(abs(u),abs(d));
        u/=g, d/=g;
        if(d<0)d*=-1,u*=-1;
    }
};
bool operator<(const frac &a,const frac &b){
    return a.u*b.d<a.d*b.u;
}
bool operator==(const frac &a,const frac &b){
    return a.u*b.d==a.d*b.u;
}
bool operator>(const frac &a,const frac &b){
    return a.u*b.d>a.d*b.u;
}

vector<frac> oppo;
pair<frac,frac> info[100005];

int bit[100005];

#define lb(x) ((x)&-(x))
void add(int x,int v){
    for(;x<100005;x+=lb(x))bit[x]+=v;
}
int query(int x,int v=0){
    for(;x;x-=lb(x))v+=bit[x];
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll w; cin>>w;
    for(int i=0;i<n;++i){
        ll x,v; cin>>x>>v;
        frac l={w+v,x},r{v-w,x};
        l.nrm(); r.nrm();
        info[i]={l,r};
        oppo.push_back(r);
        // cout<<l<<" "<<r<<endl;
    }
    sort(info,info+n,[](const pair<frac,frac> &a,const pair<frac,frac> &b){
        if(a.first==b.first)return a.second>b.second;
        else return a.first<b.first;
    });
    sort(oppo.begin(),oppo.end());
    /* for(auto i:oppo){
        cout<<i.u<<"/"<<i.d<<" ";
    } cout<<endl;
    for(int i=0;i<n;++i){
        cout<<"("<<info[i].first.u<<"/"<<info[i].first.d<<","<<info[i].second.u<<"/"<<info[i].second.d<<") ";
    } cout<<endl; */
    long long ans=0;
    for(int i=0;i<n;++i){
        // cout<<info[i].first<<" "<<info[i].second<<endl;
        frac x=info[i].second;
        int xx=lower_bound(oppo.begin(),oppo.end(),x)-oppo.begin();
        ans+=i-query(xx);
        add(xx+1,1);
        // cout<<xx<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
