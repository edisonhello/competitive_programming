#include<bits/stdc++.h>
using namespace std;

#define lb(x) ((x)&-(x))

int bit[100005];
vector<pair<int,int>> a[100005];

void add(int x,int v){
    x=100002-x;
    for(;x<100005;x+=lb(x))bit[x]=min(bit[x],v);
}
int query(int x,int v=1<<30){
    x=100002-x;
    for(;x;x-=lb(x))v=min(v,bit[x]);
    return v;
}

int main(){
    int t; cin>>t; while(t--){
        memset(bit,0x3f,sizeof(bit));
        for(int i=0;i<100005;++i)a[i].clear();
        int n; cin>>n;
        int L=10000000,R=-1;
        for(int i=0;i<n;++i){
            int l,r,w; cin>>l>>r>>w;
            ++l;
            a[r].emplace_back(l,w);
            L=min(L,l);
            R=max(R,r);
        }
        for(int i=1;i<=100002;++i)sort(a[i].begin(),a[i].end());
        add(L-1,0);
        for(int i=L;i<=R;++i){
            for(auto seg:a[i]){
                add(i,query(seg.first-1)+seg.second);
            }
            // cout<<i<<" "<<query(i)<<endl;
        }
        cout<<query(R)<<endl;
    }
}
