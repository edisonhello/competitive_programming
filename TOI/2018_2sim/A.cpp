#include<bits/stdc++.h>
using namespace std;
#define ll long long

int w[5005][5005],n,go[20][1<<18];
bitset<(1<<18)> v[20];
long long rec[20][1<<18];

long long dfs(int now,int bs){
    if(v[now][bs])return rec[now][bs];
    if(bs==0)return w[now][1];
    v[now][bs]=1;
    rec[now][bs]=1ll<<60;
    for(int i=1;i<n;++i){
        if(bs&(1<<i)){
            long long rt=w[now][i+1]+dfs(i+1,bs^(1<<i));
            if(rt<rec[now][bs]){
                rec[now][bs]=rt;
                go[now][bs]=i+1;
            }
        }
    }
//    cout<<now<<" "<<bitset<6>(bs)<<" "<<rec[now][bs]<<endl;
    return rec[now][bs];
}

int main(){
//    freopen("in.txt","r",stdin);
    int m1,m2; cin>>n>>m1>>m2;
    while(m1--){
        int u,v,k; cin>>u>>v>>k;
        ++u, ++v;
        w[u+1][n+1]+=k;
        w[u+1][v]-=k;
        w[1][n+1]-=k;
        w[1][v]+=k;
    }
    while(m2--){
        int u,v,k; cin>>u>>v>>k;
        ++u, ++v;
        w[n+1][v+1]+=k;
        w[u][v+1]-=k;
        w[n+1][1]-=k;
        w[u][1]+=k;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            w[i][j]+=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
        }
    }
    cout<<dfs(1,(1<<n)-2)<<endl;
    int bs=(1<<n)-2,now=1;
    while(bs){
        cout<<now<<" ";
        int gt=go[now][bs];
        bs^=(1<<(gt-1));
        now=gt;
    }
    cout<<now<<" "<<1<<endl;
    for(int i=1;i<=n;++i){
//        w[i][i]=0;
        for(int j=1;j<=n;++j){
            cout<<setw(3)<<w[i][j]<<" ";
        }
        cout<<endl;
    }
}

