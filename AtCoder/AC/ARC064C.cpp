#include<bits/stdc++.h>
using namespace std;

vector<pair<int,double>> G[1004];
int cc[1004][3];
double d[1004];
bitset<1004> v;

int main(){
    int sx,sy,tx,ty; cin>>sx>>sy>>tx>>ty;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>cc[i][0]>>cc[i][1]>>cc[i][2];
    tie(cc[0][0],cc[0][1])=make_pair(sx,sy);
    tie(cc[n+1][0],cc[n+1][1])=make_pair(tx,ty);
    for(int i=0;i<=n+1;++i){
        for(int j=0;j<i;++j){
            double d=sqrt(pow(cc[i][0]-cc[j][0],2)+pow(cc[i][1]-cc[j][1],2));
            d-=cc[i][2]+cc[j][2]; if(d<0)d=0;
            G[i].emplace_back(j,d);
            G[j].emplace_back(i,d);
            // cout<<i<<" "<<j<<" "<<d<<endl;
        }
    }
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
    for(int i=1;i<=n+1;++i)d[i]=1e12;
    pq.emplace(0,0);
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        int now=pq.top().second; pq.pop();
        v[now]=1;
        for(auto &p:G[now]){
            if(d[p.first]>d[now]+p.second+1e-10){
                d[p.first]=d[now]+p.second;
                pq.emplace(d[p.first],p.first);
            }
        }
    }
    cout<<fixed<<setprecision(12)<<d[n+1]<<endl;
}
