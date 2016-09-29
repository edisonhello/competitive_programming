#include<bits/stdc++.h>
using namespace std;
int t;
struct E{
    int d,c,p;
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
    long long mn=(1<<60);
    for(t=0;t<=d;t++){
        {
        int d[40005];
        memset(d,0x7f,sizeof(d));
        d[0]=0;
        bitset<40005> v;
        priority_queue<E,vector<E>,greater<E>> pq;
        pq.push({0,0,0});
        long long c=0;
        while(pq.size()){
            while(pq.size() && v[pq.top().d]){
                pq.pop();
            }
            int newc=pq.top().d;
            c += (pq.top().c+pq.top().p*t);
            v[newc]=1;
            for(int i=0;i<(int)G[newc].size();i++){
                E &cur=G[newc][i];
                if(!v[cur.d] && d[newc]+cur.c+cur.p*t < d[cur.d]){
                    d[cur.d] = d[newc]+cur.c+cur.p*t;
                }
            }
        }
        mn=min(mn,c);
        }
        {
        int d[40005];
        memset(d,0x7f,sizeof(d));
        d[0]=0;
        bitset<40005> v;
        priority_queue<E,vector<E>,less<E>> pq;
        pq.push({0,0,0});
        long long c=0;
        while(pq.size()){
            while(pq.size() && v[pq.top().d]){
                pq.pop();
            }
            int newc=pq.top().d;
            c += (pq.top().c+pq.top().p*t);
            v[newc]=1;
            for(int i=0;i<(int)G[newc].size();i++){
                E &cur=G[newc][i];
                if(!v[cur.d] && d[newc]+cur.c+cur.p*t > d[cur.d]){
                    d[cur.d] = d[newc]+cur.c+cur.p*t;
                }
            }
        }
        mx=max(mx,c);
        }
    }
    cout<<mx-mn<<endl;
}
