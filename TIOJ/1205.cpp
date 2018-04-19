#include<bits/stdc++.h>
using namespace std;

pair<int,int> pt[1555];

int main(){
    int n; while(cin>>n,n){
        long long ans=0;
        for(int i=0;i<n;++i)cin>>pt[i].first>>pt[i].second;
        for(int i=0;i<n;++i){
            auto cmp=[](const pair<int,int> &a,const pair<int,int> &b){
                return a.first*b.second-a.second*b.first>0;
            };
            map<pair<int,int>,int,decltype(cmp)> mp(cmp);
            for(int j=0;j<n;++j){
                if(i==j)continue;
                int dx=pt[j].first-pt[i].first,dy=pt[j].second-pt[i].second;
                if(dx==0)dy=1;
                else if(dy==0)dx=1;
                else{
                    int g=__gcd(dx,dy);
                    dx/=g, dy/=g;
                    if(dx<0)dx=-dx,dy=-dy;
                }
                ++mp[make_pair(dx,dy)];
            }
            for(auto it1=mp.begin(),it2=mp.begin();it1!=mp.end();++it1){
                while(it1->first.first*it2->first.first+it1->first.second*it2->first.second>0){
                    ++it2;
                    if(it2==mp.end())it2=mp.begin();
                }
                if(it1->first.first*it2->first.first+it1->first.second*it2->first.second==0){
                    ans+=it1->second*it2->second;
                }
            }
        }
        cout<<ans<<endl;
    }
}
