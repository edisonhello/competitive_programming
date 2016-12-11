#include<iostream>
using namespace std;
#include<queue>
#include<cstring>
#define int long long
struct _{int a,c;
bool operator<(const _ &a)const{return c<a.c;}
bool operator>(const _ &a)const{return c>a.c;}};
priority_queue<_,vector<_>,greater<_>> pq;
int n,m,st,ed;
int G[1005][1005];
int d[1005];
bool v[1005];
signed main(){
    while(cin>>n>>m){
        cin>>st>>ed;--st,--ed;
        while(pq.size())pq.pop();
        memset(G,-1,sizeof(G));
        for(int i=0;i<n;++i)d[i]=(1ll<<40);
        memset(v,0,sizeof(v));
        int a,b,c;while(m--){
            cin>>a>>b>>c;--a,--b;
            G[a][b]=G[b][a]=c;
        }
        d[st]=0;
        pq.push({st,0});
        for(int iii=0;iii<n;++iii){
            while(pq.size() && v[pq.top().a]){pq.pop();}
            if(pq.empty())break;
            v[pq.top().a]=1;
            for(int i=0;i<n;++i){
                if(~G[pq.top().a][i] && d[pq.top().a]+G[pq.top().a][i]<d[i]){
                    d[i]=d[pq.top().a]+G[pq.top().a][i];
                    pq.push({i,d[i]});
                }
            }
        }
        if(d[ed]==(1ll<<40))cout<<"He is very hot\n";
        else cout<<d[ed]<<endl;
    }
}
