#include<bits/stdc++.h>
using namespace std;
#define lb(x) ((x)&-(x))

vector<pair<int,int>> seg;

void lisan(){
    vector<int> num;
    for(auto i:seg){
        num.push_back(i.first);
        num.push_back(i.second);
    }
    sort(num.begin(),num.end());
    for(auto &i:seg){
        i.first=lower_bound(num.begin(),num.end(),i.first)-num.begin()+1;
        i.second=lower_bound(num.begin(),num.end(),i.second)-num.begin()+1;
    }
}


int bit[200005];
void add(int x,int v){
    x=200004-x;
    for(;x<200006;x+=lb(x)){
        bit[x]=max(bit[x],v);
    }
}
int query(int x,int v=0){
    x=200004-x;
    for(;x;x-=lb(x)){
        v=max(v,bit[x]);
    }
    return v;
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int s,t; cin>>s>>t;
        seg.emplace_back(s,t);
    }
    lisan();
    sort(seg.begin(),seg.end(),[](const pair<int,int> &a,const pair<int,int> &b){
        return a.second==b.second?a.first>b.first:a.second<b.second;
    });
    int ans=0;
    for(auto p:seg){
        int hi=query(p.first);
        ++hi;
        ans=max(ans,hi);
        add(p.first,hi);
    }
    cout<<ans<<endl;
}
