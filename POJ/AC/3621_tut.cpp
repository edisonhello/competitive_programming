#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<cstring>
#include<iomanip>
#define ld long double

using namespace std;

vector<pair<int,int>> G[1111];

int n,w[1111];

int upd[1111];
long double d[1111];
bitset<1111> inq;
bool test(long double m){
    memset(upd,0,sizeof(upd));
    queue<int> q;
    inq.reset();
    for(int i=1;i<=n;++i)d[i]=0,q.push(i),inq[i]=1;
    while(q.size()){
        int now=q.front(); q.pop(); inq[now]=0;
        // cout<<"now: "<<now<<endl;
        for(int ii=0;ii<G[now].size();++ii){
            pair<int,int> &i=G[now][ii];
            if(d[i.first]>d[now]-w[now]+i.second*m){
                d[i.first]=d[now]-w[now]+i.second*m;
                ++upd[i.first];
                if(upd[i.first]>n)return 1;
                if(!inq[i.first]){
                    inq[i.first]=1;
                    q.push(i.first);
                }
            }
        }
    }
    return 0;
}

int main(){
    int m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=m;++i){
        int u,v,ww; cin>>u>>v>>ww;
        G[u].push_back(pair<int,int>(v,ww));
    }
    long double L=0,R=1e12;
    while(R-L>1e-5){
        // cout<<L<<" "<<R<<endl;
        long double mid=(L+R)/2;
        if(!test(mid))R=mid;
        else L=mid;
    }
    if(L<1e11)cout<<fixed<<setprecision(2)<<L<<endl;
    else cout<<0<<endl;
}
