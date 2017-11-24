#include<bits/stdc++.h>
using namespace std;

struct side{
    set<int> x;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,less<pair<int,pair<int,int>>>> pq;
    void init(int n){
        x.insert(0); x.insert(n);
        pq.push(make_pair(n,make_pair(0,n)));
    }
    void cut(int pos){
        auto it=x.lower_bound(pos);
        auto it2=it; --it;
        pq.push(make_pair(*it2-pos,make_pair(pos,*it2)));
        pq.push(make_pair(pos-*it,make_pair(*it,pos)));
        x.insert(pos);
    }
    long long max(){
        while(*(++x.lower_bound(pq.top().second.first))!=pq.top().second.second)pq.pop();
        return pq.top().first;
    }
} x,y;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w,h,n; cin>>w>>h>>n;
    x.init(w); y.init(h);
    while(n--){
        string s; cin>>s;
        int pos; cin>>pos;
        if(s=="H")y.cut(pos);
        else x.cut(pos);
        cout<<x.max()*y.max()<<endl;
    }
}
