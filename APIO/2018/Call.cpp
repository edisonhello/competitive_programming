#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> G[100005],mem[100005],bel[100005],bG[100005];
int in[100005],low[100005],dt,sz[100005];
stack<int> pts;
int cbcc;
bitset<100005> vis,isside;

ll tot=0;

void dfs(int now,int pa){
    in[now]=low[now]=++dt;
    int ch=0;
    pts.push(now);
    for(int i:G[now]){
        if(i==pa)continue;
        if(in[i]){
            low[now]=min(low[now],in[i]);
        }
        else{
            ++ch;
            dfs(i,now);
            low[now]=min(low[now],low[i]);
        }
    }
    if(low[now]==in[now]){
        ++cbcc;
        while(pts.top()!=now){
            mem[cbcc].push_back(pts.top());
            bel[pts.top()].push_back(cbcc);
            pts.pop();
        }
        mem[cbcc].push_back(pts.top());
        bel[pts.top()].push_back(cbcc);
    }
}
void dfs1(int now,int pa,int acnt){
    sz[now]=mem[now].size();
    vis[now]=1;
    for(int i:bG[now]){
        if(i==pa)continue;
        dfs1(i,now,acnt);
        sz[now]+=sz[i]-1;
    }
    for(int i:bG[now]){
        if(i==pa)continue;
        cout<<now<<endl;
        cout<<sz[i]<<" "<<mem[now].size()-1<<" "<<acnt-mem[now].size()-sz[i]+1<<endl;
        tot+=1ll*(sz[i])*(mem[now].size()-1)*(acnt-mem[now].size()-sz[i]+1)*2;
    }
}
int dfs2(int now,int pa){
    int rt=mem[now].size();
    for(int i:bG[now]){
        if(i==pa)continue;
        rt+=dfs2(i,now)-1;
    }
    return rt;
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        if(!in[i])dfs(i,i);
    }

    for(int i=1;i<=cbcc;++i){
        tot+=1ll*mem[i].size()*(mem[i].size()-1)*(mem[i].size()-2);
    }
//    cout<<cbcc<<endl;
    for(int i=1;i<=n;++i){
        if(bel[i].size()>1){
            for(int j=1;j<bel[i].size();++j){
                bG[bel[i][0]].push_back(bel[i][j]);
            }
        }
    }
    for(int i=1;i<=cbcc;++i){
        if(vis[i])continue;
        ;
        dfs1(i,i,dfs2(i,i));
    }
    cout<<tot<<endl;
}
