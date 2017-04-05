#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<long long,long long>
#define X first
#define Y second

int n;
bool v[12345];
ll j[12334],d[12345];
struct pnt{ll x,y;} p[13244];
priority_queue<pii,vector<pii >,greater<pii > > pq;

ll dist(int i,int j){
    return (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
}
ll meow(int root){
    for(int i=0;i<n;++i)d[i]=999999999999999999ll;
    d[root]=0; pq.push(pii(0,root)); ll mx=0;
    while(pq.size()){
        while(pq.size() && v[pq.top().Y])pq.pop();
        if(pq.empty())break;
        v[pq.top().Y]=1;
        mx=max(mx,pq.top().X);
        int npt=pq.top().Y;
        for(int i=0;i<n;++i){
            if(!v[i] && dist(npt,i)<d[i]){
                d[i]=dist(npt,i);
                pq.push(pii(d[i],i));
            }
        }
    }
    return mx;
}

int main(){
    int m;
    while(cin>>m){
        memset(v,0,sizeof(v)); memset(j,0,sizeof(j));
        memset(d,0,sizeof(d)); memset(p,0,sizeof(p));
        while(pq.size())pq.pop();
        for(int i=0;i<m;++i)cin>>j[i];
        cin>>n;
        for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
        ll d=meow(0); int ans=0;
        for(int i=0;i<m;++i)if(j[i]*j[i]>=d)++ans;
        cout<<ans<<endl;
    }
}
