#include<bits/stdc++.h>
using namespace std;

struct pt{
    int x,w,ad,mn;
};
vector<pt> p;
vector<int> num;

#define lb(x) ((x)&-(x))

int bit[400008];
void add(int x,int v){
    for(;x<400008;x+=lb(x))bit[x]=max(bit[x],v);
}
int qry(int x,int v=0){
    for(;x;x-=lb(x))v=max(v,bit[x]);
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int x,w; cin>>x>>w;
        p.push_back({x,w,x+w,x-w});
        num.push_back(x+w);
        num.push_back(x-w);
    }
    sort(num.begin(),num.end()); for(auto &i:p){
        i.ad=lower_bound(num.begin(),num.end(),i.ad)-num.begin();
        i.mn=lower_bound(num.begin(),num.end(),i.mn)-num.begin();
    }
    sort(p.begin(),p.end(),[](const pt &a,const pt &b){return a.x>b.x;});
    int mx=0;
    for(auto &i:p){
        // cout<<i.x<<" "<<i.w<<" "<<i.ad<<" "<<i.mn<<endl;
        int ans=qry(400005-i.ad)+1;
        mx=max(mx,qry(400005-i.ad));
        add(400005-i.mn,ans);
    }
    cout<<mx+1<<endl;
}
