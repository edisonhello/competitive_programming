#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,r;

struct pos{
    int x,y;
    ll area;
    pos(int x,int y):x(x),y(y){
        int u=x-r+1,d=x+r-1;
        u=max(1,u); d=min(n,d);
        d=d-r+1;
        int l=y-r+1,rr=y+r-1;
        l=max(1,l); rr=min(m,rr);
        rr=rr-r+1;
        area=1ll*(d-u+1)*(rr-l+1);
    }
};

bool operator<(const pos &a,const pos &b){
    return a.area<b.area;
}

set<pair<int,int>> u;
int main(){
    int k; cin>>n>>m>>r>>k;
    priority_queue<pos,vector<pos>,less<pos>> pq;
    pq.push(pos((n+1)/2,(m+1)/2));
    u.insert({(n+1)/2,(m+1)/2});
    ll totarea=0;
    while(k--){
        totarea+=pq.top().area;
        int x=pq.top().x,y=pq.top().y; pq.pop();
        if(x>1 && u.find({x-1,y})==u.end()){
            u.insert({x-1,y});
            pq.push(pos(x-1,y));
        }
        if(y>1 && u.find({x,y-1})==u.end()){
            u.insert({x,y-1});
            pq.push(pos(x,y-1));
        }
        if(x<n && u.find({x+1,y})==u.end()){
            u.insert({x+1,y});
            pq.push(pos(x+1,y));
        }
        if(y<m && u.find({x,y+1})==u.end()){
            u.insert({x,y+1});
            pq.push(pos(x,y+1));
        }
    }
    cout<<fixed<<setprecision(20)<<(long double)totarea/(1ll*(n-r+1)*(m-r+1))<<endl;
}
