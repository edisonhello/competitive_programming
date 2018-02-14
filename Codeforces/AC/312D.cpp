#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int long long

int m;
ll t[100005],pre[100005];
ll d[123456];
ll dp[105][100005];

struct line{
    int i;
    ll m,y;
    ll get(ld x){return m*x+y;}
};

ld inter(line l1,line l2){
    return (ld)(l1.y-l2.y)/(l2.m-l1.m);
}

main(){
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

    for(int i=1;i<=m;++i)dp[1][i]=t[i]*i-pre[i];
    for(int i=2;i<=p;++i){
        deque<line> q; q.push_back({0,0,0});
        for(int j=1;j<=m;++j){
            while(q.size()>1 && q[0].get(t[j])>=q[1].get(t[j]))q.pop_front();
            dp[i][j]=t[j]*j-pre[j]+q[0].get(t[j]);
            line nline={j,-j,dp[i-1][j]+pre[j]};
            while(q.size()>1 && inter(nline,q[q.size()-2])<=inter(q[q.size()-2],q.back()))q.pop_back();
            q.push_back(nline);
        }
    }

    /* for(int i=1;i<=p;++i){
        for(int j=1;j<=m;++j){
            cout<<dp[i][j]<<" ";
        } cout<<endl;
    } */

    cout<<dp[p][m]<<endl;
}

