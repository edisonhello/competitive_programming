#include<bits/stdc++.h>
using namespace std;

struct ans{
    int x,y,z; 
};
vector<ans> a;

int main(){
    int n; cin>>n;
    set<pair<int,int>> set0,set1;
    for(int i=1;i<=n;++i){
        int c,v; cin>>c>>v;
        (c?set1:set0).insert({v,i});
    }
    while(set1.size()+set0.size()>1){
        if(set1.begin()->first<set0.begin()->first || set0.size()==1u){
            auto pi=*(--set0.end());
            set0.erase(--set0.end());
            a.push_back({set1.begin()->second,pi.second,set1.begin()->first});
            pi.first-=set1.begin()->first;
            set1.erase(set1.begin());
            set0.insert(pi);
        }
        else{
            auto pi=*(--set1.end());
            set1.erase(--set1.end());
            a.push_back({set0.begin()->second,pi.second,set0.begin()->first});
            pi.first-=set0.begin()->first;
            set0.erase(set0.begin());
            set1.insert(pi);
        }
    }
    for(auto i:a){
        cout<<i.x<<" "<<i.y<<" "<<i.z<<endl;
    }
}
