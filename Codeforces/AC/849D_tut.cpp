#include<bits/stdc++.h>
using namespace std;

pair<int,int> *ans[100005];

struct item{
    vector<pair<int,int>> ori,dst;
    void add(int i,int id,int dx,int dy){
        ori.emplace_back(i,id);
        dst.emplace_back(dx,dy);
    }
    void proc(){
        sort(ori.begin(),ori.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;});
        sort(dst.begin(),dst.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.first==b.first?a.second>b.second:a.first<b.first;});
        for(int i=0;i<ori.size();++i){
            ans[ori[i].first]=&dst[i];
        }
    }
};

unordered_map<int,item> pt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,w,h; cin>>n>>w>>h;
    for(int i=1;i<=n;++i){
        int g,p,t; cin>>g>>p>>t;
        if(g==1){
            int x=p,y=-t;
            pt[x+y].add(i,x,x,h);
        }
        else{
            int x=-t,y=p;
            pt[x+y].add(i,x,w,y);
        }
    }
    for(auto &i:pt)i.second.proc();
    for(int i=1;i<=n;++i)cout<<ans[i]->first<<" "<<ans[i]->second<<endl;
}
