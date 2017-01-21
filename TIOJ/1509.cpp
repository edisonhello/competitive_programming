#include<iostream>
using namespace std;
#include<queue>
#include<vector>

struct st{int now,team,dist;};
bool cmp_d(const st &a,const st &b){return a.dist<b.dist;}
vector<pair<int,int>> G[1000005];
vector<int> ls[1000005];
int len[1000005];
priority_queue<st,vector<st>,decltype(&cmp_d)> pq(cmp_d);

int main(){
    ios_base::sync_with_stdio(0);
    int m,n;cin>>m>>n;
    for(int i=1;i<=n;++i)len[i]=1e9+7;
    while(n--){
        int p,q,r;cin>>p>>q>>r;
        G[p].push_back({q,r});
    }
    len[1]=0;
    
}
