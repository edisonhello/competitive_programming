int match[104];
vector<int> G[104];
bitset<104> v;

// edge are only one side
int meow(){
    int ans=0;
    function<int(int)> dfs=[&](int now)->int{
        for(int i:G[now]){
            if(v[i])continue;
            v[i]=1;
            if(match[i]==-1 || dfs(match[i])){
                match[i]=now;
                return 1;
            }
        }
        return 0;
    };
    for(int i=1;i<=n;++i){
        v.reset();
        if(dfs(i))++ans;
    }
    return ans;
}

// a full graph
int meow(){
    int ans=0;
    function<int(int)> dfs=[&](int now)->int{
        for(int i:G[now]){
            if(v[i])continue;
            v[i]=1;
            if(match[i]==-1 || dfs(match[i])){
                match[i]=now;
                match[now]=i;
                return 1;
            }
        }
        return 0;
    };
    for(int i=1;i<=n;++i){
        if(match[i]!=-1)continue;
        v.reset();
        if(dfs(i))++ans;
    }
    return ans;
}
