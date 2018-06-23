// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define exp expexpexpexp
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

#define up(x,y) (x=max(x,y))

vector<int> qy[235005],wk,cG[235005];
vector<pair<int,int>> G[235005];
int sz[235005],mxch[235005],ctpa[235005],dep[235005],dis[235005],last[235005],dtc[16][235005],ictd[235005],allval[235005],myval[235005],tpval[235005];
bitset<235005> inct;

void dfs1(int now,int pa){
    // cout<<"dfs1: "<<now<<" pa "<<pa<<endl;
    wk.pb(now);
    for(pair<int,int> p:G[now]){
        // cout<<"G information: "<<p.first<<" "<<p.second<<endl;
        if(inct[p.first] || p.first==pa)continue;
        dis[p.first]=dis[now]+p.second;
        dfs1(p.first,now);
        sz[now]+=sz[p.first];
        mxch[now]=max(mxch[now],sz[p.first]);
    }
    ++sz[now];
    // cout<<"dfs1: now: "<<now<<" , sz: "<<sz[now]<<" , mxch: "<<mxch[now]<<endl;
}

void dfs1_5(int now,int pa,int dep,int nowd){
    dtc[dep][now]=nowd;
    // cout<<"dtc "<<dep<<" "<<now<<" = "<<nowd<<endl;
    for(pair<int,int> p:G[now]){
        if(p.first==pa)continue;
        if(inct[p.first])continue;
        dfs1_5(p.first,now,dep,nowd+p.second);
    }
}

int cd(int now,int pa,int dep){
    // cout<<"cen tree information: "<<now<<" pa "<<pa<<endl;
    dfs1(now,now);
    int cen=-1;
    for(int i:wk)if(max(mxch[i],int(wk.size())-sz[i])<=int(wk.size())/2)cen=i;
    // cout<<"find new cen: "<<cen<<endl;
    dfs1_5(cen,cen,dep,0);
    ictd[cen]=dep;
    ctpa[cen]=pa;
    inct[cen]=1;
    for(int i:wk){
        sz[i]=mxch[i]=0;
    }
    wk.clear();
    for(pair<int,int> p:G[cen]){
        if(inct[p.first])continue;
        dis[p.first]=p.second;
        int chcen=cd(p.first,cen,dep+1);
        cG[cen].pb(chcen);
    }
    return cen;
}

void dfs2(int now,int pa){
    for(pair<int,int> p:G[now]){
        if(p.first==pa)continue;
        dep[p.first]=dep[now]+p.second;
        dfs2(p.first,now);
        sz[now]+=sz[p.first];
    }
    sz[now]+=qy[now].size();
}

set<int> _add_modify_point;
void clearct(){
    for(int i:_add_modify_point){
        allval[i]=-999999;
        tpval[i]=-999999;
        myval[i]=-999999;
    }
    _add_modify_point.clear();
    // cout<<"cleared"<<endl;
}
void add(int x,int v){
    // cout<<"add "<<v<<" in "<<x<<endl;
    int ox=x,prv=x;
    up(myval[x],v);
    // cout<<"insert "<<v<<" in myval of "<<x<<endl;
    x=ctpa[x];
    while(x){
        up(tpval[prv],v+dtc[ictd[x]][ox]);
        up(allval[x],v+dtc[ictd[x]][ox]);
        // cout<<"insert "<<v+dtc[ictd[x]][ox]<<" in allval of "<<x<<endl;
        // cout<<"insert "<<v+dtc[ictd[x]][ox]<<" in tpval of "<<prv<<endl;
        _add_modify_point.insert(x);
        _add_modify_point.insert(prv);
        // v+=dtp[x];
        prv=x;
        x=ctpa[x];
    }
}
int query(int x,int v=-999999){
    int prv=x,ox=x;
    v=max(v,allval[x]);
    v=max(v,myval[x]);
    x=ctpa[x];
    while(x){
        // cout<<x<<" "<<prv<<" "<<v<<endl;
        for(int cch:cG[x]){
            if(cch==prv)continue;
            v=max(v,dtc[ictd[x]][ox]+tpval[cch]);
            // cout<<x<<" "<<prv<<" "<<cch<<" "<<v<<endl;
        }
        v=max(v,dtc[ictd[x]][ox]+myval[x]);
        // cout<<v<<endl;
        prv=x;
        x=ctpa[x];
    }
    // cout<<"query "<<ox<<" get "<<v<<endl;
    return v;
}

int ans;
vector<pair<int,int>> *dfs3(int now,int pa,bool clean){
    // cout<<"dfs3 "<<now<<endl;
    sort(G[now].begin(),G[now].end(),[&](const pair<int,int> &a,const pair<int,int> &b){ 
        if(b.first==pa)return true;
        if(a.first==pa)return false;
        return sz[a.first]<sz[b.first]; });
    vector<vector<pair<int,int>>*> rec;
    for(pair<int,int> p:G[now]){
        if(p.first==pa){
            __is_end:;
            vector<pair<int,int>>* rt;
            if(rec.size()){
                rt=rec.back();
                rec.pop_back();
            }
            else rt=new vector<pair<int,int>>();
            for(auto *v:rec){
                for(auto &p:*v){
                    int Q=query(p.second);
                    ans=max(ans,Q+dep[p.first]-dep[now]*2);
                    // cout<<"update ans with "<<Q+dep[p.first]-dep[now]*2<<endl;
                }
                for(auto &p:*v){
                    add(p.second,dep[p.first]);
                }
            }
            for(auto &sec:qy[now]){
                int Q=query(sec);
                ans=max(ans,Q-dep[now]);
                // cout<<"update ans with "<<Q+dep[p.first]-dep[now]*2<<endl;
            }
            for(auto &sec:qy[now]){
                add(sec,dep[now]);
            }
            for(auto *v:rec){
                if(v->size()>rt->size())swap(rt,v);
                for(auto &p:*v)rt->pb(p);
                delete v;
            }
            for(auto &sec:qy[now]){
                rt->eb(now,sec);
            }
            return rt;
        }
        else{
            clearct();
            vector<pair<int,int>> *rt=dfs3(p.first,now,p!=G[now].back());
            rec.pb(rt);
            if(p==G[now].back())goto __is_end;
        }
    }
    // cout<<"You shouldn't be here"<<endl;
    assert(0);
}

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)last[i]=i;
    int N=n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        int nu=++N,nv=++N;
        G[last[u]].eb(nu,0); G[last[v]].eb(nv,0);
        G[nu].eb(last[u],0); G[nv].eb(last[v],0);
        G[nu].eb(nv,1); G[nv].eb(nu,1);
        // cout<<"add edge "<<last[u]<<" to "<<nu<<" d 0 "<<endl;
        // cout<<"add edge "<<last[v]<<" to "<<nv<<" d 0 "<<endl;
        // cout<<"add edge "<<nu<<" to "<<nv<<" d 1 "<<endl;
        last[u]=nu, last[v]=nv;
    }
    int root=cd(1,0,1);
    while(m--){
        int x,y; cin>>x>>y;
        qy[x].pb(y);
    }
    // for(int i=1;i<=n;++i)val[i]=new multiset<int>[cG[i].size()+1];
    dep[1]=1;
    dfs2(1,1);
    dfs3(1,1,0);
    cout<<ans<<endl;
}
