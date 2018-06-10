// = Codeforces 673E
#include<bits/stdc++.h>
using namespace std;
#define ld double

double t[200005],pt[200005],ti[200005],pti[200005],ptt[200005];
double dp[54][200005];

inline double cost(int i,int j){ // [i,j]
    return ptt[j]-ptt[i-1]-pt[i-1]*(pti[j]-pti[i-1]);
}

void go(int ly,int l,int r,int tl,int tr){
    if(l>r)return;
    int x=(l+r)>>1;
    int p=-1;
    double v=1e20;
    for(int i=tl;i<=min(tr,x);++i){
        double nv=dp[ly-1][i-1]+cost(i,x);
        if(nv<v){
            v=nv;
            p=i;
        }
    }
    dp[ly][x]=v;
    go(ly,l,x-1,tl,p);
    go(ly,x+1,r,p,tr);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>t[i];
    for(int i=1;i<=n;++i)pt[i]=pt[i-1]+t[i];
    for(int i=1;i<=n;++i)ti[i]=1.0/t[i];
    for(int i=1;i<=n;++i)pti[i]=pti[i-1]+ti[i];
    for(int i=1;i<=n;++i)ptt[i]=ptt[i-1]+ti[i]*pt[i];

    for(int i=1;i<=n;++i)dp[0][i]=1e20;
    for(int i=1;i<=k;++i)go(i,i,n,i,n);
    cout<<fixed<<setprecision(12)<<dp[k][n]<<endl;
}
