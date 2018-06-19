#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<bitset>
using namespace std;
#define pb push_back
#define eb emplace_back
#define ll long long

struct pair_edge{
    int first,second,index;
    pair_edge(int z=0,int a=0,int q=0):first(z),second(a),index(q){}
};

vector<pair_edge> G[1000006];
// vector<ll> brenchs[1000006];

int djs[1000006];
int F(int x){ return x==djs[x]?x:djs[x]=F(djs[x]); }
void U(int x,int y){ djs[F(x)]=F(y); }

ll dp[1000006];
#define brenchs dp
ll ans[1000006];

void print_ans(const int n){
    // for(int i=1;i<=n;++i)for(ll z:dp[i])ans[F(i)]=max(ans[F(i)],z);
    // for(int i=1;i<=n;++i)if(dp[i].size()>1u)ans[F(i)]=max(ans[F(i)],dp[i][0]+dp[i][1]);
    ll a=0;
    for(int i=1;i<=n;++i)a+=ans[i];
    /* for(int i=1;i<=n;++i){
        if(!ans[i])continue;
        cout<<"ans["<<i<<"] = "<<ans[i]<<endl;
    } */
    printf("%lld\n",a);
}

void dfs_all_circle(const int n,const vector<pair_edge> *G,const bitset<1000006> &is_circle){
    bitset<1000006> vis,expire;
    for(int i=1;i<=n;++i){
        if(!is_circle[i])continue;
        if(vis[i])continue;
        // cout<<"circle index point: "<<i<<endl;
        vis[i]=1;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>> pq;
struct info{
    int ceid,now,d;
    info(int q=0,int z=0,int c=0):ceid(q),now(z),d(c){}
};
        vector<info> circle;
        circle.eb(-1,i,-1);
        while(1){
            if(circle.size()>1u && circle[0].now==circle.back().now)break;
            for(auto &p:G[circle.back().now]){
                if(!is_circle[p.first])continue;
                if(p.index==circle.back().ceid)continue;
                circle.back().d=p.second;
                circle.eb(p.index,p.first,-1);
                break;
            }
        }
        /* cout<<"circle: [ ";
        for(auto &c:circle)cout<<"("<<c.ceid<<" "<<c.now<<" "<<c.next<<" "<<c.d<<") ";
        cout<<"]\n"; */
        for(auto &c:circle)vis[c.now]=1;
        ll &nans=ans[F(i)],pathlen=circle[0].d,pqdelta=0;
        for(int i=1;i<circle.size()-1;++i){
            pq.emplace(pathlen+brenchs[circle[i].now],circle[i].now);
            pathlen+=circle[i].d;
        }
        pathlen-=circle[circle.size()-2].d;
        nans=max(nans,(pq.size()?pq.top().first:0ll)+brenchs[i]);
        // cout<<"after first run, nans: "<<nans<<endl;
        // cout<<"pathlen: "<<pathlen<<endl;
        for(int i=1,j=circle.size()-2;i<circle.size();++i){
            pathlen-=circle[i-1].d;
            pqdelta-=circle[i-1].d;
            pathlen+=circle[j].d;
            expire[circle[i-1].now]=1;
            ++j; if(j==int(circle.size()-1))j=0;
            // cout<<"running to start at "<<circle[i].now<<" , pathlen: "<<pathlen<<endl;
            pq.emplace(pathlen+brenchs[circle[j].now]-pqdelta,circle[j].now);
            while(pq.size() && pq.top().second==circle[i].now)pq.pop();
            // cout<<"pq top val is "<<pq.top().first<<" , delta: "<<pqdelta<<endl;
            nans=max(nans,(pq.size()?pq.top().first+pqdelta:0ll)+brenchs[circle[i].now]);
        }
        // cout<<"finish all run, nans: "<<nans<<endl;
    }

    print_ans(n);
}

/* int ansindex;
ll dfs(int now,int pa){
    // cout<<"in dfs "<<now<<" pa: "<<pa<<endl;
    vector<ll> dps(3,0);
    for(auto &p:G[now]){
        if(p.first==pa)continue;
        // cout<<"["<<p.first<<"]"<<p.second<<endl;
        dps[2]=dfs(p.first,now)+p.second;
        sort(dps.begin(),dps.end(),greater<ll>());
    }
    ans[ansindex]=max(ans[ansindex],dps[0]+dps[1]);
    // cout<<"dp of "<<now<<" : "<<dp[now][1]<<" "<<dp[now][2]<<endl;
    return dps[0];
} */
void dfs_to_brench(const int n,const vector<pair_edge> *G,const bitset<1000006> &is_circle){
    /* for(int i=1;i<=n;++i){
        cout<<i<<" is? "<<is_circle[i]<<endl;
    } */

    for(int i=1;i<=n;++i){
        if(!is_circle[i])continue;
        // ansindex=F(i);
        /* for(auto &p:G[i]){
            if(!is_circle[p.first]){
                brenchs[i].pb(p.second);
                // cout<<"brenchs add "<<dp[p.first][1]+p.second<<endl;
                sort(brenchs[i].begin(),brenchs[i].end(),greater<ll>());
                if(brenchs[i].size()>2u)brenchs[i].pop_back();
            }
        } */
        /* if(brenchs[i].size())ans[ansindex]=max(ans[ansindex],brenchs[i][0]);
        if(brenchs[i].size()>1u)ans[ansindex]=max(ans[ansindex],brenchs[i][0]+brenchs[i][1]); */
        // if(brenchs[i].empty())brenchs[i].pb(0);
        // cout<<"now ans: "<<ans[F(i)]<<endl;
        /* cout<<"brenchs of "<<i<<" : ";
        for(ll z:brenchs[i])cout<<z<<" ";
        cout<<endl; */
    }

    dfs_all_circle(n,G,is_circle);
}

void reduce_to_circle(const int n,const vector<pair_edge> *G){
    vector<int> deg(n+3,0);
    for(int i=1;i<=n;++i){
        deg[i]=int(G[i].size());
    }
    bitset<1000006> is_circle;
    for(int i=1;i<=n;++i)is_circle[i]=1;
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(deg[i]==1){
            q.push(i);
            is_circle[i]=0;
        }
    }
    while(q.size()){
        int now=q.front(); q.pop();
        for(auto &p:G[now]){
            if(!is_circle[p.first])continue;
            --deg[p.first];
            ans[F(now)]=max(ans[F(now)],dp[p.first]+p.second+dp[now]);
            dp[p.first]=max(dp[p.first],p.second+dp[now]);
            if(deg[p.first]==1){
                q.push(p.first);
                is_circle[p.first]=0;
            }
        }
    }
    dfs_to_brench(n,G,is_circle);
}

int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1,t,l;i<=n;++i){
        scanf("%d%d",&t,&l);
        G[i].eb(t,l,i); G[t].eb(i,l,i);
        U(i,t);
    }
    /* for(int i=1;i<=n;++i){
        cout<<"djs["<<i<<"] = "<<F(i)<<endl;
    } */ 
    reduce_to_circle(n,G);
}
// in virtual 47
// after 80
// after memory optimize AC
