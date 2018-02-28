#include<bits/stdc++.h>
using namespace std;

vector<int> pr[60006];
map<pair<int,int>,int> ans;

int query(int a,int b){
    if(pr[a].size()<pr[b].size())swap(a,b);
    int &rt=ans[make_pair(a,b)];
    if(rt!=0)return rt;
    rt=9999999;
    int aptr=0;
    for(int i:pr[b]){
        // auto it=lower_bound(pr[a].begin(),pr[a].end(),i);
        while(aptr<pr[a].size() && pr[a][aptr]<i)++aptr;
        if(aptr<pr[a].size())rt=min(rt,pr[a][aptr]-i);
        if(aptr)rt=min(rt,i-pr[a][aptr-1]);
    }
    if(rt==9999999)rt=-1;
    return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        int t; cin>>t; 
        // while(pr[t].size()>1 && pr[t].back()==i-1 && pr[t][pr[t].size()-2]==i-2)pr[t].pop_back();
        pr[t].push_back(i);
    }
    while(m--){
        int a,b; cin>>a>>b;
        cout<<query(a,b)<<'\n';
    }
}
