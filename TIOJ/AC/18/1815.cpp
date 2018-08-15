#include<bits/stdc++.h>

using namespace std;

int putaway(int a, int b, int t, int x[], int y[], int w[], int s[]) {
    // cout<<"in: putaway"<<endl;
    if([&]()->bool{
        int xmx=0,ymx=0;
        for(int i=0;i<a;++i)xmx=max(xmx,x[i]);
        for(int i=0;i<b;++i)ymx=max(ymx,y[i]);
        for(int i=0;i<t;++i)if(w[i]>=xmx && s[i]>=ymx)return 1;
        return 0;
    }())return -1;
    vector<pair<int,int>> pz(t);
    for(int i=0;i<t;++i)pz[i].first=w[i],pz[i].second=s[i];
    sort(pz.begin(),pz.end());
    sort(x,x+a);
    sort(y,y+b);
    int L=1,R=t;
    while(R>L){
        // cout<<"BS range "<<L<<" to "<<R<<endl;
        int M=(L+R)>>1;
        if([&](int T)->bool{
            priority_queue<int,vector<int>,less<int>> pq;
            int pzt=0;
            for(int i=0;i<a;++i){
                // cout<<"i: "<<i<<endl;
                while(pzt<t && pz[pzt].first<x[i])pq.push(pz[pzt++].second);
                for(int z=0;z<T;++z)if(pq.size())pq.pop(); else break;
            }
            while(pzt<t)pq.push(pz[pzt++].second);
            for(int i=b-1;i>=0;--i){
                // cout<<"i: "<<i<<endl;
                if(pq.size() && pq.top()>=y[i])return 0;
                for(int z=0;z<T;++z)if(pq.size())pq.pop(); else break;
            }
            return pq.empty();
        }(M))R=M;
        else L=M+1;
    }
    return L;
}

int x[50005],y[50005],w[1000006],s[1000006];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,z; cin>>n>>m>>z;
    for(int i=0;i<n;++i)cin>>x[i];
    for(int i=0;i<m;++i)cin>>y[i];
    for(int i=0;i<z;++i)cin>>w[i]>>s[i];
    cout<<putaway(n,m,z,x,y,w,s)<<'\n';
}
