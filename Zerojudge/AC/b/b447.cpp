#include<bits/stdc++.h>
using namespace std;
#define ll long long

int u[10000007]={0,1};
ll pre[10000007],phi[10000007];

ll solve2(int n,int m){
    ll rt=0;
    for(int k=1;k<=min(n,m);){
        int nex=min(n/(n/k),m/(m/k));
        rt+=(n/k)*1ll*(m/k)*(pre[nex]-pre[k-1]);
        cout<<"add "<<n/k<<" "<<m/k<<" ["<<k<<","<<nex<<"] -> "<<(n/k)*1ll*(m/k)*(pre[nex]-pre[k-1])<<endl;
        k=nex+1;
    }
    return rt;
}

ll solve(int n,int m){
    ll rt=0;
    for(int k=1;k<=min(n,m);){
        int nex=min(n/(n/k),m/(m/k));
        nex=min(nex,10000000);
        rt+=(n/k)*1ll*(m/k)*(pre[nex]-pre[k-1]);
        k=nex+1;
    }
    return rt;
    /* ll rt=0;
    for(int g=1;g<=min(n,m);++g){
        cout<<"go g: "<<g<<endl;
        rt+=g*solve2(n/g,m/g);
    }
    return rt; */
}



int main(){
    /* for(int i=1;i<=10000000;++i){
        for(int j=i*2;j<=10000000;j+=i){
            u[j]-=u[i];
        }
        pre[i]=pre[i-1]+u[i];
    } */
    for(int i=1;i<=10000000;++i)phi[i]=i;
    for(int i=1;i<=10000000;++i){
        for(int j=i*2;j<=10000000;j+=i){
            phi[j]-=phi[i];
        }
        pre[i]=pre[i-1]+phi[i];
    }

    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        // int n=10000000,m=10000000;
        cout<<solve(n,m)<<'\n';
    }
}
