#include<bits/stdc++.h>
using namespace std;

int G[234][234];
bitset<234> v;
vector<pair<char,char>> ans;

void dfs(int now){
    v[now]=1;
    for(int i='a';i<='z';++i){
        if(G[now][i] && !v[i]){
            ans.emplace_back(now,i);
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string s,t; cin>>s>>t;
    for(int i=0;i<n;++i){
        if(s[i]!=t[i]){
            G[s[i]][t[i]]=G[t[i]][s[i]]=1;
        }
    }
    for(int i='a';i<='z';++i){
        if(!v[i])dfs(i);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
}
