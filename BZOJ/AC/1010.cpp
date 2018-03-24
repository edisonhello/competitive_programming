#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int long long

ll c[50005],pre[50005],l;
ll dp[50005];

ll sq(ll x){
    return x*x;
}
ll get(ll x){
    return sq(l-x);
}

ll get_bf(int n){
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;++i){
        int cf=-1;
        for(int j=i;j>=1;--j){
            ll v=dp[j-1]+sq(pre[i]-pre[j-1]+i-j-l);
            if(v<dp[i]){
                dp[i]=v;
                cf=j-1;
            }
        }
        cout<<i<<" "<<cf<<endl;
    }
    return dp[n];
}

struct line{
    ll m,y,i;
    ll get(ll x){return m*x+y;}
};

#ifdef this_is_not_code
dp[i] = min (0<=j<i) {
    dp[j] + ( L - (i-j-1) - (pre[i]-pre[j]) )^2
  = dp[j] + ( (L+j+1+pre[j]) - (i+pre[i]) )^2
  = dp[j] + (L+j+1+pre[j])^2 + (i+pre[i])^2 + (i+pre[i]) * -2*(L+j+1+pre[j])
   -------------------------  ------------   ----------  --------------------
}
#endif

bool kill(line b2,line b1,line nl){
    // return (b2.y-b1.y)*(b2.m-nl.m)>=(nl.y-b2.y)*(b1.m-b2.m);
    return (ld)(b2.y-b1.y)/(b1.m-b2.m)>=(ld)(b2.y-nl.y)/(nl.m-b2.m);
}

int32_t main(){
    int n; cin>>n;
    cin>>l;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;++i)cin>>c[i],pre[i]=pre[i-1]+c[i];
    deque<line> dq;
    /* dp[1]=get(c[1])+sq(l+1);
    dq.pu sh_back({-2*(l+1),sq(l+1)}); */
    dq.push_back({-2*(l+1),sq(l+1),0});
    for(int i=1;i<=n;++i){
        // cout<<"dping "<<i<<endl;
        ll x=i+pre[i];
        while(dq.size()>1u && dq[0].get(x)>=dq[1].get(x))dq.pop_front();
        dp[i]=dq[0].get(x)+sq(i+pre[i]);
        // cout<<dq[0].get(x)<<" "<<sq(i+pre[i])<<" from "<<dq[0].i<<endl;
        // cout<<"from "<<dq[0].i<<endl;
        line nl={-2*(l+i+1+pre[i]),dp[i]+sq(l+i+1+pre[i]),i};
        while(dq.size()>1u && kill(dq[dq.size()-2],dq[dq.size()-1],nl))dq.pop_back();
        dq.push_back(nl);
    }
    // for(int i=1;i<=n;++i)cout<<dp[i]<<" "; cout<<endl;
    cout<<dp[n]<<endl;
    // cout<<get_bf(n)<<endl;
}
