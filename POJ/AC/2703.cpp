#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long

int main(){
    int n; while(cin>>n){
        if(n==-1)break;
        map<int,vector<int>,greater<int> > mp;
        while(n--){
            int w,h; cin>>w>>h;
            if(w>h)swap(w,h);
            mp[w].push_back(h);
        }
        int prv=0;
        ll ans=0;
        for(map<int,vector<int>,greater<int> >::iterator it=mp.begin();it!=mp.end();++it){
        // for(auto it:mp){
            sort(it->second.begin(),it->second.end(),greater<int>());
            if(it->second.size()<2u)exit(7122);
            if(!prv){
                ans+=it->first*(it->second[0]+it->second[1]-it->first);
                prv=it->second[0]+it->second[1];
            }
            else{
                ans+=it->first*(it->second[0]+it->second[1]-prv);
                prv=it->second[0]+it->second[1];
            }
        }
        cout<<ans<<endl;
    }
}
