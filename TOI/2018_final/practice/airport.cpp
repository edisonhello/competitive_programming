#include<bits/stdc++.h>
using namespace std;

int c[10004];
vector<pair<int,pair<int,int>>> G;

int main(){
    int ts; cin>>ts; while(ts--){
        int n,m; cin>>n>>m;
        for(int i=0;i<n;++i)G.clear();
        for(int i=0;i<n;++i)cin>>c[i];
        for(int u,v,w,i=0;i<m;++i){
            cin>>u>>v>>w;
            G.emplace_back(w,make_pair(u,v));
        }
        int ans=INT_MAX;
        {
            sort(G.begin(),G.end());
            vector<int> d(n);
            iota(d.begin(),d.end(),0);
            function<int(int)> F=[&](int x)->int{ return x==d[x]?x:d[x]=F(d[x]); };
            int mst=0;
            for(auto i:G){
                i.second.first=F(i.second.first);
                i.second.second=F(i.second.second);
                if(i.second.first==i.second.second)continue;
                d[i.second.first]=i.second.second;
                mst+=i.first;
            }
            set<int> dd;
            for(int i:d)dd.insert(F(i));
            if(dd.size()==1u)ans=min(ans,mst);
        }
        {
            int x=min_element(c,c+n)-c;
            int mst=c[x];
            // cout<<"get x: "<<x<<endl;
            for(int i=0;i<n;++i){
                if(i!=x)G.emplace_back(c[i],make_pair(i,x));
            }
            sort(G.begin(),G.end());
            vector<int> d(n);
            iota(d.begin(),d.end(),0);
            function<int(int)> F=[&](int x)->int{ return x==d[x]?x:d[x]=F(d[x]); };
            for(auto i:G){
                i.second.first=F(i.second.first);
                i.second.second=F(i.second.second);
                if(i.second.first==i.second.second)continue;
                d[i.second.first]=i.second.second;
                // cout<<"merge "<<i.second.first<<" "<<i.second.second<<endl;
                mst+=i.first;
            }
            set<int> dd;
            for(int i:d)dd.insert(F(i));
            if(dd.size()==1u)ans=min(ans,mst);
        }
        cout<<ans<<endl;
    }
}
