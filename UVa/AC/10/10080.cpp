#include<bits/stdc++.h>
using namespace std;
#define ld long double

int match[111];
vector<int> G[111];
pair<ld,ld> pos[111];
bitset<111> v;

bool dfs(int now){
    // cout<<"now is "<<now<<endl;
    for(int i:G[now]){
        if(v[i])continue;
        // cout<<"try edge "<<now<<" to "<<i<<endl;
        v[i]=1;
        if(match[i]==-1 || dfs(match[i])){
            // cout<<"change match of "<<i<<" from "<<match[i]<<" to "<<now<<endl;
            match[i]=now;
            return 1;
        }
    }
    return 0;
}


int main(){
    int n,m,s,vv; while(cin>>n>>m>>s>>vv){
        for(int i=0;i<111;++i)G[i].clear();
        for(int i=0;i<n;++i)cin>>pos[i].first>>pos[i].second;
        for(int i=0;i<m;++i){
            ld x,y; cin>>x>>y;
            for(int j=0;j<n;++j){
                if(sqrt(pow(x-pos[j].first,2)+pow(y-pos[j].second,2))-1e-7<=s*vv){
                    // cout<<j<<" -> "<<i<<endl;
                    G[j].push_back(i);
                }
            }
        }
        memset(match,0xff,sizeof(match));
        int ans=0;
        for(int i=0;i<n;++i){
            // if(match[i]==-1){
                v.reset();
                // cout<<"go i "<<i<<endl;
                if(dfs(i))++ans;
            // }
        }
        // for(int i=0;i<m;++i)cout<<i<<" "<<match[i]<<endl;
        cout<<n-ans<<endl;
    }
}
