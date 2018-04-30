#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000006];
bitset<1000006> is_loop,is_end;
int deg[1000006],connect_to[1000006],side_len[1000006],loop_to[1000006],count_side,loop_size;
vector<int> connecting[1000006];

int _dfs1_len=0;
int dfs1(int now,int pa){
    if(is_loop[now])return now;
    for(int i:G[now]){
        if(i==pa)continue;
        ++_dfs1_len;
        return dfs1(i,now);
    }
}

int loop_start;
void dfs2(int now,int pa){
    // cout<<"now: "<<now<<endl;
    if(now==loop_start && now!=pa)return;
    ++loop_size;
    for(int i:G[now]){
        if(i==pa)continue;
        if(!is_loop[i])continue;
        loop_to[now]=i;
        dfs2(i,now);
        return;
    }
}

int dp[4][1000006];
void dfs3(int now,int pa,int lid){
    connect_to[now]=lid;
    dp[1][now]=dp[2][now]=G[now].size();
    if(G[now].size()==1)return;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs3(i,now,lid);
    }
    for(int i:G[now])if(i!=pa){
        dp[1][now]=max(dp[1][now],(int)G[now].size()-1+dp[1][i]);
    }
    dp[2][now]=dp[1][now];
    vector<int> vals;
    for(int i:G[now])if(i!=pa){
        vals.push_back(dp[1][i]);
    }
    sort(vals.begin(),vals.end(),greater<int>());
    while(vals.size()<2u)vals.push_back(0);
    dp[2][now]=max(dp[2][now],(int)G[now].size()-2+vals[0]+vals[1]);
}

int main(){
    freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1,a,b;i<=n;++i){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        ++deg[a]; ++deg[b];
    }
    { // get loop
        is_loop.set();
        queue<int> q;
        for(int i=1;i<=n;++i){
            if(deg[i]==1)q.push(i),is_loop[i]=0,is_end[i]=1;
        }
        while(q.size()){
            int now=q.front(); q.pop();
            for(int i:G[now]){
                if(!is_loop[i])continue;
                --deg[i];
                if(deg[i]==1 && is_loop[i]){
                    is_loop[i]=0;
                    q.push(i);
                }
            }
        }
//        for(int i=1;i<=n;++i)if(is_loop[i])cout<<i<<" is loop"<<endl;
    }
    { // order loop
        for(int i=1;i<=n;++i)if(is_loop[i]){loop_start=i; break;}
        dfs2(loop_start,loop_start);
    }
    int ans=3;
    {
        for(int i=1;i<=n;++i){
            if(!is_loop[i])continue;
            for(int j:G[i]){
                if(is_loop[j])continue;
                dfs3(j,i,i);
            }
        }
        for(int i=1;i<=n;++i)if(!is_loop[i])ans=max(ans,dp[2][i]+1);
        // for(int i=1;i<=n;++i)cout<<"dp of "<<i<<" : "<<dp[1][i]<<" "<<dp[2][i]<<endl;
    }
    for(int i=1;i<=n;++i)if(is_loop[i])count_side+=G[i].size()-2;
    {
        ans=max(ans,loop_size+count_side);
        int st_point=0;
        for(int i=1;i<=n;++i)if(is_loop[i]){st_point=i; break;}
        for(int u=st_point,v2=0;;u=loop_to[u]){
            if(u==st_point)++v2;
            if(v2>=2)break;
            for(int i:G[u]){
                if(is_loop[i])continue;
                ans=max(ans,loop_size+dp[1][i]+count_side-1);
                int now_loop=0;
                int near=0;
                for(int v=u,vv2=0;;v=loop_to[v]){
                    if(v==u)++vv2;
                    if(vv2>=2)break;
                    ++now_loop;
                    near+=G[v].size()-2;
                    for(int j:G[v]){
                        if(is_loop[j])continue;
                        if(j==i)continue;
                        int add=2;
                        if(loop_to[v]==u)add=0;
                        else if(loop_to[loop_to[v]]==u)add=1;
                        ans=max(ans,now_loop+add+dp[1][i]+dp[1][j]+near-2);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

