#include<bits/stdc++.h>
using namespace std;

string mp[2002];
int pre[2002][2002];

int main(){
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(mp[i-1][j-1]=='*');
    int ans=0;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
        if(i+k<=n+1){
            bool ok=1;
            if(pre[i+k-1][j]-pre[i+k-1][j-1]-pre[i-1][j]+pre[i-1][j-1])ok=0;
            if(ok)++ans;
        }
        if(k>1 && j+k<=m+1){
            bool ok=1;
            if(pre[i][j+k-1]-pre[i-1][j+k-1]-pre[i][j-1]+pre[i-1][j-1])ok=0;
            if(ok)++ans;
        }
    }
    cout<<ans<<endl;
}
