#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,ll>> G[100005];
vector<vector<ll>> ds[100005];
bitset<100005> builded;
vector<int> building,cenG[100005];
ll *dfsd,tmpd[20][100005],dis[20][100005],dpa[100005];
int sz[100005],mxc[100005],cenpa[100005],cendep[100005],ippos[100005];

void dfs(int now,int pa){
    building.push_back(now);
    sz[now]=1;
    mxc[now]=0;
    for(auto i:G[now]){
        if(i.first==pa)continue;
        if(builded[i.first])continue;
        dfsd[i.first]=dfsd[now]+i.second;
        dfs(i.first,now);
        sz[now]+=sz[i.first];
        mxc[now]=max(mxc[now],sz[i.first]);
    }
}

pair<vector<int>,int> getcen(int now,int pa,int dep){
    dfsd=tmpd[dep];
    building.clear(); dfsd[now]=0;
    dfs(now,now);
    int cen=-1;
    for(int i:building){ if(max(mxc[i],sz[now]-sz[i])<=sz[now]/2){ cen=i; break; } }
    assert(cen!=-1);
    cenpa[cen]=pa;
    cendep[cen]=dep;
    building.clear(); dfsd[cen]=0;
    dfs(cen,cen);
    for(int i:building){ dis[dep][i]=dfsd[i]; }
    builded[cen]=1;
    vector<ll> alld;
    vector<int> allmem=building;
    for(auto i:G[cen]){ if(!builded[i.first]){ 
        auto chifo=getcen(i.first,cen,dep+1); 
        dpa[chifo.second]=tmpd[dep][chifo.second];
        ippos[chifo.second]=cenG[cen].size();
        cenG[cen].push_back(chifo.second);
        ds[cen].push_back(vector<ll>());
        for(int j:chifo.first){  ds[cen].back().push_back(tmpd[dep][j]); alld.push_back(tmpd[dep][j]); }
    } }
    alld.push_back(0);
    ds[cen].push_back(alld);
    return make_pair(allmem,cen);
}

int bfdfs(int now,int pa,ll d){
    if(d<0)return 0;
    // cout<<"bfdfs "<<now<<" "<<d<<endl;
    int rt=1;
    for(auto i:G[now]){
        if(i.first==pa)continue;
        rt+=bfdfs(i.first,now,d-i.second);
    }
    return rt;
}

int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<n;++i){
        int a,b,w; cin>>a>>b>>w;
        G[a].emplace_back(b,w);
        G[b].emplace_back(a,w);
    }
    getcen(1,0,1);
    for(int i=1;i<=n;++i)for(vector<ll> &v:ds[i])sort(v.begin(),v.end());
    /* for(int i=1;i<=n;++i)cout<<i<<" "<<cenpa[i]<<" "<<cendep[i]<<" "<<dpa[i]<<" "<<ippos[i]<<endl;
    for(int i=1;i<=n;++i){
        cout<<"[ ";
        for(auto v:ds[i]){
            cout<<"[ ";
            for(int i:v)cout<<i<<", ";
            cout<<"], ";
        }
        cout<<"]"<<endl;
    } */
    while(q--){
        int x; ll l; cin>>x>>l;
        int ans=0,ndep=cendep[x],xxx=x;
        // int aans=bfdfs(x,x,l);
        while(x && l>=0){
            // cout<<x<<" "<<ans<<" dis: "<<dis[ndep][xxx]<<endl;
            ans+=upper_bound(ds[x].back().begin(),ds[x].back().end(),l-dis[ndep][xxx])-ds[x].back().begin();
            // cout<<x<<" "<<ans<<" , dis: "<<dis[ndep-1][xxx]<<endl;
            if(cenpa[x]){
                ans-=upper_bound(ds[cenpa[x]][ippos[x]].begin(),ds[cenpa[x]][ippos[x]].end(),l-dis[ndep-1][xxx])-ds[cenpa[x]][ippos[x]].begin();
            }
            x=cenpa[x];
            --ndep;
        }
        cout<<ans<<endl;
        // if(ans!=aans)cout<<"error "<<aans<<endl;
    }
}
