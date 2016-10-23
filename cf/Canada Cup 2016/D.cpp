#include<bits/stdc++.h>
using namespace std;
int n;
#define ll long long
struct t{ll b,w;} te[300005];
ll bs[300005];
bool cmp_b(const t &a,const t &b){
    return a.b<b.b;
}
bool cmp_bd(const t &a,const t &b){
    if(a.b!=b.b)return a.b<b.b;
    return a.w-a.b>b.w-b.b;
}
ll b,w;
int lower;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    --n;
    cin>>b>>w;
    for(int i=0;i<n;++i){
        cin>>te[i].b>>te[i].w;
        bs[i]=te[i].b;
        // cout<<i<<" "<<te[i].b<<" "<<te[i].w<<endl;
    }
    // while(pq_.size()){
    //     cout<<pq_.top().b<<" ";pq_.pop();
    // }
    sort(bs,bs+n);
    sort(te,te+n,cmp_bd);
    int mx=999999;
    int alive=n;
    while(1){
        ll* lowb=lower_bound(bs,bs+n,b);
        --lowb;
        if(lowb-bs<0)break;
        mx=min(mx,alive-(lowb-bs));
        // cout<<lowb-bs<<endl;break;
        t tm__p={b,0};
        t* flo=lower_bound(te,te+n,tm__p,cmp_bd);

    }
    cout<<mx<<endl;

}
