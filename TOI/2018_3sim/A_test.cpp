#include<bits/stdc++.h>
using namespace std;
#define int int_fast32_t
#define X first
#define Y second

bitset<222> v,vis[222];
int dp[222][111],d[222],to[222],n,s,t,dis[222][222],tr[222][222],edge[222][222];

#define mat vector<vector<int_fast32_t>>

vector<pair<int,int>> G[222];

void dij(int t){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,t});
    memset(d,0x3f,sizeof(d)); d[t]=0;
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        int now=pq.top().second; pq.pop();
        v[now]=1;
        for(auto e:G[now]){
            if(d[e.first]>d[now]+e.second){
                to[e.first]=now;
                d[e.first]=d[now]+e.second;
                pq.push({d[e.first],e.first});
            }
        }
    }
}

void open(mat &m){
    m.resize(n+3);
    for(int i=0;i<n+3;++i){
        m[i].resize(n+3);
        for(int j=0;j<n+3;++j)m[i][j]=0;
    }
}

mat operator*(const mat &a,const mat &b){
    mat rt; open(rt);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)rt[i][j]=-1e16;
    for(int i=1;i<=n;++i)rt[i][i]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                rt[i][j]=max(rt[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    return rt;
}

mat pw(mat b,int up){
    mat a; open(a);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a[i][j]=-1e16;
    for(int i=1;i<=n;++i)a[i][i]=0;
    while(up){
        if(up&1)a=a*b;
        b=b*b; up>>=1;
    } return a;
}

int32_t main(){
    int m,k; cin>>n>>m>>s>>t>>k;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i)dis[i][i]=0;
    while(m--){
        int u,v,t; cin>>u>>v>>t;
        G[u].emplace_back(v,t);
        G[v].emplace_back(u,t);
        dis[u][v]=dis[v][u]=t;
        edge[u][v]=edge[v][u]=t;
    }
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    // dij(s,t);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            // if(edge[i][j]==0){tr[i][j]=0; continue;}
            for(int k=1;k<=n;++k){
                if(k==i)continue;
                tr[i][j]=max(tr[i][j],edge[i][k]+dis[k][j]-dis[i][j]);
            }
            // tr[i][j]=dis[j][t]+edge[i][j]-dis[i][t];
        }
    }

    mat base,trans;
    open(base); open(trans);
    for(int j=1;j<=n;++j){
        // dij(j);
        for(int i=1;i<=n;++i){
            base[i][j]=dis[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(edge[i][j]==0)continue;
            trans[i][j]=edge
//            trans[i][j]=tr[i][j];
        }
    }

    cout<<"base: "<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<base[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"trans: "<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }

    trans=pw(trans,k);
    base=base*trans;

    cout<<"base: "<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<base[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"trans: "<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<base[s][t]<<endl;


}
