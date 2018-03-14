#include<bits/stdc++.h>
using namespace std;
#ifdef WEAK
#include"../template/debug.cpp"
#else
#define PDE(...) ;
#endif

int a[300005],cnt[1000006];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    priority_queue<int,vector<int>,greater<int>> pq;
    long long ans=0;
    for(int i=1;i<=n;++i){
        pq.push(a[i]);
        if(pq.top()<a[i]){
            int bp=pq.top(); pq.pop();
            ans+=a[i]-bp;
            ++cnt[a[i]];
            if(cnt[bp])--cnt[bp],pq.push(bp);
        }
        PDE(i,a[i],ans,pq);
    }
    cout<<ans<<endl;
}
