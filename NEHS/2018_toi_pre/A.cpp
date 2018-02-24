/* WA
dp[i] = min(j<i) { dp[j] + (ti+K-ti) * xi + (ti+K-t{i-1}) * x{i-1} + ... + (ti+K-t{j+1}) * x{j+1} }
      = min(j<i) { dp[j] + (ti+K) * (pre_x[i] - pre_x[j]) - (pre_tx[i] - pre_tx[j]) }
      = min(j<i) { - (ti+K) * pre_x[j] + pre_tx[j] + dp[j]} - pre_tx[i] + (ti+K) * pre_x[i]
                   ~~~~~~~   ~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~
                      x        slope        offset
*/
/*
dp[i] = min(j<=i-k) { dp[j] + (i+K-tp) * xp ... }
      = min(j<=i-k) { dp[j] + (i+K)*all_x_in(j+1,i) - all_xt_in(j+1,i) }
      = min(j<=i-k) { dp[j] + (i+K)*pre_x(i) - (i+K)*pre_x(j) - pre_xt(i) + pre_xt(j) }
      = min(j<=i-k) { - (i+K) * pre_x(j) + pre_xt(j) + dp[j] } - pre_xt(i) + (i+K)*pre_x(i)
                      ~~~~~~~  ~~~~~~~~~   ~~~~~~~~~~~~~~~~~
                         x       slope          offset
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pre_x[4000005],pre_tx[4000005],x[100005],t[100005],dp[4000005];

struct line{
    ll m,y; int i;
    ll get(ll x){return m*x+y;}
};

long double inter(line l1,line l2){
    return (long double)(l1.y-l2.y)/(l2.m-l1.m);
}

template<typename T>void printq(T q){
    while(q.size()){
        cout<<q.front().i<<" ";
        q.pop_front();
    } cout<<endl;
}
template<typename T>void everyq(T q,int v){
    while(q.size()){
        cout<<q.front().get(v)<<" ";
        q.pop_front();
    } cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; ll k; cin>>n>>k;
    deque<line> q; q.push_back({0,0,0});
    for(int i=1;i<=n;++i){
        cin>>t[i]>>x[i];
        pre_x[t[i]]+=x[i];
        pre_tx[t[i]]+=x[i]*t[i];
    }
    for(int i=1;i<=4000000;++i)pre_x[i]+=pre_x[i-1],pre_tx[i]+=pre_tx[i-1];
    deque<line> qqq;
    ll ans=1ll<<60;
    for(int i=1;i<=4000000;++i){
        while(q.size()>1 && q[0].get(-i-k) >= q[1].get(-i-k))q.pop_front();
        dp[i]=q.front().get(-i-k)-pre_tx[i]+(i+k)*pre_x[i];
        // cout<<"dp["<<i<<"]="<<dp[i]<<" , get from: "<<q.front().i<<endl;
        // cout<<"now q have "; printq(q);
        // if(i==9)everyq(q,-i-k);
        line nline={pre_x[i],pre_tx[i]+dp[i],i};
        qqq.push_back(nline);
        if(qqq.size()>=k){
            // cout<<"qqq"<<endl;
            nline=qqq.front(); qqq.pop_front();
            while(q.size()>1 && inter(q.back(),q[q.size()-2]) <= inter(nline,q[q.size()-2]))q.pop_back();
            if(q.size() && q.back().m==nline.m && q.back().y<=nline.y);
            else q.push_back(nline);
        }
    }
    // for(int i=0;i<=15;++i)cout<<"dp["<<i<<"]="<<dp[i]<<endl;
    for(int i=t[n];i<=4000000;++i)ans=min(ans,dp[i]);
    cout<<ans<<endl;
}
