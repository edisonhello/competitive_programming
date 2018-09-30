#include<bits/stdc++.h>
using namespace std;



int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<pair<int,int>> ans;
    int n; cin>>n; while(n--){
        string s; cin>>s;
        if(s=="insert"){
            int x; cin>>x;
            pq.push(x);
            ans.emplace_back(1,x);
        }
        if(s=="getMin"){
            int x; cin>>x;
            while(pq.size() && pq.top()<x){
                pq.pop();
                ans.emplace_back(3,0);
            }
            if(pq.empty() || pq.top()>x){
                ans.emplace_back(1,x);
                pq.push(x);
            }
            ans.emplace_back(2,x);
        }
        if(s=="removeMin"){
            if(pq.empty())ans.emplace_back(1,1),pq.push(1);
            ans.emplace_back(3,0);
            pq.pop();
        }
    }
    cout<<ans.size()<<endl;
    for(auto &p:ans){
        if(p.first==1)cout<<"insert "<<p.second<<'\n';
        if(p.first==2)cout<<"getMin "<<p.second<<'\n';
        if(p.first==3)cout<<"removeMin"<<'\n';
    }
}
