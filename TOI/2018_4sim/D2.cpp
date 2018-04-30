#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;

vector<pair<int,int>> G[200005];
vector<pair<int,int>> pp[200005];
double last[200005];

// priority_queue<pair<double,int>,vector<pair<double,int>>,less<pair<double,int>>> pq;
queue<int> pq;
void go(){
    while(pq.size()){
        int now=pq.front(); pq.pop();
        for(auto &p:G[now]){
            if(last[p.first]<last[now]-p.second){
                last[p.first]=last[now]-p.second;
                pq.push(p.first);
            }
        }
    }
}

//#define getchar getchar_unlocked
int rit(){
    char c; int x=0;
    while((c=getchar())!=-1 && (c<'0' || c>'9'));
    do{ x=x*10+(c&15); c=getchar(); }while(c>='0' && c<='9');
    return x;
}

int main(){
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int n=rit(),m=rit(),k=rit();
    for(int i=1,u,v,l;i<=m;++i){
        u=rit(),v=rit(),l=rit();
        G[u].emplace_back(v,l);
        G[v].emplace_back(u,l);
    }
    for(int i=0,p,r,d;i<k;++i){
        p=rit(),r=rit(),d=rit();
        pp[p].emplace_back(r,d);
    }
    auto check=[&](double pw)->bool{
//        cout<<"checking "<<pw<<endl;
        while(pq.size())pq.pop();
        memset(last,0,sizeof(last));
        for(int i=1;i<=n;++i){
            for(auto &p:pp[i]){
                // pq.emplace(p.first+pw*p.second,i);
                pq.push(i);
                last[i]=max(last[i],p.first+pw*p.second);
            }
        }
        go();
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

