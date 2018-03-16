#pragma GCC optimize("O")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll p[18];
vector<ll> pa,pb;

void dfs(vector<ll> &v,int ptr,ll x){
    if(ptr>n){
        v.push_back(x);
        return;
    }
    dfs(v,ptr+2,x);
    for(;;){
        ll xx=x*p[ptr];
        if(xx/x!=p[ptr] || xx>1000000000000000000ll)break;
        x=xx;
        dfs(v,ptr+2,x);
    }
}

ll get(ll x){
    ll rt=0;
    auto it1=pa.begin(),it2=--pb.end();
    for(;it1!=pa.end();++it1){
        bool no=0;
        while(1){
            ll xx=(*it1)*(*it2);
            if(xx>x || xx/(*it1)!=(*it2)){
                if(it2==pb.begin()){no=1; break;}
                --it2;
            }
            else break;
        }
        if(no)break;
        rt+=it2-pb.begin()+1;
    }
    // cout<<"get "<<x<<" is "<<rt<<endl;
    return rt;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i];
    ll k; cin>>k;
    dfs(pa,1,1);
    dfs(pb,2,1);
    sort(pa.begin(),pa.end());
    sort(pb.begin(),pb.end());
    ll x=0,step(1ll<<61);
    while(step){
        if(x+step<=1000000000000000000ll && get(x+step)<k)x+=step;
        step>>=1;
    }
    cout<<x+1<<endl;
}
