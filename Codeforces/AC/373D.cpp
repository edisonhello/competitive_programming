#include<bits/stdc++.h>
using namespace std;

string mp[44];
int pre[44][44];
int preans[44][44][44][44],n,m;

int get(int x1,int x2,int y1,int y2){
    return pre[x2][y2]-(x1?pre[x1-1][y2]:0)-(y1?pre[x2][y1-1]:0)+(x1&&y1?pre[x1-1][y1-1]:0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin>>n>>m>>q;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=0;i<n;++i)for(char &c:mp[i])c-='0';
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            pre[i][j]=(i?pre[i-1][j]:0)+(j?pre[i][j-1]:0)-(i&&j?pre[i-1][j-1]:0)+mp[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            for(int k=0;k<m;++k){
                int cnt=0;
                for(int l=k;l<m;++l){
                    get(i,j,l,l)?cnt=0:++cnt;
                    preans[i][j][k][l]=(l?preans[i][j][k][l-1]:0)+cnt;
                }
            }
        }
    }
    while(q--){
        int a,b,c,d; cin>>a>>c>>b>>d; --a,--b,--c,--d;
        int ans=0;
        for(int i=a;i<=b;++i){
            for(int j=i;j<=b;++j){
                ans+=preans[i][j][c][d];
            }
        }
        cout<<ans<<endl;
    }
}
