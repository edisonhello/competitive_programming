// UVa 796
inline int meow(){
    string s;cin>>s;
    s=s.substr(1,s.length()-2);
    SS ss(s); int rt; ss>>rt; return rt;
}
vector<vint> G;
vector<pii> ans;

int timer;
vint low,num;

void dfs(int now,int pa){
    low[now]=num[now]=++timer;
    for(auto i:G[now]){
        if(i==pa)continue;
        if(!num[i])dfs(i,now);
        low[now]=min(low[now],low[i]);
        if(low[i]>num[now])ans.push_back({now,i});
    }
}

int main(){
    int n;while(cin>>n){
        G.clear(); ans.clear();
        low.clear(), num.clear(); timer=0;

        G.resize(n); low.resize(n), num.resize(n);
        for(int i=0;i<n;++i){
            int stp;cin>>stp;
            int conCnt=meow();
            while(conCnt--){
                int ed;cin>>ed;
                G[stp].pb(ed);
            }
        }
        for(int i=0;i<n;++i)if(!num[i])dfs(i,i);
        for(auto &i:ans)if(i.X>i.Y)swap(i.X,i.Y);
        sort(ans.begin(),ans.end());
        printf("%d critical links\n",ans.size());
        for(auto i:ans)printf("%d - %d\n",i.X,i.Y);el;
    }
}
