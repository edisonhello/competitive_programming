#include<iostream>
#include<cstring>
using namespace std;

int p[100005];
bool a[100005],isL[100005],v[100005];

int dfs(int now,int dep){
    if(v[now])return dep;
    if(a[now])return dep;
    v[now]=1;
    return dfs(p[now],dep+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        memset(isL,1,sizeof(isL));
        int n;cin>>n;
        for(int i=1;i< n;++i){cin>>p[i];isL[p[i]]=0;}
        for(int i=0;i< n;++i)cin>>a[i];
        int cnt=0;
        for(int i=1;i< n;++i){
            if(!isL[i])continue;
            cnt+=dfs(i,0);
        }
        if(cnt&1)cout<<"bGg\n";
        else cout<<"689\n";
    }
}
