#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll tut[505][505];

int main(){
    srand(time(0));
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        tut[u][v]=-(tut[v][u]=(rand()*1ll*rand()+rand()));
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            while(tut[j][i]){
                ll mns=tut[i][i]/tut[j][i];
                for(int k=1;k<=n;++k){
                    tut[i][k]=((tut[i][k]-mns*tut[j][k]%mod)%mod+mod)%mod;
                    swap(tut[j][k],tut[i][k]);
                }
            }
        }
        if(tut[i][i])++cnt;
    }

    cout<<(cnt>>1)<<endl;
}
