#include<bits/stdc++.h>
using namespace std;

int n,m;
int h[505][505];

int get(int l,int r){
    int rt=0;
    for(int i=1;i<=n;++i){
        if(i+rt-1>n)break;
        int L=1,R=m+1;
        while(R>L){
            int m=(L+R)>>1;
            if(h[i][m]<l)L=m+1;
            else R=m;
        }
        if(L==m+1)continue;
        int j=L;
        L=1,R=min(n-i+1,m-j+1);
        while(R>L){
            int m=(L+R+1)>>1;
            if(h[i+m-1][j+m-1]<=r)L=m;
            else R=m-1;
        }
        if(h[i+L-1][j+L-1]<=r)rt=max(rt,L);
    }
    return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>n>>m,n){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j)cin>>h[i][j];
            h[i][m+1]=1000000007;
        }
        int q,lb,ub; cin>>q; 
        for(int i=0;i<q;++i){
            cin>>lb>>ub;
            cout<<get(lb,ub)<<endl;
        }
        cout<<"-\n";
    }
}
