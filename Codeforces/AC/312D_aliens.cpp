#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int m;
ll t[100005],pre[100005];
ll d[123456];
ld dp[100005];
int connect[100005];

struct line{
    int i;
    ld m,y;
    ld get(ld x){return m*x+y;}
};

ld inter(line l1,line l2){
    return (l1.y-l2.y)/(l2.m-l1.m);
}

int use(ld cost){
    // cout<<"calc cost: "<<cost<<endl;
    memset(dp,0,sizeof(dp));
    deque<line> q; q.push_back({0,0,0});
    for(int i=1;i<=m;++i){
        while(q.size()>1 && q[0].get(t[i])>=q[1].get(t[i]))q.pop_front();
        dp[i]=t[i]*i+cost-pre[i]+q[0].get(t[i]);
        connect[i]=q[0].i;
        line nline={i,-i,dp[i]+pre[i]};
        while(q.size()>1 && inter(nline,q[q.size()-2])<=inter(q[q.size()-2],q.back()))q.pop_back();
        q.push_back(nline);
    }
    int cnt=0,idx=m;
    while(idx){
        idx=connect[idx];
        ++cnt;
    }
    // cout<<"cnt: "<<cnt<<endl;
    // cout<<"dps: "; for(int i=1;i<=m;++i)cout<<dp[i]<<" "; cout<<endl;
    // cout<<"con: "; for(int i=1;i<=m;++i)cout<<connect[i]<<" "; cout<<endl;
    return cnt;
}

int main(){
    int n,p; cin>>n>>m>>p;
    for(int i=2;i<=n;++i)cin>>d[i];
    for(int i=3;i<=n;++i)d[i]+=d[i-1];
    for(int i=1;i<=m;++i){
        int h; ll tt; cin>>h>>tt;
        t[i]=tt-d[h];
    }
    sort(t+1,t+m+1);
    for(int i=1;i<=m;++i)pre[i]=pre[i-1]+t[i];
    // cout<<"t: "; for(int i=1;i<=m;++i)cout<<t[i]<<" "; cout<<endl;
    ld L=0,R=1e12,ans,ndp;
    while(R-L>1e-6){
        ld M=(L+R)/2;
        if(use(M)>p)L=M;
        else R=M,ans=M,ndp=dp[m];
    }
    cout<<fixed<<setprecision(0)<<ndp-ans*p<<endl;
}
