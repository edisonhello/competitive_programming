#include<iostream>
using namespace std;
#include<cstring>

int in[100005],djs[100005];
bool v[100005],fa[100005];

int F(int x){
    if(fa[x] || djs[x]==x)return djs[x];
    fa[x]=1;
    return djs[x]=F(djs[x]);
}

int main(){
    int ts;cin>>ts;while(ts--){
        int n,m;cin>>n>>m;

        memset(v,0,sizeof(v));
        memset(in,0,sizeof(in));
        memset(fa,0,sizeof(fa));
        for(int i=1;i<=n;++i)djs[i]=i;

        while(m--){
            int a,b;cin>>a>>b;
            djs[b]=a;
            in[b]++;
        }
        // cout<<"djs:";for(int i=1;i<=n;++i)cout<<djs[i]<<" ";cout<<endl;
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(!in[i]){
                ++cnt;
                v[i]=1;
            }
        }

        for(int i=1;i<=n;++i){
            int head=F(i);
            // cout<<"head "<<i<<" : "<<head<<endl;
            if(!v[head]){
                v[head]=1;
                ++cnt;
            }
        }
        cout<<cnt<<endl;
    }
}
