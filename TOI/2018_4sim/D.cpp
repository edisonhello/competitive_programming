#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;

vector<pair<int,int>> G[200005];
vector<pair<int,int>> pp[200005];
double last[200005];

void go(int s,double len){
    if(last[s]>=len-eps)return;
    last[s]=len;
    priority_queue<pair<double,int>,vector<pair<double,int>>,less<pair<double,int>>> pq;
    pq.emplace(len,s);
    while(pq.size()){
        int now=pq.top().second; pq.pop();
        for(auto &p:G[now]){
            if(last[p.first]<last[now]-p.second){
                last[p.first]=last[now]-p.second;
                pq.emplace(last[p.first],p.first);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,l; cin>>u>>v>>l;
        G[u].emplace_back(v,l);
        G[v].emplace_back(u,l);
    }
    for(int i=0;i<k;++i){
        int p,r,d; cin>>p>>r>>d;
        pp[p].emplace_back(r,d);
    }
    auto check=[&](double pw)->bool{
//        cout<<"checking "<<pw<<endl;
        memset(last,0,sizeof(last));
        for(int i=1;i<=n;++i){
            for(auto &p:pp[i]){
                go(i,p.first+pw*p.second);
            }
        }
        for(int i=1;i<=n;++i){
            for(auto j:G[i]){
                if(last[i]+last[j.first]+eps<j.second){
                    return 0;
                }
            }
        }
        return 1;
    };
    int cnt=60;
    double L=0,R=3e15;
    while(cnt--){
        unsigned long long LL=*(unsigned long long*)(&L),RR=*(unsigned long long*)(&R);
        unsigned long long MM=(LL+RR)/2;
        double t=*(double*)(&MM);
//        cout<<"t: "<<t<<endl;
        // double m=(L+R)/2;
        if(check(t))R=t;
        else L=t;
    }
    if(L>2e15)cout<<-1<<endl;
    else cout<<fixed<<setprecision(12)<<L<<endl;
}
