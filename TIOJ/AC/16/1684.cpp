#include<bits/stdc++.h>
using namespace std;

stack<int> st;
int in[1006],low[1006],kick[1006],v[1006],bel[1006],bccc,timer;
vector<int> G[1006],bccmb[1006];
bitset<1006> hate[1006];

void dfs1(int now,int pa){
    in[now]=low[now]=++timer;
    st.push(now);
    for(int i:G[now]){
        if(i==pa)continue;
        if(in[i])low[now]=min(low[now],in[i]);
        else{
            dfs1(i,now);
            low[now]=min(low[now],low[i]);
            if(low[i]>=in[now]){
                ++bccc;
                while(0==0){
                    bccmb[bccc].push_back(st.top());
                    if(st.top()==i)break;
                    st.pop();
                }
                st.pop(); bccmb[bccc].push_back(now);
            }
        }
    }
}

bool dfs2(int now,int clr,int bcc){
    if(v[now]){
        if(v[now]==clr)return 1;
        return 0;
    }
    v[now]=clr;
    for(int i:G[now]){
        if(bel[i]!=bcc)continue;
        if(!dfs2(i,-clr,bcc))return 0;
    }
    return 1;
}

int main(){
    int n,m; while(cin>>n>>m){
        if(!n&&!m)break;
        bccc=timer=0;
        while(st.size())st.pop();
        for(int i=0;i<1006;++i)hate[i].reset(),G[i].clear(),bccmb[i].clear(),in[i]=low[i]=v[i]=bel[i]=0,kick[i]=1;
        while(m--){
            int u,v; cin>>u>>v;
            hate[u][v]=hate[v][u]=1;
        }
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(hate[i][j])continue;
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
        for(int i=1;i<=n;++i){
            if(in[i])continue;
            dfs1(i,0);
            if(st.size()){
                ++bccc;
                while(st.size()){
                    bccmb[bccc].push_back(st.top());
                    st.pop();
                }
            }
        }
#ifdef WEAK
        for(int i=1;i<=bccc;++i){
            cout<<"bccc["<<i<<"]:"; 
            for(int j:bccmb[i])cout<<" "<<j; cout<<endl;
        }
#endif
        for(int i=1;i<=bccc;++i){
            if(bccmb[i].empty())continue;
            for(int j:bccmb[i])bel[j]=i,v[j]=0;
            if(!dfs2(bccmb[i][0],1,i)){
                for(int j:bccmb[i])kick[j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)if(kick[i])++ans;
        cout<<ans<<endl;
    }
}
