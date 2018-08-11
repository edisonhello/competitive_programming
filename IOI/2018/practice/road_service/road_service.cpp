#include<bits/stdc++.h>
using namespace std;

vector<int> G[1111];

int n,d[1111];
bitset<1111> v;
void go(int s){
    v.reset();
    memset(d,0,sizeof(d));
    queue<int> q; q.push(s);
    v[s]=1;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i:G[now]){
            if(v[i])continue;
            d[i]=d[now]+1;
            q.push(i);
            v[i]=1;
        }
    }
}

void meow(){
    go(0);
    int x=max_element(d,d+n)-d;
    go(x);
    int y=max_element(d,d+n)-d;
    G[x].push_back(y);
    G[y].push_back(x);
    cout<<x<<" "<<y<<endl;
}

int main(){
    int k,w; cin>>n>>k>>w;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while(k--){
        meow();
    }
}
