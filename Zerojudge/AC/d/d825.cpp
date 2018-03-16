#include<bits/stdc++.h>
using namespace std;

int a[100005],nxt[100005],prv[100005],djs[100005];
bitset<100005> v;
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
int main(){
    int ans=0;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i]>>a[i];
    for(int i=0;i<=n;++i)nxt[i]=i+1;
    for(int i=1;i<=n+1;++i)prv[i]=i-1;
    for(int i=0;i<=n+1;++i)djs[i]=i;
    auto cmp=[&](const int &x,const int &y)->bool{return a[x]<a[y];};
    priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
    for(int i=1;i<=n;++i)pq.push(i);
    while(pq.size()){
        while(pq.size() && v[F(pq.top())])pq.pop();
        if(pq.empty())break;
        int np=pq.top(); pq.pop();
        np=F(np);
        v[np]=1;
        ++ans;
        prv[nxt[np]]=prv[np];
        nxt[prv[np]]=nxt[np];
        if(a[prv[np]]==a[nxt[np]]){
            djs[nxt[np]]=prv[np];
            nxt[prv[np]]=nxt[nxt[np]];
            prv[nxt[prv[np]]]=prv[np];
        }
    }
    cout<<ans<<endl;
}
