// Codeforces 320E
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll h[100005],c[100005],dp[100005];

struct line{
    ll m,y;
    ll get(ll x){return m*x+y;}
};
#define ld long double

ld interx(line l1,line l2){
    return (ld)(l2.y-l1.y)/(l1.m-l2.m);
}

bool useless(line befbef,line bef,line nline){
    return interx(befbef,bef)>=interx(befbef,nline);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>h[i];
    for(int i=1;i<=n;++i)cin>>c[i];
    deque<line> q; q.push_back({c[1],0});
    for(int i=2;i<=n;++i){
        while(q.size()>1 && q[0].get(h[i])>=q[1].get(h[i]))q.pop_front();
        dp[i]=q.front().get(h[i]);
        line newline={c[i],dp[i]};
        while(q.size()>1 && useless(q.back(),q[q.size()-2],newline))q.pop_back();
        q.push_back(newline);
    }
    cout<<dp[n]<<endl;
}
