#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

int to[200005],vis[200005],ind[200005],trash[200005],pw[200005];

int main(){
    pw[0]=1;
    for(int i=1;i<200005;++i)pw[i]=pw[i-1]*2%mod;
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>to[i];
        ++ind[to[i]];
    }
    queue<int> ed;
    for(int i=1;i<=n;++i)if(ind[i]==0)ed.push(i);
    int ans=1;
    while(ed.size()){
        int now=ed.front(); ed.pop();
        ans=ans*2%mod;
        --ind[to[now]];
        if(ind[to[now]]==0)ed.push(to[now]);
        trash[now]=1;
    }
    for(int i=1;i<=n;++i){
        if(trash[i])continue;
        int cnt=1;
        int j=to[i];
        trash[i]=trash[j]=1;
        while(j!=i){
            ++cnt;
            j=to[j];
            trash[j]=1;
        }
        ans=1ll*ans*(pw[cnt]-2)%mod;
    }
    cout<<ans<<endl;
}
