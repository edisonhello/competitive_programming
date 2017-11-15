#include<bits/stdc++.h>
using namespace std;

vector<int> v,u;
unordered_map<string,int> mp;
int main(){
    int n,m; cin>>n>>m;
    while(n--){
        int t; cin>>t; v.push_back(t);
    }
    string s; while(m--){
        cin>>s; mp[s]++;
    }
    for(auto i:mp)u.push_back(i.second);

    sort(v.begin(),v.end());
    sort(u.begin(),u.end(),greater<int>());
    int tot=0;
    for(int i=0;i<u.size();++i)tot+=v[i]*u[i];
    cout<<tot<<" ";
    reverse(v.begin(),v.end());
    tot=0;
    for(int i=0;i<u.size();++i)tot+=v[i]*u[i];
    cout<<tot<<endl;
}
