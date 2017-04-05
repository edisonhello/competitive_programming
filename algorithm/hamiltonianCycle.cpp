// UVa 775 (cheat)
vint G[333];
bool v[333];
int rd[333],n;

bool meow(int idx){
    PDE2(rd[idx-1],idx);FLH;
    if(idx==n){
        for(int i:G[rd[idx-1]]){
            if(i==rd[0]){
                for(int j=0;j<n;++j)pit(rd[j]),spc;
                pit(rd[0]),el;
                return 1;
            }
        }
        return 0;
    }
    for(int i:G[rd[idx-1]]){
        if(v[i])continue;
        v[i]=1; rd[idx]=i;
        if(meow(idx+1))return 1;
        v[i]=0;
    }
    return 0;
}

int main(){
    while(cin>>n){
        for(int i=0;i<=n;++i)v[i]=0,G[i].clear();
        {string s;getline(cin,s);while(getline(cin,s)){
            if(s=="%")break; SS ss(s);
            int u,v; ss>>u>>v;
            G[u].pb(v), G[v].pb(u);
        }}
        rd[0]=1; v[1]=1;
        if(!meow(1))cout<<"N"<<endl;
    }
}
