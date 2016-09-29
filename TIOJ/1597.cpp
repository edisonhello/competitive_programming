#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
struct E{
    int d;ll c,p;
    friend bool operator < (const E &a,const E &b){
        return a.c+a.p*t < b.c+b.p*t;
    }
    friend bool operator > (const E &a,const E &b){
        return a.c+a.p*t > b.c+b.p*t;
    }
};

vector<E> G[40005];

int main(){
    int n,m,a,b,d;
    cin>>n>>m>>a>>b>>d;
    while(m--){
        int n1,n2,c1,p1,c2,p2;
        cin>>n1>>n2>>c1>>p1>>c2>>p2;
        G[n1].push_back({n2,c1,p1});
        G[n2].push_back({n1,c2,p2});
    }

    long long mx=-9;
    long long mn=(1ll<<60);
    for(t=0;t<=d;t++){
        {
            ll rd=0;
            {
                ll d[40005];
                memset(d,0x7f,sizeof(d));
                d[a]=0;
                bitset<40005> v;
                priority_queue<E,vector<E>,greater<E>> pq;
                pq.push({a,0,0});
                while(pq.size()){
                    while(pq.size() && v[pq.top().d]){
                        pq.pop();
                    }
                    int newc=pq.top().d;
                    v[newc]=1;
                    for(int i=0;i<(int)G[newc].size();i++){
                        E &cur=G[newc][i];
                        if(!v[cur.d] && d[newc]+cur.c+cur.p*t < d[cur.d]){
                            d[cur.d] = d[newc]+cur.c+cur.p*t;
                        }
                    }
                }
                rd+=d[b];
            }
            {
                ll d[40005];
                memset(d,0x7f,sizeof(d));
                d[b]=0;
                bitset<40005> v;
                priority_queue<E,vector<E>,greater<E>> pq;
                pq.push({b,0,0});
                while(pq.size()){
                    while(pq.size() && v[pq.top().d]){
                        pq.pop();
                    }
                    int newc=pq.top().d;
                    v[newc]=1;
                    for(int i=0;i<(int)G[newc].size();i++){
                        E &cur=G[newc][i];
                        if(!v[cur.d] && d[newc]+cur.c+cur.p*t < d[cur.d]){
                            d[cur.d] = d[newc]+cur.c+cur.p*t;
                        }
                    }
                }
                rd+=d[a];
            }
            mn=min(mn,rd);
        }
        {
            ll rd=0;
            {
                ll d[40005];
                memset(d,0x7f,sizeof(d));
                d[a]=0;
                bitset<40005> v;
                priority_queue<E,vector<E>,less<E>> pq;
                pq.push({a,0,0});
                while(pq.size()){
                    while(pq.size() && v[pq.top().d]){
                        pq.pop();
                    }
                    int newc=pq.top().d;
                    v[newc]=1;
                    for(int i=0;i<(int)G[newc].size();i++){
                        E &cur=G[newc][i];
                        if(!v[cur.d] && d[newc]+cur.c+cur.p*t > d[cur.d]){
                            d[cur.d] = d[newc]+cur.c+cur.p*t;
                        }
                    }
                }
                rd+=d[b];
            }
            {
                ll d[40005];
                memset(d,0x7f,sizeof(d));
                d[b]=0;
                bitset<40005> v;
                priority_queue<E,vector<E>,less<E>> pq;
                pq.push({b,0,0});
                while(pq.size()){
                    while(pq.size() && v[pq.top().d]){
                        pq.pop();
                    }
                    int newc=pq.top().d;
                    v[newc]=1;
                    for(int i=0;i<(int)G[newc].size();i++){
                        E &cur=G[newc][i];
                        if(!v[cur.d] && d[newc]+cur.c+cur.p*t > d[cur.d]){
                            d[cur.d] = d[newc]+cur.c+cur.p*t;
                        }
                    }
                }
                rd+=d[a];
            }
            mx=max(mx,rd);
        }
    }
    cout<<mx-mn<<endl;
}
