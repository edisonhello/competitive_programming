#include<bits/stdc++.h>
using namespace std;

int a,b;
int clr[3008];
vector<int> G[3008];
bool go[3008];
vector<int> win;

int dfs(int now,int stp,int passG){
    passG|=clr[now];
    // cout<<"dfs "<<now<<" "<<stp<<" "<<passG<<endl;
    if(go[now] && now!=stp)return -1;
    if(go[now])return passG;
    go[now]=1;
    int can=0;
    for(int i=0;i<G[now].size();++i){
        int rt=dfs(G[now][i],stp,passG);
        if(rt==-1){
            if(now>a)return -1;
        }
        if(now<=a){
            can|=rt;
            if(can){
                go[now]=0;
                return can;
            }
        }
        else{
            can&=rt;
            if(!can && !passG){
                go[now]=0;
                return 0;
            }
        }
    }
    go[now]=0;
    return can;
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
        if(dfs(i,i,0))win.push_back(i);
    }
    sort(win.begin(),win.end());
    cout<<win.size()<<endl;
    for(int i=0;i<win.size();++i)cout<<win[i]<<endl;
}
