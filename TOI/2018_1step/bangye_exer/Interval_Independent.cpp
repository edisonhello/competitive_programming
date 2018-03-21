#include<bits/stdc++.h>
using namespace std;

#define lb(x) ((x)&-(x))

int bit[200005],w[100005];
vector<pair<int,int>> a[200005];
pair<int,int> rec[100005];

void add(int x,int v){
    for(;x<200005;x+=lb(x))bit[x]=max(bit[x],v);
}
int query(int x,int v=0){
    for(;x;x-=lb(x))v=max(v,bit[x]);
    return v;
}

int main(){
    int t; cin>>t; while(t--){
        memset(bit,0,sizeof(bit));
        for(int i=0;i<200005;++i)a[i].clear();
        int n; cin>>n;
        int L=10000000,R=-1;
        vector<int> num;
        for(int i=0;i<n;++i){
            cin>>rec[i].first>>rec[i].second>>w[i];
            // a[r].emplace_back(l,w);
            num.push_back(rec[i].first);
            num.push_back(rec[i].second);
            // L=min(L,l);
            // R=max(R,r);
        }
        sort(num.begin(),num.end());
        for(int i=0;i<n;++i){
            rec[i].first=lower_bound(num.begin(),num.end(),rec[i].first)-num.begin()+1;
            rec[i].second=lower_bound(num.begin(),num.end(),rec[i].second)-num.begin()+1;
            a[rec[i].second].emplace_back(rec[i].first,w[i]);
            L=min(L,rec[i].first);
            R=max(R,rec[i].second);
        }
        for(int i=1;i<=200002;++i)sort(a[i].begin(),a[i].end());
        for(int i=L;i<=R;++i){
            for(auto seg:a[i]){
                add(i,query(seg.first)+seg.second);
            }
            // cout<<i<<" "<<query(i)<<endl;
        }
        cout<<query(R)<<endl;
    }
}
