#include<queue>
#include<iostream>
using namespace std;
#define int long long

struct st{int s,t,w;};
bool operator<(const st &a,const st &b){return a.w<b.w;}
bool operator>(const st &a,const st &b){return a.w>b.w;}

priority_queue<st,vector<st>,greater<st>> pq;

int djs[10005];
int F(int x){if(x==djs[x])return x;return djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}
bool C(int x,int y){return F(x)==F(y);}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int ts;cin>>ts;while(ts--){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;++i)djs[i]=i;
        while(pq.size())pq.pop();
        while(m--){
            int u,v,c;cin>>u>>v>>c;
            pq.push({u,v,c});
        }
        int ans=0;
        for(int i=1;i<n;++i){
            while(pq.size() && C(pq.top().s,pq.top().t))pq.pop();
            ans+=pq.top().w;
            U(pq.top().s,pq.top().t);
        }
        cout<<ans<<endl;
    }
}
