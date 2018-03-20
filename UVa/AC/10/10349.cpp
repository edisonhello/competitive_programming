#include<bits/stdc++.h>
using namespace std;

int match[1322];
string mp[123];
vector<int> G[1000];
bitset<1232> v;

bool dfs(int now){
    for(int i:G[now]){
        if(v[i])continue;
        v[i]=1;
        if(match[i]==-1 || dfs(match[i])){
            match[i]=now;
            return 1;
        }
    }
    return 0;
}

int main(){
    int ts; cin>>ts; while(ts--){
        int n,m; cin>>n>>m;
        for(int i=0;i<n*m;++i)G[i].clear();
        for(int i=0;i<n;++i)cin>>mp[i];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mp[i][j]=='o')continue;
                if(j&&mp[i][j-1]=='*'){
                    // cout<<i<<" "<<j<<" L"<<endl;
                    G[i*m+j].push_back(i*m+j-1);
                    G[i*m+j-1].push_back(i*m+j);
                }
                if(i&&mp[i-1][j]=='*'){
                    // cout<<i<<" "<<j<<" U"<<endl;
                    G[(i-1)*m+j].push_back(i*m+j);
                    G[i*m+j].push_back((i-1)*m+j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)for(char c:mp[i])if(c=='*')++ans;
        memset(match,0xff,sizeof(match));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if((i+j)&1)continue;
                v.reset();
                if(dfs(i*m+j)){
                    --ans;
                }
            }
        }
        cout<<ans<<endl;
    }
}
