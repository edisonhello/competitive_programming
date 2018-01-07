#include<bits/stdc++.h>
using namespace std;

bitset<10002> u;
int a[10002][10002],d[10002];
int main(){
    int n,m; cin>>n>>m;
    memset(a,0x3f,sizeof(a));
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        a[u][v]=a[v][u]=c;
    }
    memset(d,0x3f,sizeof(d)); d[0]=0;
    int ans=0;
    for(int _=0;_<n;++_){
        int near=0x3f3f3f3f,neari;
        for(int i=0;i<n;++i)if(!u[i] && d[i]<near)near=d[i],neari=i;
        u[neari]=1;
        ans+=near;
        // cout<<"near: "<<near<<" , neari: "<<neari<<endl;
        for(int i=0;i<n;++i)if(!u[i] && d[i]>+a[neari][i])d[i]=a[neari][i];
    }
    cout<<ans<<endl;
}
