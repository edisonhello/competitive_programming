// UVa 315
int G[111][111],n,ans,t,itm[111],lw[111];

void dfs(int now,int p){
    itm[now]=lw[now]=++t;
    int ch=0; bool dea=0;
    for(int i=1;i<=n;++i){
        if(i==now || i==p || !G[now][i])continue;
        if(!itm[i]){
            dfs(i,now); ++ch;
            lw[now]=min(lw[now],lw[i]);
            if(lw[i]>=itm[now])++dea;
        }
        else lw[now]=min(lw[now],itm[i]);
    }
    if(lw[now]<=itm[now] && ((ch>=1 && p)||(!p && ch>1)) && dea)++ans;
}

int main(){
    while(scanf("%d ",&n),n){
        memset(G,0,sizeof(G)); ans=t=0;
        for(int i=1;i<=n;++i)itm[i]=lw[i]=0;
        string s;
        while(getline(cin,s) && s[0]!='0'){
            SS ss(s);
            int st,ed;ss>>st;
            while(ss>>ed)G[st][ed]=G[ed][st]=1;
        }
        dfs(1,0);
        pit(ans),el;
    }
}
