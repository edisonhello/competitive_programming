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

int main(){
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
    { // get side connect to loop's id
        for(int i=1;i<=n;++i){
            if(!is_end[i])continue;
            _dfs1_len=0;
            connect_to[i]=dfs1(i,i);
            side_len[i]=_dfs1_len;
            connecting[connect_to[i]].push_back(i);
            ++count_side;
            cout<<i<<" connect to "<<connect_to[i]<<" , len: "<<side_len[i]<<endl;
        }
    }
    { // order loop
        for(int i=1;i<=n;++i)if(is_loop[i]){loop_start=i; break;}
        dfs2(loop_start,loop_start);
//        for(int i=1;i<=n;++i)if(is_loop[i])cout<<i<<" connect to "<<loop_to[i]<<endl;
//        cout<<"loop_size: "<<loop_size<<endl;
    }
    int ans=3;
    {
        ans=max(ans,loop_size+count_side);
        for(int i=1;i<=n;++i){
            if(!is_end[i])continue;
            cout<<"start at end: "<<i<<endl;
            ans=max(ans,loop_size+count_side-1+side_len[i]);
            int c_to_loop_id=connect_to[i],go_loop_len=0;
            for(int u=c_to_loop_id,v2=0;;u=loop_to[u]){
                if(u==c_to_loop_id)++v2;
                cout<<"now u:"<<u<<endl;
                if(v2>=2)break;
                ++go_loop_len;
                for(int end_id:connecting[u]){
                    if(end_id==i)continue;
                    int addition=2;
                    if(loop_to[u]==c_to_loop_id)addition=0;
                    if(loop_to[loop_to[u]]==c_to_loop_id)addition=1;
                    ans=max(ans,side_len[i]+side_len[end_id]+go_loop_len+addition);
                }
            }
        }
    }
    cout<<ans<<endl;
}
