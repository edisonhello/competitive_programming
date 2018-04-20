#include<bits/stdc++.h>
using namespace std;

pair<int,int> pt[1555];

int main(){
    int n; while(cin>>n,n){
        long long ans=0;
        for(int i=0;i<n;++i)cin>>pt[i].first>>pt[i].second;
        for(int i=0;i<n;++i){
            /* auto cmp=[](const pair<int,int> &a,const pair<int,int> &b)->bool{
                if(a.second==0 && b.second==0)return a.first>b.first;;
                if(a.second==0)return 1;
                if(b.second==0)return 0;
                if(a.second>=0 && b.second<0)return 1;
                return 1ll*a.first*b.second-1ll*a.second*b.first>0;
                // return atan2(a.second,a.first)<atan2(b.second,b.first);
            }; */
            // map<pair<int,int>,int,decltype(cmp)> mp(cmp);
            map<pair<int,int>,int> mp;
            for(int j=0;j<n;++j){
                if(i==j)continue;
                int dx=pt[j].first-pt[i].first,dy=pt[j].second-pt[i].second;
                if(dx==0)dy/=abs(dy);
                else if(dy==0)dx/=abs(dx);
                else{
                    int g=abs(__gcd(dx,dy));
                    dx/=g, dy/=g;
                }
                // if(i==0)cout<<" j "<<j<<" "<<dx<<" "<<dy<<endl;
                ++mp[make_pair(dx,dy)];
            }
            // if(i==0)
            // cout<<"pivot: "<<pt[i].first<<" , "<<pt[i].second<<" , map: \n";
            // for(auto p:mp)cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
            for(auto it1=mp.begin();it1!=mp.end();++it1){
                int dx=-it1->first.second,dy=it1->first.first;
                auto it2=mp.find(make_pair(dx,dy));
                if(it2!=mp.end())ans+=it1->second*it2->second;
            }
        }
        cout<<ans<<endl;
    }
}
