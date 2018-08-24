#include<bits/stdc++.h>
using namespace std;

vector<int> G[425];

string s[425];
int deg[254];

void JIZZ(){
    cout<<"Impossible"<<endl;
    exit(0);
}

void dfs(int l,int r,int ptr){
    // cout<<"dfs "<<l<<" "<<r<<" "<<ptr<<endl;
    while(l<=r && s[l].size()<=ptr)++l;
    if(l>r)return;
    for(int i=l,j;i<=r;i=j){
        for(j=i;j<=r && s[j][ptr]==s[i][ptr];++j);
        if(j<=r)G[s[i][ptr]].push_back(s[j][ptr]);
        dfs(i,j-1,ptr+1);
    }
}

int main(){
    int n; cin>>n; 
    for(int i=1;i<=n;++i)cin>>s[i];
    for(int i=2;i<=n;++i){
        int sh=min(s[i-1].size(),s[i].size());
        if(s[i-1].substr(0,sh)==s[i].substr(0,sh) && s[i-1].size()>s[i].size())JIZZ();
    }
    dfs(1,n,0);
    queue<int> q;
    vector<int> ans;
    for(int i='a';i<='z';++i)for(int j:G[i])++deg[j];
    for(int i='a';i<='z';++i)if(deg[i]==0)q.push(i);
    while(q.size()){
        int now=q.front(); q.pop();
        ans.push_back(now);
        for(int i:G[now]){
            --deg[i];
            if(deg[i]==0)q.push(i);
        }
    }
    if(ans.size()<26)JIZZ();
    for(int i:ans)cout<<char(i);
}
