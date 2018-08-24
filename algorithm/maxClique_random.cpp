#include<bits/stdc++.h>
using namespace std;

bitset<88> G[88];
int pnt[88],ins[88];

int main(){
    srand(time(0));
    int n,m; cin>>n>>m; while(m--){
        int u,v; cin>>u>>v;
        G[u][v]=G[v][u]=1;
    }
    for(int i=0;i<n;++i)pnt[i]=i;
    int cnt=n*n,ans=0;
    while(cnt--){
        // for(int i=0;i<n;++i)swap(pnt[rand()%n],pnt[i]);
        random_shuffle(pnt,pnt+n);
        int size=0;
        for(int i=0;i<n;++i){
            bool ok=1;
            for(int j=0;j<size;++j){
                if(G[pnt[i]][ins[j]]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ins[size]=pnt[i];
                ++size;
            }
        }
        ans=max(ans,size);
    }
    cout<<ans<<endl;
}
