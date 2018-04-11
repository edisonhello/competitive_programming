#include<bits/stdc++.h>
using namespace std;

long long b,c;
long long n,k,t[200005],a[200005];
long long pre[200005],cost[200005];

long long go(int r){
    // `cout<<"r: "<<r<<endl;
    long long bottom=-1e9-10;
    while((bottom%5+5)%5!=r)++bottom;
    for(int i=1;i<=n;++i){
        a[i]=t[i];
        // costpre[i]=costpre[i-1];
        cost[i]=0;
        while((a[i]%5+5)%5!=r){
            ++a[i];
            cost[i]+=c;
        }
        pre[i]=pre[i-1]+a[i];
        // cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    long long mn=1ll<<60,now=0;
    priority_queue<long long,vector<long long>,less<long long>> pq;
    for(int i=1;i<=k;++i){
        long long in=-a[i]/5*b+cost[i];
        now+=in;
        // cout<<i<<" "<<in<<" "<<cost[i]<<" "<<now<<endl;
        pq.push(in);
    }
    for(int L=1,R=k;R<=n;++L,++R){
        mn=min(mn,a[R]/5*k*b+now);
        long long in=-a[R+1]/5*b+cost[R+1];
        now+=in;
        pq.push(in);
        long long out=pq.top();
        pq.pop();
        now-=out;
    }
    // cout<<mn<<endl;
    return mn;
}

int main(){
    cin>>n>>k>>b>>c;
    b=min(b,c*5);
    for(int i=1;i<=n;++i)cin>>t[i],t[i]+=1000000000;
    sort(t+1,t+n+1);
    long long ans=go(0);
    cout<<min(ans,min(go(1),min(go(2),min(go(3),go(4)))))<<endl;
}
