#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define left mmeeooww
#define right RIGHT
#define lowbit(x) ((x)&-(x))

#ifdef WEAK
#include"../template/debug.cpp"
#else
#define PDE(...) ;
#endif

int to[20][100005];
ll x[100005],z[100005],bit[100005];
ll cost[20][100005],right[20][100005];

ll query(int x,ll rt=0){
    for(;x;x-=lowbit(x)){
        rt=max(rt,bit[x]);
    } return rt;
}
void add(int x,ll v){
    for(;x<100005;x+=lowbit(x)){
        bit[x]=max(bit[x],v);
    }
}


int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>z[i];
    }
    add(n,x[n]+z[n]);
    right[0][n]=x[n]+z[n];
    for(int i=n-1;i>=1;--i){
        add(i,x[i]+z[i]);
        auto it=upper_bound(x+i,x+1+n,x[i]+z[i]); --it;
        right[0][i]=query(it-x);
        add(i,right[0][i]);
        to[0][i]=it-x;
    }
    for(int i=1;i<n;++i){
        if(to[0][i]==i){
            to[0][i]=i+1;
            cost[0][i]=x[i+1]-right[0][i];
            right[0][i]=x[i+1];
        }
    }

    for(int i=1;i<=n;++i)PDE(i,to[0][i],right[0][i],cost[0][i]);

    for(int i=1;i<=19;++i){
        for(int j=1;j<=n;++j){
            to[i][j]=to[i-1][to[i-1][j]];
            cost[i][j]=cost[i-1][j]+cost[i-1][to[i-1][j]]+max(0ll,x[to[i-1][j]]-right[i-1][j]);
            right[i][j]=right[i-1][to[i-1][j]];
        }
    }

    for(int i=1;i<=n;++i)PDE(i,to[1][i],right[1][i],cost[1][i]);
    for(int i=1;i<=n;++i)PDE(i,to[2][i],right[2][i],cost[2][i]);

    int q; cin>>q; while(q--){
        int u,v; cin>>u>>v;
        ll ans=0;
        for(int i=19;i>=0;--i){
            if(to[i][u] && to[i][u]<=v){
                PDE("go",i);
                ans+=cost[i][u];
                u=to[i][u];
                PDE("newu",u);
            }
        }
        cout<<ans<<endl;
    }
}
