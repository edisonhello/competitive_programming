// UVa 10054
vector<pii> G[55],ans;
bool u[1111];
int deg[55];

void meow(int now){
    for(pii i:G[now]){
        if(u[i.Y])continue;
        u[i.Y]=1;
        meow(i.X);
        ans.push_back({i.X,now});
    }
}

int main(){
    int ts,ks=0;cin>>ts;while(ts--){
        int n;cin>>n;
        MS(deg,0), MS(u,0);
        for(int i=1;i<=50;++i)G[i].clear(); ans.clear();
        for(int i=0;i<n;++i){
            int u,v;cin>>u>>v;
            deg[u]++, deg[v]++;
            G[u].push_back({v,i});
            G[v].push_back({u,i});
        }
        int st=-1;
        for(int i=1;i<=50;++i){
            if(deg[i]&1){
                printf("Case #%d\nsome beads may be lost\n",++ks);
                goto nexT;
            }
            if(deg[i])st=i;
        }
        meow(st);
        printf("Case #%d\n",++ks);
        for(pii i:ans)printf("%d %d\n",i.X,i.Y);
        nexT:;
        if(ts)el;
    }
}
