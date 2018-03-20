#include<bits/stdc++.h>
using namespace std;

int n,val[100005],pa[100005];
vector<int> G[100005];
vector<pair<int,int>> acts;
deque<pair<int,int>> chain_info[100005];

int sz[100005],maxson[100005],maxson_id[100005];
void dfs1(int now,int p){
    sz[now]=1;
    pa[now]=p;
    for(int i:G[now]){
        if(i==p)continue;
        dfs1(i,now);
        sz[now]+=sz[i];
        if(sz[i]>maxson[now]){
            maxson[now]=sz[i];
            maxson_id[now]=i;
        }
    }
}

int chain_count=1;
int chain_number[100005],chain_pos[100005],chaintop[100005];
void dfs(int now,int pa,int _chain_number,int _chain_pos){
    // cout<<"dfs "<<now<<" "<<_chain_number<<" "<<_chain_pos<<endl;
    chain_number[now]=_chain_number;
    chain_pos[now]=_chain_pos;
    for(int i:G[now]){
        if(i==pa)continue;
        if(i==maxson_id[now]){
            dfs(i,now,_chain_number,_chain_pos+1);
        }
        else{
            chaintop[++chain_count]=i;
            dfs(i,now,chain_count,1);
        }
    }
}

void go(int now,int val,vector<pair<int,int>> &rec){
    // cout<<"in go "<<now<<" "<<val<<endl;
    if(!now)return;
    int pop_size=chain_pos[now];
    int atchain=chain_number[now];
    vector<pair<int,int>> tmp_v;
    while(chain_info[atchain].size() && chain_info[atchain].front().second<=pop_size){
        tmp_v.push_back(chain_info[atchain].front());
        pop_size-=chain_info[atchain].front().second;
        chain_info[atchain].pop_front();
    }
    if(pop_size){
        auto tmp=chain_info[atchain].front();
        chain_info[atchain].pop_front();
        tmp.second-=pop_size;
        tmp_v.emplace_back(tmp.first,pop_size);
        chain_info[atchain].push_front(tmp);
        pop_size=0;
    }
    chain_info[atchain].emplace_front(val,chain_pos[now]);
    reverse(tmp_v.begin(),tmp_v.end());
    for(auto &i:tmp_v)rec.push_back(i);
    go(pa[chaintop[atchain]],val,rec);
}


long long bit[100005];

#define lb(x) ((x)&-(x))
void add(int x,int v){
    for(;x<100005;x+=lb(x))bit[x]+=v;
}
long long query(int x,long long v=0){
    for(;x;x-=lb(x))v+=bit[x];
    return v;
}

long long count_inverse(vector<pair<int,int>> &rec){
    // cout<<"rec: "; for(auto pi:rec)cout<<"("<<pi.first<<","<<pi.second<<")"; cout<<endl;
    long long rt=0,sum=0;
    for(auto p:rec){
        rt+=query(p.first-1)*p.second;
        add(p.first,p.second);
        sum+=p.second;
    }
    for(auto p:rec)add(p.first,-p.second);
    return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector<int> num;
    for(int i=1;i<=n;++i)cin>>val[i],num.push_back(val[i]);
    sort(num.begin(),num.end());
    for(int i=1;i<=n;++i)val[i]=lower_bound(num.begin(),num.end(),val[i])-num.begin()+1;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        acts.emplace_back(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    chaintop[1]=1;
    dfs(1,1,1,1);
    chain_info[1].emplace_back(val[1],1);
    for(auto ac:acts){
        vector<pair<int,int>> trace;
        // cout<<"go "<<ac.first<<" "<<ac.second<<endl;
        // cout<<"follow chain 1 "; for(auto i:chain_info[1])cout<<"("<<i.first<<","<<i.second<<")"; cout<<endl;
        go(ac.first,val[ac.second],trace);
        chain_info[chain_number[ac.second]].emplace_back(val[ac.second],1);
        cout<<count_inverse(trace)<<'\n';
    }
}
// first submit AC
