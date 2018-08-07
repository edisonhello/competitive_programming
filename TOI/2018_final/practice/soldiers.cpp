#include<bits/stdc++.h>
using namespace std;

int n,ans;
vector<int> G[104];
int dega[104];
bitset<104> chosed,cc;
unsigned long long start_time;

int match(){
    int ans=0;
    cc.reset();
    for(int i=1;i<=n;++i){
        if(!chosed[i] && !cc[i])for(int j:G[i]){
            if(!chosed[j] && !cc[j]){
                cc[i]=cc[j]=1;
                ++ans;
                break;
            }
        }
    }
    return ans;
}

void dfs(int now){
    if(now>n){ ans=min(ans,int(chosed.count())); return; }
    if(int(chosed.count())+match()>=ans)return;
    // if((double)(clock()-start_time)/CLOCKS_PER_SEC>9.99)return;
    if(chosed[dega[now]])dfs(now+1);
    else{
        {
            bitset<104> backup=chosed;
            for(int i:G[dega[now]]){
                chosed[i]=1;
            }
            dfs(now+1);
            chosed=backup;
        }
        {
            chosed[dega[now]]=1;
            dfs(now+1);
        }
    }
}

int main(){
    // start_time=clock();
    int m; while(cin>>m>>n,n){
        for(int i=1;i<=n;++i)G[i].clear();
        chosed.reset(); 

        while(m--){
            int u,v; cin>>u>>v; ++u, ++v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=n;++i){
            dega[i]=i;
        }
        sort(dega+1,dega+1+n);
        ans=INT_MAX;
        dfs(1);
        cout<<ans<<endl;
    }
}
