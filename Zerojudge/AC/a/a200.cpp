#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct item{
    int l,r,from;
    bool useless(){return l>r;}
};

ll a,b,c,x[1000006],p[1000006],dp[1000006];

ll sq(ll x){return x*x;}
ll get(ll i,ll j){
    return dp[j]+a*sq(p[i]-p[j])+b*(p[i]-p[j])+c;
}

int main(){
    int n;
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;++i)cin>>x[i],p[i]=p[i-1]+x[i];
    p[n+1]=p[n];
    deque<item> dq; dq.push_back({1,n+1,0});
    for(int i=1;i<=n;++i){
        dp[i]=get(i,dq.front().from);
        ++dq.front().l;
        if(dq.front().useless())dq.pop_front();
        while(dq.size() && get(dq.back().l,i)>=get(dq.back().l,dq.back().from))dq.pop_back();
        if(dq.size()){
            if(get(dq.back().r,i)>=get(dq.back().r,dq.back().from)){
                int L=dq.back().l+1,R=dq.back().r;
                while(R>L){
                    int mid=(L+R)>>1;
                    if(get(mid,i)>=get(mid,dq.back().from))R=mid;
                    else L=mid+1;
                }
                dq.back().r=L-1;
            }
        }
        if(dq.size() && dq.back().r!=n+1)dq.push_back({dq.back().r+1,n+1,i});
        else if(dq.empty())dq.push_back({i+1,n+1,i});
    }
    cout<<dp[n]<<endl;
}
