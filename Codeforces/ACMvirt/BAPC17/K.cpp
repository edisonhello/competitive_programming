#include<bits/stdc++.h>
using namespace std;

int n;
string G[1004];
vector<int> ans;
bitset<1004> v;

void dfs(int now){
    v[now]=1;
    for(int i=0;i<n;++i){
        if(G[now][i]=='1' && !v[i])dfs(i);
    }
    ans.push_back(now);
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>G[i];
    dfs(0);
    if(ans.size()!=n)cout<<"impossible"<<endl;
    else for(int i:ans){
        cout<<i<<" ";
    } cout<<endl;
}

