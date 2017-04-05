#include<bits/stdc++.h>
using namespace std;

int a,b;
int clr[3008];
vector<int> G[3008];
bool go[3008];
vector<int> win;
int dfs1(int now,int stp,int pG);
int dfs2(int now,int stp,int pG);

int Q;
int dfs2(int now,int stp,int pG){
    pG|=clr[now];
    cout<<"dfs2 "<<now<<" "<<stp<<" "<<pG<<endl;
    if(go[now] && now==stp)return pG;
    if(go[now])return (pG?Q=now:0),0;
    go[now]=1;
    for(int i=0;i<G[now].size();++i){
        int rt=dfs1(G[now][i],stp,pG);
        if(!rt){
            if(Q)win.push_back(now);
            if(Q==now)Q=0;
            go[now]=0;
            return 0;
        }
    }
    if(Q)win.push_back(now);
    if(Q==now)Q=0;
    go[now]=0;
    return 1;
}
int dfs1(int now,int stp,int pG){
    pG|=clr[now];
    cout<<"dfs1 "<<now<<" "<<stp<<" "<<pG<<endl;
    if(go[now] && now==stp)return pG;
    if(go[now])return 0;
    go[now]=1;
    for(int i=0;i<G[now].size();++i){
        int rt=dfs2(G[now][i],stp,pG);
        if(rt){
            if(Q)win.push_back(now);
            if(Q==now)Q=0;
            go[now]=0;
            return 1;
        }
    }
    if(Q)win.push_back(now);
    if(Q==now)Q=0;
    go[now]=1;
    return 0;
}

int main(){
    cin>>a>>b;
    for(int i=1;i<=a+b;++i){
        cin>>clr[i];int k;cin>>k;
        while(k--){
            int t;cin>>t;
            G[i].push_back(t);
        }
    }
    for(int i=1;i<=a+b;++i){
        memset(go,0,sizeof(go));
        if(i<=a){
            if(dfs1(i,i,0))win.push_back(i);
        }
        else{
            if(dfs2(i,i,0))win.push_back(i);
        }
    }
    sort(win.begin(),win.end());
    cout<<win.size()<<endl;
    for(int i=0;i<win.size();++i)cout<<win[i]<<endl;
}
