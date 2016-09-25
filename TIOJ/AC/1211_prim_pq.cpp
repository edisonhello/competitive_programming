#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m;
struct node{int pt,val;};
vector<node> G[10003];
bitset<10003> ined;
int dist[10003];
int ans;
int ppp,i;
priority_queue<node,vector<node>,greater<node>> pq;
bool operator>(const node &a,const node &b){
    return a.val>b.val;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m && n){
        for(i=1;i<=n;i++)G[i].clear();
        ined.reset();
        memset(dist,0,sizeof(dist));
        ans=0;
        while(pq.size())pq.pop();
        for(int i=0;i<m;i++){
            int z,x,c;
            cin>>z>>x>>c;
            G[z].push_back({x,c});
            G[x].push_back({z,c});
        }
        memset(dist,0x7f,sizeof(dist));
        dist[1]=0;
        pq.push({1,0});
        for(ppp=0;ppp<n;ppp++){
            int nowc=-1;
            while(pq.size() && ined[pq.top().pt]){
                pq.pop();
            }
            if(!pq.size()){
                break;
            }
            nowc=pq.top().pt;
            ined[nowc]=1;
            // cout<<"join:nowc:"<<nowc<<endl;
            ans+=pq.top().val;
            for(i=0;i<(int)G[nowc].size();i++){
                if(!ined[G[nowc][i].pt] && G[nowc][i].val < dist[G[nowc][i].pt]){
                    dist[G[nowc][i].pt]=G[nowc][i].val;
                    pq.push({G[nowc][i].pt,dist[G[nowc][i].pt]});
                }
            }
        }
        for(i=1;i<=n;i++){
            if(!ined[i]){
                cout<<"-1\n";
                goto jizz;
            }
        }
        cout<<ans<<"\n";
        jizz:;
    }
}
