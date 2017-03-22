// UVa 12083
struct person{
    int h,g,m,s;
} p[505];
map<string,int> mu,sp;
vint G[505];
int mch[505];
bool v[505];

int gid(string &s,map<string,int> &mp){
    auto it=mp.find(s);
    if(it==mp.end()){
        mp[s]=mp.size();
        return mp.size();
    } return it->Y;
}

int dfs(int now){
    for(auto i:G[now]){
        if(!v[i]){
            v[i]=1;
            if(mch[i]==-1 || dfs(mch[i])){ // notice here! not dfs(i)
                mch[i]=now, mch[now]=i;
                return 1;
            }
        }
    }
    return 0;
}

int main(){ CIO;
    int ts;cin>>ts;while(ts--){
        int n,b=0,g=0,i,h,pr=0,tid,rid; string s,t,r; cin>>n;
        for(i=0;i<n;++i)G[i].clear();
        for(i=0;i<n;++i){
            cin>>h>>s>>t>>r;
            tid=gid(t,mu), rid=gid(r,sp);
            p[i]={h,s=="M"?0:1,tid,rid};
        }
        for(i=0;i<n;++i){
            PDE4(p[i].h,p[i].g,p[i].m,p[i].s);
            for(int j=i+1;j<n;++j){
                if(abs(p[i].h-p[j].h)>40)continue;
                if(p[i].g==p[j].g)continue;
                if(p[i].m!=p[j].m)continue;
                if(p[i].s==p[j].s)continue;
                G[i].pb(j), G[j].pb(i);
            }
        }
        MSM(mch);
        for(i=0;i<n;++i){
            if(mch[i]==-1){
                MS0(v); v[i]=1;
                if(dfs(i))++pr;
            }
        }
        cout<<n-pr<<endl;
    }
}
