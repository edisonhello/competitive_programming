#include<iostream>
#include<algorithm>
#define int long long
#define mid ((l+r)>>1)
using namespace std;

int n,m,k,x,s;
int a[200005],b[200005],c[200005],d[200005];


int takepois(int F,int S){
    return (n-c[S])*a[F];
}

int tryans(int F){
    int pos=upper_bound(d,d+k+1,s-b[F])-d-1;
    //cout<<"F="<<F<<" "<<s-b[F]<<" "<<d[pos]<<" "<<takepois(F,pos)<<endl;
    return takepois(F,pos);
}

int sol(){
    int bestans=(1ll<<62);
    for(int i=0;i<=m;++i){
        if(b[i]>s)continue;
        bestans=min(bestans,tryans(i));
    }
    cout<<bestans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k>>x>>s;
    for(int i=0;i<m;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    a[m]=x;b[m]=0;
    for(int i=1;i<=k;++i)cin>>c[i];
    for(int i=1;i<=k;++i)cin>>d[i];
    c[0]=0;d[0]=0;
    sol();
}
