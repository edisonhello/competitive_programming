#include<bits/stdc++.h>
using namespace std;
#define ld long double

pair<int,int> a[102],b[102];
vector<int> G[122];
int match[122];
bitset<122> v;

double dis(pair<int,int> a,pair<int,int> b){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

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
        for(int i=0;i<122;++i)G[i].clear();
        for(int i=0;i<n;++i){
            cin>>a[i].first>>a[i].second;
        }
        for(int i=0;i<m;++i)cin>>b[i].first>>b[i].second;
        for(int i=0;i<n-1;++i){
            for(int j=0;j<m;++j){
                if(dis(a[i],a[i+1])*2>dis(a[i],b[j])+dis(a[i+1],b[j])){
                    G[i].push_back(j);
                }
            }
        }
        --n;
        memset(match,-1,sizeof(match));
        int cnt=n+1;
        for(int i=0;i<n;++i){
            v.reset();
            if(dfs(i))++cnt;
        }
        cout<<cnt<<endl;
        for(int i=0;i<n;++i){
            cout<<a[i].first<<" "<<a[i].second<<" ";
            for(int j=0;j<m;++j){
                if(match[j]==i){
                    cout<<b[j].first<<" "<<b[j].second<<" ";
                    break;
                }
            }
        }
        cout<<a[n].first<<" "<<a[n].second<<endl;

        if(ts)cout<<endl;
    }
}
